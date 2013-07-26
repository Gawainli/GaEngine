#include "CgManager.h"

GaEngineNs::CgManager* GaEngineNs::CgManager::pInstance = NULL;

GaEngineNs::CgManager::CgManager()
{

}

GaEngineNs::CgManager::~CgManager()
{

}

GaEngineNs::CgManager& GaEngineNs::CgManager::getInstance()
{
	if ( NULL == pInstance )
	{
		pInstance = new CgManager;
	}

	return *pInstance;
}

bool GaEngineNs::CgManager::InitCgGL()
{
	cgSetErrorHandler( &CgErrorHandler, NULL );

	cgContext = cgCreateContext();

	if ( NULL == cgContext )
	{
		return false;
	}

	cgGLRegisterStates( cgContext );
	cgGLSetManageTextureParameters( cgContext , CG_TRUE );
	isInitSucceed = true;
	return true;
}

void GaEngineNs::CgManager::CgErrorHandler( CGcontext context, CGerror error, void* appdata )
{
	if ( error != CG_NO_ERROR )
	{
		std::stringstream ss;
		const char* pStr = cgGetErrorString( error );

		std::string strError = ( pStr == NULL )?"":pStr;
		ss<<"Cg Error: "<<strError<<std::endl;

		std::string strListing;

		if ( error == CG_COMPILER_ERROR )
		{
			pStr = cgGetLastErrorString( &error );
			strListing = ( pStr == NULL )?"":pStr;

			ss<<strListing<<std::endl;
		}

		std::cerr<<ss;
	}
}