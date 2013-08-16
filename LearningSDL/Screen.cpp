#include "consolidated.h"

void Screen::Initialize()
{

}

bool Screen::InitGL()
{
	glShadeModel(GL_SMOOTH);						// Enables Smooth Shading		
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);					// Black Background
	glClearDepth(1.0f);							// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);							// The Type Of Depth Test To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Really Nice Perspective Calculations

	glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); 

	glInitNames();

	return true;
}

GLvoid Screen::ReSizeGLScene(GLsizei width, GLsizei height)				// Resize And Initialize The GL Window
{
	if (height==0)								// Prevent A Divide By Zero By
	{
		height=1;							// Making Height Equal One
	}

	glViewport(0, 0, width, height);					// Reset The Current Viewport
			
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();							// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	//gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glOrtho (0 - (width / 2), width / 2, height / 2, 0 - (height / 2), -100, 100);

	glMatrixMode(GL_MODELVIEW);						// Select The Modelview Matrix
	glLoadIdentity();							// Reset The Modelview Matrix
}

void Screen::Draw( glm::vec3 position, int w, int h, float scaleX, float scaleY, float rotZ, GLuint source, bool drawGuide, GLuint tag )
{		
	glPushMatrix();

	if(tag != 0)
	{
		glPushName(tag);
	}

	glBindTexture(GL_TEXTURE_2D, source);

	glTranslatef( position.x, position.y, position.z );
	glRotatef(rotZ, 0, 0 , 1);
	glScalef(scaleX, scaleY, 1.0);

    glBegin( GL_QUADS );
            
        //Draw square
       glTexCoord2f(0.0, 0.0); glVertex3f( 0, 0, 0 );
       glTexCoord2f(1.0, 0.0); glVertex3f( w, 0, 0 );
       glTexCoord2f(1.0, 1.0); glVertex3f( w, h, 0 );
       glTexCoord2f(0.0, 1.0); glVertex3f( 0, h, 0 );
	    
    //End quad   
    glEnd();

	if(drawGuide)
	{
		//glTranslatef( 0.5, 0.5, 0 );
		//glLineWidth (3);
		//
		//glBegin( GL_LINES );

		//	glVertex3f( 0, 0, -0.1 );
		//	glVertex3f( w, 0, -0.1 );

		//	glVertex3f( w, 0, -0.1 );
		//	glVertex3f( w, h, -0.1 );

		//	glVertex3f( w, h, -0.1 );
		//	glVertex3f( 0, h, -0.1 );

		//	glVertex3f( 0, h, -0.1 );
		//	glVertex3f( 0, 0, -0.1 );

		//	glVertex3f( 0, 0, -0.1 );
		//	glVertex3f( w, h, -0.1 );

		//glEnd();
	}

	if(tag != 0)
	{
		glPopName();
	}
	
	glPopMatrix();
}