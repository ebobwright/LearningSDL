#ifndef _RENDERINGSYSTEM_
#define _RENDERINGSYSTEM_ 
#pragma once
 
#include <SDL.h>
#include "SDL_OpenGL.h" 

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

public:
	void Initialize();
	void Update();
	void Kill();
};

#endif
