#ifndef RenderObject_h__
#define RenderObject_h__

#include "common.h"
#include "EngineDef.h"


ENGINE_NS_BEGIN

class RenderObject
{
public:
	RenderObject();
	virtual ~RenderObject();
	void Render();

protected:
private:
};

ENGINE_NS_END
#endif // RenderObject_h__
