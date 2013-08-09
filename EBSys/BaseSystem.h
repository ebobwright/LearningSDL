#ifndef _BASESYSTEM_
#define _BASESYSTEM_ 
#pragma once
/*******************************************************
*File:		BaseSystem.h
*Author:	E. Bob Wright
*Date:		12/22/2010
*Notes:		
*******************************************************/
class ENTITYSYSTEM_API BaseSystem
{
public:	
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Kill() = 0;
};
#endif