#ifndef _COMPONENT_
#define _COMPONENT_ 
#pragma once
/*******************************************************
*File:		Component.h
*Author:	E. Bob Wright
*Date:		12/16/2010
*Notes:		
*******************************************************/
class ENTITYSYSTEM_API Component
{
public:
	static const int familyId = 0;
	Component(void);
	~Component(void);
};

#endif