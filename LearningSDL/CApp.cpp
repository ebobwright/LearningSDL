#include "..\\EBSys\\EBSys.h"
#include "RenderingSystem.h"
#include "CApp.h"

#pragma region Constructor

CApp::CApp(void)
{
}

#pragma endregion

bool CApp::OnInit() 
{
	this->_entitySystem = EntitySystem::GetInstance();

	//Register Entities
	this->_entitySystem->RegisterSystem(new RenderingSystem()); //Always Register Rendering System Last
	
	try
	{
		this->_entitySystem->InitializeSystems();   
	}
	catch(...)
	{
		return false;
	}

	return true;
}
 
void CApp::OnEvent(SDL_Event* Event) 
{
	if(Event->type == SDL_QUIT) 
	{
        _running = false;
    }
}

void CApp::OnLoop() 
{
	this->_entitySystem->UpdateSystems();
}

void CApp::OnCleanup() 
{
	this->_entitySystem->KillSystems();
}

#pragma region main and message pump

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