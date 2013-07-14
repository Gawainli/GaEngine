#include "common.h"
#include "RenderEngine.h"

GaEngineNs::RenderEngine* GaEngineNs::RenderEngine::pInstance = NULL;


GaEngineNs::RenderEngine::RenderEngine()
	:window(NULL)
{

}


GaEngineNs::RenderEngine::~RenderEngine()
{
}


ECODE GaEngineNs::RenderEngine::InitWithWindow( int width, int heigh, bool isFull, char* title )
{
	/* Initialize the library */
	if (!glfwInit())
		return ECODE::UNEXCEPT_ERR;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, ENGINE_GL_MAJOR_VER);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, ENGINE_GL_MINOR_VER);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow( width, heigh, title, NULL, NULL );

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental=GL_TRUE;
	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		printf("Error: %s\n", glewGetErrorString(err));
		return ECODE::UNEXCEPT_ERR;
	}

	if ( !GLEW_VERSION_3_3 )
	{
		return ECODE::INCORRECT_DEVICE_VERSION;
	}

	return ECODE::NOERR;
}

ECODE GaEngineNs::RenderEngine::Destory()
{
	glfwTerminate();
	return ECODE::NOERR;
}

ECODE GaEngineNs::RenderEngine::Loop()
{
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	return ECODE::NOERR;
}

GaEngineNs::RenderEngine& GaEngineNs::RenderEngine::getInstance()
{
	if ( NULL == pInstance )
	{
		pInstance = new RenderEngine;
	}
	return *pInstance;
}


