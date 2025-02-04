#ifndef MXCORE_H
#define MXCORE_H

#include "compat.h"
#include "mxtypes.h"

#include <string.h>

class MxParam;

// VTABLE: LEGO1 0x100dc0f8
// SIZE 0x08
class MxCore {
public:
	MxCore();
	virtual ~MxCore();                       // vtable+00
	virtual MxLong Notify(MxParam& p_param); // vtable+04

	// FUNCTION: LEGO1 0x10001f70
	virtual MxResult Tickle() { return SUCCESS; } // vtable+08

	// FUNCTION: LEGO1 0x100144c0
	inline virtual const char* ClassName() const // vtable+0c
	{
		// STRING: LEGO1 0x100f007c
		return "MxCore";
	}

	// FUNCTION: LEGO1 0x100140d0
	inline virtual MxBool IsA(const char* p_name) const // vtable+10
	{
		return !strcmp(p_name, MxCore::ClassName());
	}

	inline MxU32 GetId() { return m_id; }

	// SYNTHETIC: LEGO1 0x100ae1c0
	// MxCore::`scalar deleting destructor'

private:
	MxU32 m_id; // 0x04
};

#endif // MXCORE_H
