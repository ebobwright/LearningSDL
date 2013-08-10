#include "..\\EBSys\\EBSys.h"

#include <glm/glm.hpp>
#include "Position.h"
#include "Renderable.h"
#include "RenderingSystem.h"

void RenderingSystem::Initialize()
{
	_entitySystem = EntitySystem::GetInstance();

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{		
        //return false;
    }
 
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);
 
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);
 
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);
 
	if((_displaySurface = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) 
	{
        //return false;
    }
 
    glClearColor(0, 0, 0, 0);
 
    glViewport(0, 0, 1280, 720);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 
    glOrtho(0, 1280, 720, 0, 1, -1);
 
    glMatrixMode(GL_MODELVIEW);
 
    glEnable(GL_TEXTURE_2D);
 
    glLoadIdentity(); 
}

void RenderingSystem::Update()
{
	std::set<Entity*> renderables;
	_entitySystem->GetEntities<Renderable>(renderables);	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// Clear The Screen And The Depth Buffer
	glLoadIdentity();
	
	//CAMERA
	//glTranslatef(0 - m_Camera->x, 0 - m_Camera->y, 0 - m_Camera->z);	
	glRotatef(0, 0, 0, 1);

	std::set<Entity*>::const_iterator it = renderables.begin();
	std::set<Entity*>::const_iterator end = renderables.end();
	for( ; it != end; it++)
	{		
		Position* tempPosition = (*it)->getAs<Position>();
		Renderable* tempRenderable = (*it)->getAs<Renderable>();

		glBegin(GL_QUADS);
			glColor3f(1, 0, 0); glVertex3f(tempPosition->PositionVector.x, tempPosition->PositionVector.y, tempPosition->PositionVector.z);
			glColor3f(1, 1, 0); glVertex3f(tempPosition->PositionVector.x + 100, tempPosition->PositionVector.y, tempPosition->PositionVector.z);
			glColor3f(1, 0, 1); glVertex3f(tempPosition->PositionVector.x + 100, tempPosition->PositionVector.y + 100, tempPosition->PositionVector.z);
			glColor3f(1, 1, 1); glVertex3f(tempPosition->PositionVector.x, tempPosition->PositionVector.y + 100, tempPosition->PositionVector.z);
		glEnd();		
	}
		 
    SDL_GL_SwapBuffers();
}

void RenderingSystem::Kill()
{	
	SDL_Quit();
}