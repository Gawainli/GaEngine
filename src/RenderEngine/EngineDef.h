#ifndef EngineDef_h__
#define EngineDef_h__


#define ENGINE_GL_MAJOR_VER 3
#define ENGINE_GL_MINOR_VER 3

namespace GaEngineNs{};
#define ENGINE_NS_BEGIN namespace GaEngineNs {
#define ENGINE_NS_END }


enum class ECODE
{
	NOERR,
	INCORRECT_DEVICE_VERSION,
	UNEXCEPT_ERR
};

using namespace GaEngineNs;

#endif // EngineDef_h__

