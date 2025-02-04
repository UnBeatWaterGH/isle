#include "viewmanager.h"

#include "decomp.h"

DECOMP_SIZE_ASSERT(ViewManager, 0x1bc)

// STUB: LEGO1 0x100a5eb0
ViewManager::ViewManager(Tgl::Renderer* pRenderer, Tgl::Group* scene, const OrientableROI* point_of_view)
{
}

// STUB: LEGO1 0x100a60c0
ViewManager::~ViewManager()
{
}

// STUB: LEGO1 0x100a64d0
void ViewManager::RemoveAll(ViewROI*)
{
	// TODO
}

// STUB: LEGO1 0x100a6930
void ViewManager::Update(float p_previousRenderTime, float p_und2)
{
}

// STUB: LEGO1 0x100a6d50
void ViewManager::SetResolution(int width, int height)
{
}

// STUB: LEGO1 0x100a6d70
void ViewManager::SetFrustrum(float fov, float front, float back)
{
}

// STUB: LEGO1 0x100a6da0
void ViewManager::SetPOVSource(const OrientableROI* point_of_view)
{
}
