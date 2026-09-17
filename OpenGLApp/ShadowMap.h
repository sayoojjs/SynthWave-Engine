#pragma once
#include <stdio.h>
#include <GL\glew.h>
class ShadowMap
{
public:
	ShadowMap();



	~ShadowMap();
	bool Init(unsigned int width, unsigned int height);
	void Write();
	void Read(GLenum textureUnit);
	GLuint GetShadowWidth() { return shadowWidth; }
	GLuint GetShadowHeight() { return shadowHeight; 
	}
protected:
	GLuint FBO, shadowMap;
	GLuint shadowWidth, shadowHeight;;


};

