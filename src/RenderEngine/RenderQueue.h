#ifndef RenderQueue_h__
#define RenderQueue_h__

#include "common.h"
#include "EngineDef.h"
#include "RenderObject.h"


ENGINE_NS_BEGIN

class RenderQueue
{
public:
	RenderQueue();
	virtual ~RenderQueue();

	void RenderAllObjs();
	void AddRenderObj( RenderObject& obj );

public://render obj operation
	void RemoveRenderObj( const char* strName );
	void RemoveRenderObj( unsigned long id );
	void RemoveAllObjs();
protected:
private:
	std::vector<RenderObject*>  renderObjs;
};


ENGINE_NS_END

#endif // RenderQueue_h__
