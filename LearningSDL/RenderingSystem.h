#ifndef _RENDERINGSYSTEM_
#define _RENDERINGSYSTEM_ 
#pragma once
 
/*******************************************************
*File:		RenderingSystem.h
*Author:	E. Bob Wright
*Date:		12/22/2010
*Notes:		
*******************************************************/
class RenderingSystem : public BaseSystem
{
protected:
	SDL_Surface* _displaySurface;
	EntitySystem* _entitySystem;

	Position* _camera;

public:	
	void Initialize();
	void Update(std::set<Entity*> renderables);
	void Kill();	
};

#endif
