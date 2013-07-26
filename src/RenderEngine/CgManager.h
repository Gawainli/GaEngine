#ifndef CgManager_h__
#define CgManager_h__

#include "common.h"
#include "EngineDef.h"

ENGINE_NS_BEGIN

class CgManager
{
public:
	CgManager();
	virtual ~CgManager();
	static CgManager& getInstance();

public:
	bool InitCgGL();

public:
	//static functions
	static void CgErrorHandler( CGcontext context, CGerror error, void* appdata );

private:
	CGcontext cgContext;
	bool isInitSucceed;
private:
	static CgManager* pInstance;
};



ENGINE_NS_END


#endif // CgManager_h__


