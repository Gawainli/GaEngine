#ifndef RenderObjMgr_h__
#define RenderObjMgr_h__

#include "common.h"
#include "EngineDef.h"
#include "RenderObject.h"

#define RENDER_OBJ_PUCKET_SIZE 65537
typedef hash_map< string, RenderObject*> RenderObjMap;
ENGINE_NS_BEGIN

class RenderObjMgr
{
public:
	RenderObjMgr();
	virtual ~RenderObjMgr();
	static RenderObjMgr& getInstance()
	{
		if ( NULL == pIntance )
		{
			pIntance = new RenderObjMgr;
		}
		return *pIntance;
	}

public:
	void AddRenderObj( RenderObject& obj );

	RenderObject* GetRenderObj( const std::string& name );
	

public:

private:
	RenderObjMap objs;


private:
	static RenderObjMgr* pIntance;
};

ENGINE_NS_END

#endif // RenderObjMgr_h__
