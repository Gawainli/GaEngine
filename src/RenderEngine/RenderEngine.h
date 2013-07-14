#ifndef RenderEngine_h__
#define RenderEngine_h__

#include "common.h"
#include "EngineDef.h"

ENGINE_NS_BEGIN
class RenderEngine
{
public:
	RenderEngine();
	virtual ~RenderEngine();
	static RenderEngine& getInstance();
public:
	virtual ECODE InitWithWindow( int width, int heigh, bool isFull, char* title );
	virtual ECODE Loop();
	virtual ECODE Destory();

protected:
	
private:
	static RenderEngine* pInstance;
	GLFWwindow* window;
};
ENGINE_NS_END
#endif // RenderEngine_h__
