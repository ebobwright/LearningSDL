#ifndef _ENTITYSYSTEM_
#define _ENTITYSYSTEM_ 
#pragma once
/*******************************************************
*File:		EntitySystem.h
*Author:	E. Bob Wright
*Date:		11/10/2010
*Notes:		
*******************************************************/
class ENTITYSYSTEM_API EntitySystem {
public:	
	static EntitySystem* GetInstance();
	Entity* CreateEntity();	
	Entity* GetEntity(int id);
    void KillEntity(int id);

	void RegisterSystem(BaseSystem* newSystem, int componentFamilyId);
	void InitializeSystems();
	void UpdateSystems();
	void KillSystems();

	template<typename T> void AddComponent(Entity* e, T* comp)
	{
		_componentStores[T::familyId].insert(std::pair<Entity*, Component*>(e, comp));	
	};

	template<typename T> T* GetComponent(Entity *e)
	{
      std::map<Entity*, Component*> &store = _componentStores[T::familyId];
      return (T*)store[e];
	};

	template<typename T> void RemoveComponent(Entity* e)
	{
		std::map<Entity*, Component*>::iterator toKill = _componentStores[T::familyId].find(e);
		_componentStores[T::familyId].erase(toKill);  
	}

	template<typename T> void GetEntities (std::set<Entity*> &result)
	{
		std::map<Entity*, Component*> m = _componentStores[T::familyId];
		std::map<Entity*, Component*>::const_iterator it = m.begin();
		std::map<Entity*, Component*>::const_iterator end = m.end();
		for( ; it != end; it++)
			result.insert(it->first);
	}

protected:
	EntitySystem(void);

	int _nextID;	
	static EntitySystem* _instance;

	std::map<int, Entity*> _entities;
	std::map<int, std::map<Entity*, Component*> > _componentStores;

	std::vector<std::pair<int, BaseSystem*>> _systems;
};
#endif //_ENTITYSYSTEM_