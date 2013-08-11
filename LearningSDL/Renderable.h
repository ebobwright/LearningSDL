#ifndef _RENDERABLE_
#define _RENDERABLE_ 
#pragma once
/*******************************************************
*File:		Renderable.h
*Author:	E. Bob Wright
*Date:		
*Notes:		
*******************************************************/
class Renderable : public Component
{
public:
	static const int familyId = 2;

	SimpleRenderable* Appearance;
};

#endif