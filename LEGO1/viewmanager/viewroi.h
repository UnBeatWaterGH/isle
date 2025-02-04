#ifndef VIEWROI_H
#define VIEWROI_H

#include "decomp.h"
#include "realtime/orientableroi.h"
#include "tgl/tgl.h"
#include "viewlodlist.h"

/*
	ViewROI objects represent view objects, collections of view objects,
	etc. Basically, anything which can be placed in a scene and manipilated
	by the view manager is a ViewROI.
*/

// VTABLE: LEGO1 0x100dbe70
// SIZE 0xe0
class ViewROI : public OrientableROI {
public:
	inline ViewROI(Tgl::Renderer* pRenderer, ViewLODList* lodList)
	{
		SetLODList(lodList);
		geometry = pRenderer->CreateGroup();
	}
	inline ~ViewROI() override
	{
		// SetLODList() will decrease refCount of LODList
		SetLODList(0);
		delete geometry;
	}
	inline void SetLODList(ViewLODList* lodList)
	{
		// ??? inherently type unsafe - kind of... because, now, ROI
		//     does not expose SetLODs() ...
		// solution: create pure virtual LODListBase* ROI::GetLODList()
		// and let derived ROI classes hold the LODList

		if (m_lods) {
			reinterpret_cast<ViewLODList*>(m_lods)->Release();
		}

		m_lods = lodList;

		if (m_lods) {
			reinterpret_cast<ViewLODList*>(m_lods)->AddRef();
		}
	}
	float IntrinsicImportance() const override;                  // vtable+0x04
	void VTable0x1c() override;                                  // vtable+0x1c
	void SetLocalTransform(const Matrix4& p_transform) override; // vtable+0x20
	void VTable0x24(const MxMatrix& p_transform) override;       // vtable+0x24
	virtual const Tgl::Group* GetGeometry() const;               // vtable+0x34
	virtual Tgl::Group* GetGeometry();                           // vtable+0x30

	static undefined SetUnk101013d8(undefined p_flag);

protected:
	Tgl::Group* geometry;
	void UpdateWorldData(const MxMatrix& parent2world) override;
};

// SYNTHETIC: LEGO1 0x100aa250
// ViewROI::`scalar deleting destructor'

#endif // VIEWROI_H
