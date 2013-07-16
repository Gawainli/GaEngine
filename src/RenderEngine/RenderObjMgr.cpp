#include "RenderObjMgr.h"


GaEngineNs::RenderObjMgr* GaEngineNs::RenderObjMgr::pIntance = NULL;

GaEngineNs::RenderObjMgr::RenderObjMgr()
{
}

GaEngineNs::RenderObjMgr::~RenderObjMgr()
{

}

void GaEngineNs::RenderObjMgr::AddRenderObj( RenderObject& obj )
{
	RenderObject* p = &obj;
	objs.Insert( obj.GetName(), p );
}

RenderObject& GaEngineNs::RenderObjMgr::GetRenderObj( int idx )
{
	assert(objs[idx]);
	return *objs[idx];
}

int GaEngineNs::RenderObjMgr::GetRenderObjIdx( const std::string& name )
{
	return objs.GetIdx( name );
}

