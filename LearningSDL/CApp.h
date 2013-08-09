#ifndef _CAPP_H_
#define _CAPP_H_
 
#include <SDL.h>
#include "SDL_OpenGL.h" 
//#include <gl/gl.h>
//#include <gl/glu.h>
 
class CApp 
{ 
protected:
	bool _running;
	SDL_Surface* _displaySurface;

public:
	CApp();
	int OnExecute(); 
	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnLoop(); 
	void OnRender(); 
	void OnCleanup();
};
 
#endif