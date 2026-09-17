#include "ShadowMap.h"


ShadowMap::ShadowMap()
{
	FBO = 0;
	shadowMap = 0;
}


bool ShadowMap::init(GLuint width, GLuint height)
{

	shadowWidth = width;
	shadowHeight = height;

	glGenFramebuffers(1, &FBO); //creating frame buffer 

	glGenTextures(1, &shadowMap); //passing texture ID to shadowMap
	glBindTexture(GL_TEXTURE_2D, shadowMap); //bind the texuture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowWidth, shadowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL); //creating depth texture)
return false;
}
