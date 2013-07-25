#include "RenderObject.h"


GaEngineNs::RenderObject::RenderObject()
{

}

GaEngineNs::RenderObject::RenderObject( const std::string& name )
{
	this->name = name;
}

GaEngineNs::RenderObject::~RenderObject()
{
}

std::string GaEngineNs::RenderObject::GetName() const
{
	return name;
}

