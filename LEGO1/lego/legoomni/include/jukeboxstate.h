#ifndef JUKEBOXSTATE_H
#define JUKEBOXSTATE_H

#include "legostate.h"

// VTABLE: LEGO1 0x100d4a90
// SIZE 0x10
class JukeBoxState : public LegoState {
public:
	// FUNCTION: LEGO1 0x1000f310
	inline const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x100f02bc
		return "JukeBoxState";
	}

	// FUNCTION: LEGO1 0x1000f320
	inline MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, JukeBoxState::ClassName()) || LegoState::IsA(p_name);
	}

	MxBool VTable0x14() override; // vtable+0x14

	// SYNTHETIC: LEGO1 0x1000f3d0
	// JukeBoxState::`scalar deleting destructor'
};

#endif // JUKEBOXSTATE_H
