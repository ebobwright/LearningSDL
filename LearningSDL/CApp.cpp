#include "..\\EBSys\\EBSys.h"
#include "RenderingSystem.h"
#include "CApp.h"

#pragma region Setup Methods

void CApp::RegisterEventHandlers()
{
	this->RegisterMessageHandler(SDL_QUIT, &CApp::Quit);
}

void CApp::RegisterSystems()
{
	_entitySystem->RegisterSystem(new RenderingSystem()); //Always Register Rendering System Last
}

#pragma endregion

#pragma region Event Handlers

void CApp::Quit(void)
{
	_running = false;
}

#pragma endregion

#pragma region Message Handler Registration

CApp::tyMessageHandler CApp::GetMessageHandler(Uint8 message)
{	
	CApp::tyMessageIterator it = m_MsgHandlers.find(message);
	if(it == m_MsgHandlers.end())
		return NULL;
	return ((it->second));
}

CApp::tyMessageHandler CApp::RegisterMessageHandler(Uint8 message, CApp::tyMessageHandler handler)
{
	CApp::tyMessageHandler m = NULL;
	CApp::tyMessageIterator it = m_MsgHandlers.find(message);
	
	if(it != m_MsgHandlers.end())
		m = it->second;
	
	m_MsgHandlers.insert(std::pair<long,tyMessageHandler>(message, handler));

	return m;
}

#pragma endregion

#pragma region main and message pump

bool CApp::OnInit() 
{
	_entitySystem = EntitySystem::GetInstance();

	RegisterEventHandlers();
	RegisterSystems();
	
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
 
void CApp::OnEvent(SDL_Event* Event) 
{	
	tyMessageHandler mh = GetMessageHandler(Event->type);
	if(mh != NULL)
	{
		(this->*(mh))();			
	}
}

void CApp::OnLoop() 
{
	_entitySystem->UpdateSystems();
}

void CApp::OnCleanup() 
{
	_entitySystem->KillSystems();
}

int CApp::OnExecute() 
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
    CApp theApp; 
    return theApp.OnExecute();
}

#pragma endregion