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
	objs.insert( make_pair( obj.GetName(), &obj ) );
}

RenderObject* GaEngineNs::RenderObjMgr::GetRenderObj( const std::string& name )
{
	RenderObjMap::iterator it = objs.find(name);

	if ( it != objs.end() )
	{
		return it->second;
	}

	return NULL;
}

