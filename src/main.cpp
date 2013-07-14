#include "RenderEngine/EngineHead.h"
using namespace GaEngineNs;

int main()
{
	ECODE result = RenderEngine::getInstance().InitWithWindow( 1280, 720, false, "Render" );
	if ( result != ECODE::NOERR )
	{
		return -1;
	}
	CgManager::getInstance().InitCgGL();

	RenderEngine::getInstance().Loop();
	RenderEngine::getInstance().Destory();

	return 0;
}
