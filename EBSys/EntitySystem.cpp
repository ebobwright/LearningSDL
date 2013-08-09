/*******************************************************
*File:		EntitySystem.cpp
*Author:	E. Bob Wright
*Date:		11/10/2010
*Notes:		
*******************************************************/
#include "EBSys.h"

/*******************************************************
Constructor (and Destructor)
*******************************************************/
EntitySystem::EntitySystem(void)
{		
	_nextID = 0;
	return;
}

EntitySystem* EntitySystem::_instance = NULL;
EntitySystem* EntitySystem::GetInstance()
{
	if(_instance == NULL)
		_instance = new EntitySystem();

	return _instance;
}

Entity* EntitySystem::CreateEntity()
{
	Entity* e = new Entity(_nextID++);
	_entities.insert(std::pair<int, Entity*>(e->EntityID, e));
	return e;
}

Entity* EntitySystem::GetEntity(int id) 
{
	return _entities[id];
}

void EntitySystem::KillEntity(int id) 
{
      std::map<int, Entity*>::iterator toKill = _entities.find(id);
	  _entities.erase(toKill);      
 }

void EntitySystem::RegisterSystem(BaseSystem* newSystem)
{
	this->_systems.push_back(newSystem);
}

void EntitySystem::InitializeSystems()
{
	for(int i = 0; i < (int)_systems.size(); i++)
	{
		BaseSystem* currentSystem = _systems[i];
		currentSystem->Initialize();		
	}
}

void EntitySystem::UpdateSystems()
{
	for(int i = 0; i < (int)_systems.size(); i++)
	{
		BaseSystem* currentSystem = _systems[i];
		currentSystem->Update();		
	}
}

void EntitySystem::KillSystems()
{
	for(int i = 0; i < (int)_systems.size(); i++)
	{
		BaseSystem* currentSystem = _systems[i];
		currentSystem->Kill();		
	}
}