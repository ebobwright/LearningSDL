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

void EntitySystem::RegisterSystem(BaseSystem* newSystem, int componentFamilyId)
{
	this->_systems.push_back(std::pair<int, BaseSystem*>(componentFamilyId, newSystem));
}

void EntitySystem::InitializeSystems()
{
	for(int i = 0; i < (int)_systems.size(); i++)
	{
		std::pair<int, BaseSystem*> currentSystem = _systems[i];
		currentSystem.second->Initialize();		
	}
}

void EntitySystem::UpdateSystems()
{
	for(int i = 0; i < (int)_systems.size(); i++)
	{
		std::set<Entity*> result;
		std::pair<int, BaseSystem*> currentSystem = _systems[i];				
		std::map<Entity*, Component*> m = _componentStores[currentSystem.first];		
		std::map<Entity*, Component*>::const_iterator it = m.begin();
		std::map<Entity*, Component*>::const_iterator end = m.end();
		for( ; it != end; it++)
			result.insert(it->first);
		
		currentSystem.second->Update(result);		
	}
}

void EntitySystem::KillSystems()
{
	for(int i = 0; i < (int)_systems.size(); i++)
	{
		std::pair<int, BaseSystem*> currentSystem = _systems[i];
		currentSystem.second->Kill();		
	}
}