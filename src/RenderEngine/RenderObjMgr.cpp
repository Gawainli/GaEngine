#include "RenderObjMgr.h"


GaEngineNs::RenderObjMgr* GaEngineNs::RenderObjMgr::pIntance = NULL;

GaEngineNs::RenderObjMgr::RenderObjMgr()
{
	memset( objPucket, 0, sizeof(RenderObject*)*RENDER_OBJ_PUCKET_SIZE );
}

GaEngineNs::RenderObjMgr::~RenderObjMgr()
{

}

void GaEngineNs::RenderObjMgr::AddRenderObj( RenderObject& obj )
{
	unsigned int index = Str2Idx(obj.GetName());
	while( NULL != objPucket[index])
	{
		index++;
	}
	objPucket[index] = &obj;
}

RenderObject& GaEngineNs::RenderObjMgr::GetRenderObj( const std::string& name )
{
	unsigned int index = Str2Idx(name);
	
	while ( objPucket[index]->GetHashCheck() != Str2Check(name) )
	{
		index++;
	}
	return *objPucket[index];
}
