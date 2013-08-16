#ifndef _ENTITY_
#define _ENTITY_ 
#pragma once
/*******************************************************
*File:		Entity.h
*Author:	E. Bob Wright
*Date:		11/10/2010
*Notes:		
*******************************************************/
class ENTITYSYSTEM_API Entity
{
public:
	Entity(int NewEntityID);

	int EntityID; //Unique Identifier for each Entity
	std::string EntityName; //Friendly way to reference an Entity

	template<typename T> T* getAs()
	{
		return EntitySystem::GetInstance()->GetComponent<T>(this);
	}
};
#endif //_ENTITY_