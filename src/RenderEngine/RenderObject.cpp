#include "RenderObject.h"


GaEngineNs::RenderObject::RenderObject()
{

}

GaEngineNs::RenderObject::RenderObject( const std::string& name )
{
	this->name = name;
	hash = CommonMath::BKDRHash(name);
	hashCheck = CommonMath::APHash(name);
}

GaEngineNs::RenderObject::~RenderObject()
{

}

std::string GaEngineNs::RenderObject::GetName() const
{
	return name;
}

unsigned int GaEngineNs::RenderObject::GetHashCheck() const
{
	return hashCheck;
}

unsigned int GaEngineNs::RenderObject::GetHash() const
{
	return hash;
}
