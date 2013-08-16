#pragma once

class Screen
{
public:
	Screen(void);
	~Screen(void);

	void Initialize();
	GLvoid ReSizeGLScene(GLsizei width, GLsizei height);

	void Draw( glm::vec3 position, int w, int h, float scaleX, float scaleY, float rotZ, GLuint source, bool drawGuide, GLuint tag );

	void Flip();

	void Dispose();

	bool InitGL();	

	GLuint selectBuf[512];
};
