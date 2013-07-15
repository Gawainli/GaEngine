#ifndef RenderObject_h__
#define RenderObject_h__

#include "common.h"
#include "EngineDef.h"


ENGINE_NS_BEGIN

class RenderObject
{
public:
	RenderObject();
	RenderObject( const std::string& name );
	virtual ~RenderObject();
	void Render();

public:
	void SetData();
	void SetMtl();


public:
	std::string GetName() const;
protected:
private:
	std::string name;
};

ENGINE_NS_END
#endif // RenderObject_h__
