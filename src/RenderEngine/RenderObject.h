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
	unsigned int GetHash() const;
	unsigned int GetHashCheck() const;
	std::string GetName() const;
protected:
private:
	unsigned int hashmain;
	unsigned int hashsub;
	std::string name;
};

ENGINE_NS_END
#endif // RenderObject_h__
