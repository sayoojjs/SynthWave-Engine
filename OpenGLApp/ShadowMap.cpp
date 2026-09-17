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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowWidth, shadowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr); //creating depth texture)
    
	//Texture filter
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindFramebuffer(GL_FRAMEBUFFER, FBO); //bind the framebuffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap, 0); //attach the depth texture to the framebuffer

	glDrawBuffer(GL_NONE); //no color buffer is drawn to
	glReadBuffer(GL_NONE); //no color buffer is read from

	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);	

	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		printf("Frame buffer error: %i\n", status);
			return true;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0); //unbind the framebuffer

	return true;

}

void ShadowMap::Write()
{
	glBindFramebuffer(GL_FRAMEBUFFER, FBO);

}

void ShadowMap::Read(GLenum textureUnit)
{
	glActiveTexture(textureUnit);
	glBindTexture(GL_TEXTURE_2D, shadowMap);

}


ShadowMap::~ShadowMap()
{
	if (FBO)
	{
		glDeleteFramebuffers(1, &FBO);
	}

	if(shadowMap)
	{
		glDeleteTextures(1, &shadowMap);
	}
}