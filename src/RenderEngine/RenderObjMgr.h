#ifndef RenderObjMgr_h__
#define RenderObjMgr_h__

#include "common.h"
#include "EngineDef.h"
#include "RenderObject.h"

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
	
	RenderObject& GetRenderObj( const std::string& name );


public:
	inline static unsigned int Str2Idx( const std::string& name )
	{
		return CommonMath::BKDRHash( name ) % RENDER_OBJ_PUCKET_SIZE;
	}

	inline static unsigned int Str2Check( const std::string& name )
	{
		return CommonMath::APHash( name );
	}
private:
	RenderObject* objPucket[RENDER_OBJ_PUCKET_SIZE];


private:
	static RenderObjMgr* pIntance;
};

ENGINE_NS_END

#endif // RenderObjMgr_h__
