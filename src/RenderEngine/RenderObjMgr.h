#ifndef RenderObjMgr_h__
#define RenderObjMgr_h__

#include "common.h"
#include "EngineDef.h"
#include "RenderObject.h"
#include "Common/GaContainer.h"

#define RENDER_OBJ_PUCKET_SIZE 65537

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

	int GetRenderObjIdx( const std::string& name );
	
	RenderObject& GetRenderObj( int idx );


public:

private:
	GaHashTable<RenderObject*> objs;


private:
	static RenderObjMgr* pIntance;
};

ENGINE_NS_END

#endif // RenderObjMgr_h__
