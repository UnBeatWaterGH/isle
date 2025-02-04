#ifndef ACT1STATE_H
#define ACT1STATE_H

#include "legostate.h"
#include "legoutil.h"
#include "roi/legoroi.h"

// VTABLE: LEGO1 0x100d7028
// SIZE 0x26c
class Act1State : public LegoState {
public:
	enum {
		e_unk953 = 953,
		e_unk954 = 954,
		e_unk955 = 955,
	};

	Act1State();

	// FUNCTION: LEGO1 0x100338a0
	inline const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x100f0154
		return "Act1State";
	}

	// FUNCTION: LEGO1 0x100338b0
	inline MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, Act1State::ClassName()) || LegoState::IsA(p_name);
	}

	MxBool SetFlag() override;                          // vtable+0x18
	MxResult VTable0x1c(LegoFile* p_legoFile) override; // vtable+0x1c

	inline void SetUnknown18(MxU32 p_unk0x18) { m_unk0x018 = p_unk0x18; }
	inline MxU32 GetUnknown18() { return m_unk0x018; }
	inline MxU32 GetUnknown1c() { return m_unk0x01c; }
	inline MxS16 GetUnknown21() { return m_unk0x021; }

	inline void SetUnknown1c(MxU32 p_unk0x1c) { m_unk0x01c = p_unk0x1c; }
	inline void SetUnknown21(MxS16 p_unk0x21) { m_unk0x021 = p_unk0x21; }

	void FUN_10034d00();

	// SYNTHETIC: LEGO1 0x10033960
	// Act1State::`scalar deleting destructor'

	// SIZE 0x4c
	class NamedPlane {
	public:
		// FUNCTION: LEGO1 0x10033800
		NamedPlane() {}

		inline void SetName(const char* p_name) { m_name = p_name; }
		inline const MxString* GetName() const { return &m_name; }

		// FUNCTION: LEGO1 0x100344d0
		MxResult Serialize(LegoFile* p_file)
		{
			if (p_file->IsWriteMode()) {
				p_file->FUN_10006030(m_name);
				p_file->WriteVector3(m_point1);
				p_file->WriteVector3(m_point2);
				p_file->WriteVector3(m_point3);
			}
			else if (p_file->IsReadMode()) {
				p_file->ReadString(m_name);
				p_file->ReadVector3(m_point1);
				p_file->ReadVector3(m_point2);
				p_file->ReadVector3(m_point3);
			}

			return SUCCESS;
		}

	private:
		MxString m_name;         // 0x00
		Mx3DPointFloat m_point1; // 0x10
		Mx3DPointFloat m_point2; // 0x24
		Mx3DPointFloat m_point3; // 0x38
	};

protected:
	MxS32* m_unk0x008; // 0x008
	// FIXME: count for m_unk0x008
	MxS16 m_unk0x00c;         // 0x00c
	undefined2 m_unk0x00e;    // 0x00e
	undefined2 m_unk0x010;    // 0x010
	undefined m_unk0x012;     // 0x012
	MxS32 m_unk0x014;         // 0x014
	MxU32 m_unk0x018;         // 0x018
	MxU16 m_unk0x01c;         // 0x01c
	undefined m_unk0x01e;     // 0x01e
	undefined m_unk0x01f;     // 0x01f
	undefined m_unk0x020;     // 0x020
	undefined m_unk0x021;     // 0x021
	undefined m_unk0x022;     // 0x022
	undefined m_unk0x023;     // 0x023
	NamedPlane m_unk0x024;    // 0x024
	NamedPlane m_unk0x070;    // 0x070
	NamedPlane m_unk0x0bc;    // 0x0bc
	NamedPlane m_unk0x108;    // 0x108
	NamedTexture* m_unk0x154; // 0x154
	NamedTexture* m_unk0x158; // 0x158
	NamedTexture* m_unk0x15c; // 0x15c
	MxCore* m_unk0x160;       // 0x160
	NamedPlane m_unk0x164;    // 0x164
	NamedTexture* m_unk0x1b0; // 0x1b0
	NamedTexture* m_unk0x1b4; // 0x1b4
	MxCore* m_unk0x1b8;       // 0x1b8
	NamedPlane m_unk0x1bc;    // 0x1bc
	NamedTexture* m_unk0x208; // 0x208
	MxCore* m_unk0x20c;       // 0x20c
	NamedPlane m_unk0x210;    // 0x210
	NamedTexture* m_unk0x25c; // 0x25c
	NamedTexture* m_unk0x260; // 0x260
	NamedTexture* m_unk0x264; // 0x264
	MxCore* m_unk0x268;       // 0x268
};

// FUNCTION: LEGO1 0x10033a70
// Act1State::NamedPlane::~NamedPlane

#endif // ACT1STATE_H
