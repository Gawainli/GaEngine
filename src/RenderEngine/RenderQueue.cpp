#include "RenderQueue.h"

GaEngineNs::RenderQueue::RenderQueue()
{

}

GaEngineNs::RenderQueue::~RenderQueue()
{

}

void GaEngineNs::RenderQueue::AddRenderObj( RenderObject& obj )
{
	renderObjs.push_back( &obj );
}

void GaEngineNs::RenderQueue::RenderAllObjs()
{
	for ( int i = 0; i < renderObjs.size(); i++ )
	{
		if ( renderObjs[i] )
		{
			renderObjs[i]->Render();
		}
	}
}
