#include "consolidated.h"

void UserControlSystem::Initialize()
{
	_entitySystem = EntitySystem::GetInstance();
}

void UserControlSystem::Update(std::set<Entity*> controllable)
{	
	std::set<Entity*>::const_iterator it = controllable.begin();
	std::set<Entity*>::const_iterator end = controllable.end();
	for( ; it != end; it++)	
	{	
		if( (*it)->EntityName == "camera" )
		{
			Position* cameraPosition = (*it)->getAs<Position>();

			if(_keyboard->GetKey(SDLK_UP))
				cameraPosition->PositionVector.y -= 0.1;
			if(_keyboard->GetKey(SDLK_DOWN))
				cameraPosition->PositionVector.y += 0.1;
			if(_keyboard->GetKey(SDLK_LEFT))
				cameraPosition->PositionVector.x -= 0.1;
			if(_keyboard->GetKey(SDLK_RIGHT))
				cameraPosition->PositionVector.x += 0.1;
		}
	}
}

void UserControlSystem::Kill()
{
}

void UserControlSystem::SetKeyboard(Keyboard* keyboard)
{
	_keyboard = keyboard;
}

void UserControlSystem::SetMouse(Mouse* mouse)
{
	_mouse = mouse;
}