#include "consolidated.h"

#pragma region Setup Methods

void Game::RegisterEventHandlers()
{
	this->RegisterMessageHandler(SDL_QUIT, &Game::Quit);
	this->RegisterMessageHandler(SDL_KEYDOWN, &Game::KeyDown);
	this->RegisterMessageHandler(SDL_KEYUP, &Game::KeyUp);
}

void Game::RegisterSystems()
{	
	UserControlSystem* userControlSystem = new UserControlSystem();
	userControlSystem->SetKeyboard(&_keyboard);
	userControlSystem->SetMouse(&_mouse);
	_entitySystem->RegisterSystem(userControlSystem, UserControllable::familyId);

	RenderingSystem* renderingSystem = new RenderingSystem();	
	_entitySystem->RegisterSystem(renderingSystem, Renderable::familyId); //Always Register Rendering System Last
}

void Game::TestCode()
{
	/***** TESTING ******/	
	Entity* testEntity = _entitySystem->CreateEntity();
	testEntity->EntityName = "Test Entity";

	Position* testPosition = new Position();
	testPosition->PositionVector = glm::vec3(50,50,0);
	_entitySystem->AddComponent(testEntity, testPosition);

	Renderable* testRenderable = new Renderable();
	_entitySystem->AddComponent(testEntity, testRenderable);
}

#pragma endregion

#pragma region Event Handlers

void Game::Quit(SDL_Event* Event)
{	
	_running = false;
}

void Game::KeyDown(SDL_Event* Event)
{
	_keyboard.SetKey(Event->key.keysym.sym, true);	
}

void Game::KeyUp(SDL_Event* Event)
{
	_keyboard.SetKey(Event->key.keysym.sym, false);
}

#pragma endregion

#pragma region Message Handler Registration

Game::tyMessageHandler Game::GetMessageHandler(Uint8 message)
{	
	Game::tyMessageIterator it = m_MsgHandlers.find(message);
	if(it == m_MsgHandlers.end())
		return NULL;
	return ((it->second));
}

Game::tyMessageHandler Game::RegisterMessageHandler(Uint8 message, Game::tyMessageHandler handler)
{
	Game::tyMessageHandler m = NULL;
	Game::tyMessageIterator it = m_MsgHandlers.find(message);
	
	if(it != m_MsgHandlers.end())
		m = it->second;
	
	m_MsgHandlers.insert(std::pair<long,tyMessageHandler>(message, handler));

	return m;
}

#pragma endregion

#pragma region main and message pump

bool Game::OnInit() 
{
	_entitySystem = EntitySystem::GetInstance();		

	RegisterEventHandlers();
	RegisterSystems();

	TestCode();
	
	try
	{
		_entitySystem->InitializeSystems();   
	}
	catch(...)
	{
		return false;
	}

	return true;
}
 
void Game::OnEvent(SDL_Event* Event) 
{	
	tyMessageHandler mh = GetMessageHandler(Event->type);
	if(mh != NULL)
	{
		(this->*(mh))(Event);			
	}
}

void Game::OnLoop() 
{
	_entitySystem->UpdateSystems();
}

void Game::OnCleanup() 
{
	_entitySystem->KillSystems();
}

int Game::OnExecute() 
{
    if(OnInit() == false) 
	{
        return -1;
    }
 
    SDL_Event Event;
 
    while(_running) 
	{
        while(SDL_PollEvent(&Event)) 
		{
            OnEvent(&Event);
			
        }
 
        OnLoop();        
    }
 
    OnCleanup();
 
    return 0;
}
 
int main(int argc, char* argv[]) 
{
    Game theApp;
    return theApp.OnExecute();
}

#pragma endregion