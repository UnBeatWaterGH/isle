#include "legoomni.h"

#include "gifmanager.h"
#include "legoanimationmanager.h"
#include "legobuildingmanager.h"
#include "legogamestate.h"
#include "legoinputmanager.h"
#include "legoobjectfactory.h"
#include "legoplantmanager.h"
#include "legosoundmanager.h"
#include "legounksavedatawriter.h"
#include "legoutil.h"
#include "legovideomanager.h"
#include "legoworld.h"
#include "legoworldlist.h"
#include "mxactionnotificationparam.h"
#include "mxautolocker.h"
#include "mxbackgroundaudiomanager.h"
#include "mxdsfile.h"
#include "mxomnicreateflags.h"
#include "mxomnicreateparam.h"
#include "mxstreamer.h"
#include "mxticklemanager.h"
#include "mxtransitionmanager.h"
#include "viewmanager/viewmanager.h"

DECOMP_SIZE_ASSERT(LegoWorldList, 0x18);
DECOMP_SIZE_ASSERT(LegoWorldListCursor, 0x10);

// GLOBAL: LEGO1 0x100f451c
MxAtomId* g_copterScript = NULL;

// GLOBAL: LEGO1 0x100f4520
MxAtomId* g_dunecarScript = NULL;

// GLOBAL: LEGO1 0x100f4524
MxAtomId* g_jetskiScript = NULL;

// GLOBAL: LEGO1 0x100f4528
MxAtomId* g_racecarScript = NULL;

// GLOBAL: LEGO1 0x100f452c
MxAtomId* g_carraceScript = NULL;

// GLOBAL: LEGO1 0x100f4530
MxAtomId* g_carracerScript = NULL;

// GLOBAL: LEGO1 0x100f4534
MxAtomId* g_jetraceScript = NULL;

// GLOBAL: LEGO1 0x100f4538
MxAtomId* g_jetracerScript = NULL;

// GLOBAL: LEGO1 0x100f453c
MxAtomId* g_isleScript = NULL;

// GLOBAL: LEGO1 0x100f4540
MxAtomId* g_elevbottScript = NULL;

// GLOBAL: LEGO1 0x100f4544
MxAtomId* g_infodoorScript = NULL;

// GLOBAL: LEGO1 0x100f4548
MxAtomId* g_infomainScript = NULL;

// GLOBAL: LEGO1 0x100f454c
MxAtomId* g_infoscorScript = NULL;

// GLOBAL: LEGO1 0x100f4550
MxAtomId* g_regbookScript = NULL;

// GLOBAL: LEGO1 0x100f4554
MxAtomId* g_histbookScript = NULL;

// GLOBAL: LEGO1 0x100f4558
MxAtomId* g_hospitalScript = NULL;

// GLOBAL: LEGO1 0x100f455c
MxAtomId* g_policeScript = NULL;

// GLOBAL: LEGO1 0x100f4560
MxAtomId* g_garageScript = NULL;

// GLOBAL: LEGO1 0x100f4564
MxAtomId* g_act2mainScript = NULL;

// GLOBAL: LEGO1 0x100f4568
MxAtomId* g_act3Script = NULL;

// GLOBAL: LEGO1 0x100f456c
MxAtomId* g_jukeboxScript = NULL;

// GLOBAL: LEGO1 0x100f4570
MxAtomId* g_pz5Script = NULL;

// GLOBAL: LEGO1 0x100f4574
MxAtomId* g_introScript = NULL;

// GLOBAL: LEGO1 0x100f4578
MxAtomId* g_testScript = NULL;

// GLOBAL: LEGO1 0x100f457c
MxAtomId* g_jukeboxwScript = NULL;

// GLOBAL: LEGO1 0x100f4580
MxAtomId* g_sndAnimScript = NULL;

// GLOBAL: LEGO1 0x100f4584
MxAtomId* g_creditsScript = NULL;

// GLOBAL: LEGO1 0x100f4588
MxAtomId* g_nocdSourceName = NULL;

// GLOBAL: LEGO1 0x100f6718
// STRING: LEGO1 0x100f6710
const char* g_current = "current";

// GLOBAL: LEGO1 0x100f4c58
MxBool g_isWorldActive = TRUE;

// FUNCTION: LEGO1 0x10015700
LegoOmni* Lego()
{
	return LegoOmni::GetInstance();
}

// FUNCTION: LEGO1 0x10015710
LegoSoundManager* SoundManager()
{
	return LegoOmni::GetInstance()->GetSoundManager();
}

// FUNCTION: LEGO1 0x10015720
LegoVideoManager* VideoManager()
{
	return LegoOmni::GetInstance()->GetVideoManager();
}

// FUNCTION: LEGO1 0x10015730
MxBackgroundAudioManager* BackgroundAudioManager()
{
	return LegoOmni::GetInstance()->GetBackgroundAudioManager();
}

// FUNCTION: LEGO1 0x10015740
LegoInputManager* InputManager()
{
	return LegoOmni::GetInstance()->GetInputManager();
}

// FUNCTION: LEGO1 0x10015750
LegoControlManager* ControlManager()
{
	return LegoOmni::GetInstance()->GetInputManager()->GetControlManager();
}

// FUNCTION: LEGO1 0x10015760
LegoGameState* GameState()
{
	return LegoOmni::GetInstance()->GetGameState();
}

// FUNCTION: LEGO1 0x10015770
LegoAnimationManager* AnimationManager()
{
	return LegoOmni::GetInstance()->GetAnimationManager();
}

// FUNCTION: LEGO1 0x10015780
LegoNavController* NavController()
{
	return LegoOmni::GetInstance()->GetNavController();
}

// FUNCTION: LEGO1 0x10015790
IslePathActor* CurrentVehicle()
{
	return LegoOmni::GetInstance()->GetCurrentVehicle();
}

// FUNCTION: LEGO1 0x100157a0
LegoWorld* CurrentWorld()
{
	return LegoOmni::GetInstance()->GetCurrentWorld();
}

// FUNCTION: LEGO1 0x100157b0
LegoUnkSaveDataWriter* UnkSaveDataWriter()
{
	return LegoOmni::GetInstance()->GetUnkSaveDataWriter();
}

// FUNCTION: LEGO1 0x100157c0
ViewManager* GetViewManager()
{
	return VideoManager()->Get3DManager()->GetLego3DView()->GetViewManager();
}

// FUNCTION: LEGO1 0x100157e0
LegoPlantManager* PlantManager()
{
	return LegoOmni::GetInstance()->GetLegoPlantManager();
}

// FUNCTION: LEGO1 0x100157f0
LegoBuildingManager* BuildingManager()
{
	return LegoOmni::GetInstance()->GetLegoBuildingManager();
}

// FUNCTION: LEGO1 0x10015800
GifManager* GetGifManager()
{
	return LegoOmni::GetInstance()->GetGifManager();
}

// FUNCTION: LEGO1 0x10015820
void FUN_10015820(MxBool p_disable, MxU16 p_flags)
{
	LegoOmni::GetInstance()->FUN_1005b4f0(p_disable, p_flags);
}

// STUB: LEGO1 0x10015860
void FUN_10015860(const char*, MxU8)
{
	// TODO
}

// FUNCTION: LEGO1 0x100158c0
LegoWorld* FindWorld(const MxAtomId& p_atom, MxS32 p_entityid)
{
	return LegoOmni::GetInstance()->FindWorld(p_atom, p_entityid);
}

// FUNCTION: LEGO1 0x100158e0
MxDSAction& GetCurrentAction()
{
	return LegoOmni::GetInstance()->GetCurrentAction();
}

// FUNCTION: LEGO1 0x100158f0
void SetCurrentWorld(LegoWorld* p_world)
{
	LegoOmni::GetInstance()->SetCurrentWorld(p_world);
}

// FUNCTION: LEGO1 0x10015900
MxTransitionManager* TransitionManager()
{
	return LegoOmni::GetInstance()->GetTransitionManager();
}

// FUNCTION: LEGO1 0x10015910
void PlayMusic(MxU32 p_index)
{
	// index is the entityid of the music in jukebox.si
	MxDSAction action;
	action.SetAtomId(*g_jukeboxScript);
	action.SetObjectId(p_index);

	LegoOmni::GetInstance()->GetBackgroundAudioManager()->PlayMusic(action, 5, 4);
}

// FUNCTION: LEGO1 0x100159c0
void SetIsWorldActive(MxBool p_isWorldActive)
{
	if (!p_isWorldActive) {
		LegoOmni::GetInstance()->GetInputManager()->SetCamera(NULL);
	}
	g_isWorldActive = p_isWorldActive;
}

// FUNCTION: LEGO1 0x100159e0
void DeleteObjects(MxAtomId* p_id, MxS32 p_first, MxS32 p_last)
{
	MxDSAction action;

	action.SetAtomId(*p_id);
	action.SetUnknown24(-2);

	for (MxS32 first = p_first, last = p_last; first <= last; first++) {
		action.SetObjectId(first);
		DeleteObject(action);
	}
}

// STUB: LEGO1 0x1001a700
void FUN_1001a700()
{
	// TODO

	// This function seems to populate an unknown structure, and then calls 0x1001b230
}

// FUNCTION: LEGO1 0x1003dd70
LegoROI* PickROI(MxLong p_a, MxLong p_b)
{
	return (LegoROI*) VideoManager()->Get3DManager()->GetLego3DView()->Pick(p_a, p_b);
}

// STUB: LEGO1 0x1003ddc0
LegoEntity* PickEntity(MxLong, MxLong)
{
	// TODO
	return NULL;
}

// FUNCTION: LEGO1 0x100528e0
void RegisterScripts()
{
	g_copterScript = new MxAtomId("\\lego\\scripts\\build\\copter", e_lowerCase2);
	g_dunecarScript = new MxAtomId("\\lego\\scripts\\build\\dunecar", e_lowerCase2);
	g_jetskiScript = new MxAtomId("\\lego\\scripts\\build\\jetski", e_lowerCase2);
	g_racecarScript = new MxAtomId("\\lego\\scripts\\build\\racecar", e_lowerCase2);
	g_carraceScript = new MxAtomId("\\lego\\scripts\\race\\carrace", e_lowerCase2);
	g_carracerScript = new MxAtomId("\\lego\\scripts\\race\\carracer", e_lowerCase2);
	g_jetraceScript = new MxAtomId("\\lego\\scripts\\race\\jetrace", e_lowerCase2);
	g_jetracerScript = new MxAtomId("\\lego\\scripts\\race\\jetracer", e_lowerCase2);
	g_isleScript = new MxAtomId("\\lego\\scripts\\isle\\isle", e_lowerCase2);
	g_elevbottScript = new MxAtomId("\\lego\\scripts\\infocntr\\elevbott", e_lowerCase2);
	g_infodoorScript = new MxAtomId("\\lego\\scripts\\infocntr\\infodoor", e_lowerCase2);
	g_infomainScript = new MxAtomId("\\lego\\scripts\\infocntr\\infomain", e_lowerCase2);
	g_infoscorScript = new MxAtomId("\\lego\\scripts\\infocntr\\infoscor", e_lowerCase2);
	g_regbookScript = new MxAtomId("\\lego\\scripts\\infocntr\\regbook", e_lowerCase2);
	g_histbookScript = new MxAtomId("\\lego\\scripts\\infocntr\\histbook", e_lowerCase2);
	g_hospitalScript = new MxAtomId("\\lego\\scripts\\hospital\\hospital", e_lowerCase2);
	g_policeScript = new MxAtomId("\\lego\\scripts\\police\\police", e_lowerCase2);
	g_garageScript = new MxAtomId("\\lego\\scripts\\garage\\garage", e_lowerCase2);
	g_act2mainScript = new MxAtomId("\\lego\\scripts\\act2\\act2main", e_lowerCase2);
	g_act3Script = new MxAtomId("\\lego\\scripts\\act3\\act3", e_lowerCase2);
	g_jukeboxScript = new MxAtomId("\\lego\\scripts\\isle\\jukebox", e_lowerCase2);
	g_pz5Script = new MxAtomId("\\lego\\scripts\\isle\\pz5", e_lowerCase2);
	g_introScript = new MxAtomId("\\lego\\scripts\\intro", e_lowerCase2);
	g_testScript = new MxAtomId("\\lego\\scripts\\test\\test", e_lowerCase2);
	g_jukeboxwScript = new MxAtomId("\\lego\\scripts\\isle\\jukeboxw", e_lowerCase2);
	g_sndAnimScript = new MxAtomId("\\lego\\scripts\\sndanim", e_lowerCase2);
	g_creditsScript = new MxAtomId("\\lego\\scripts\\credits", e_lowerCase2);
	g_nocdSourceName = new MxAtomId("\\lego\\scripts\\nocd", e_lowerCase2);
}

// FUNCTION: LEGO1 0x100530c0
void UnregisterScripts()
{
	delete g_copterScript;
	delete g_dunecarScript;
	delete g_jetskiScript;
	delete g_racecarScript;
	delete g_carraceScript;
	delete g_carracerScript;
	delete g_jetraceScript;
	delete g_jetracerScript;
	delete g_isleScript;
	delete g_elevbottScript;
	delete g_infodoorScript;
	delete g_infomainScript;
	delete g_infoscorScript;
	delete g_regbookScript;
	delete g_histbookScript;
	delete g_hospitalScript;
	delete g_policeScript;
	delete g_garageScript;
	delete g_act2mainScript;
	delete g_act3Script;
	delete g_jukeboxScript;
	delete g_pz5Script;
	delete g_introScript;
	delete g_testScript;
	delete g_jukeboxwScript;
	delete g_sndAnimScript;
	delete g_creditsScript;
	delete g_nocdSourceName;

	g_copterScript = NULL;
	g_dunecarScript = NULL;
	g_jetskiScript = NULL;
	g_racecarScript = NULL;
	g_carraceScript = NULL;
	g_carracerScript = NULL;
	g_jetraceScript = NULL;
	g_jetracerScript = NULL;
	g_isleScript = NULL;
	g_elevbottScript = NULL;
	g_infodoorScript = NULL;
	g_infomainScript = NULL;
	g_infoscorScript = NULL;
	g_regbookScript = NULL;
	g_histbookScript = NULL;
	g_hospitalScript = NULL;
	g_policeScript = NULL;
	g_garageScript = NULL;
	g_act2mainScript = NULL;
	g_act3Script = NULL;
	g_jukeboxScript = NULL;
	g_pz5Script = NULL;
	g_introScript = NULL;
	g_testScript = NULL;
	g_testScript = NULL;
	g_jukeboxwScript = NULL;
	g_sndAnimScript = NULL;
	g_creditsScript = NULL;
	g_nocdSourceName = NULL;
}

// FUNCTION: LEGO1 0x10053430
const char* GetNoCD_SourceName()
{
	return g_nocdSourceName->GetInternal();
}

// FUNCTION: LEGO1 0x10058a00
LegoOmni::LegoOmni()
{
	Init();
}

// FUNCTION: LEGO1 0x10058b50
LegoOmni::~LegoOmni()
{
	Destroy();
}

// FUNCTION: LEGO1 0x10058bd0
void LegoOmni::Init()
{
	MxOmni::Init();
	m_unk0x68 = 0;
	m_inputMgr = NULL;
	m_viewLODListManager = NULL;
	m_gifManager = NULL;
	m_worldList = NULL;
	m_currentWorld = NULL;
	m_exit = FALSE;
	m_currentVehicle = NULL;
	m_saveDataWriter = NULL;
	m_plantManager = NULL;
	m_gameState = NULL;
	m_animationManager = NULL;
	m_buildingManager = NULL;
	m_bkgAudioManager = NULL;
	m_unk0x13c = TRUE;
	m_transitionManager = NULL;
}

// FUNCTION: LEGO1 0x10058c30
void LegoOmni::Destroy()
{
	MxAutoLocker lock(&this->m_criticalsection);

	m_notificationManager->Unregister(this);

	if (m_worldList) {
		delete m_worldList;
		m_worldList = NULL;
	}

	if (m_gameState) {
		delete m_gameState;
		m_gameState = NULL;
	}

	if (m_animationManager) {
		delete m_animationManager;
		m_animationManager = NULL;
	}

	if (m_saveDataWriter) {
		delete m_saveDataWriter;
		m_saveDataWriter = NULL;
	}

	if (m_plantManager) {
		delete m_plantManager;
		m_plantManager = NULL;
	}

	if (m_buildingManager) {
		delete m_buildingManager;
		m_buildingManager = NULL;
	}

	if (m_gifManager) {
		delete m_gifManager;
		m_gifManager = NULL;
	}

	if (m_viewLODListManager) {
		delete m_viewLODListManager;
		m_viewLODListManager = NULL;
	}

	if (m_inputMgr) {
		delete m_inputMgr;
		m_inputMgr = NULL;
	}

	if (m_inputMgr) {
		delete m_inputMgr;
		m_inputMgr = NULL;
	}

	// todo FUN_10046de0

	if (m_bkgAudioManager) {
		m_bkgAudioManager->Stop();

		delete m_bkgAudioManager;
		m_bkgAudioManager = NULL;
	}

	if (m_transitionManager) {
		delete m_transitionManager;
		m_transitionManager = NULL;
	}

	m_action.ClearAtom();
	UnregisterScripts();

	delete[] m_unk0x68;

	MxOmni::Destroy();
}

// FUNCTION: LEGO1 0x10058e70
MxResult LegoOmni::Create(MxOmniCreateParam& p_param)
{
	MxResult result = FAILURE;
	MxAutoLocker lock(&this->m_criticalsection);

	p_param.CreateFlags().CreateObjectFactory(FALSE);
	p_param.CreateFlags().CreateVideoManager(FALSE);
	p_param.CreateFlags().CreateSoundManager(FALSE);
	p_param.CreateFlags().CreateTickleManager(FALSE);

	if (!(m_tickleManager = new MxTickleManager())) {
		return FAILURE;
	}

	if (MxOmni::Create(p_param) != SUCCESS) {
		return FAILURE;
	}

	m_objectFactory = new LegoObjectFactory();
	if (m_objectFactory == NULL) {
		return FAILURE;
	}

	if ((m_soundManager = new LegoSoundManager())) {
		if (m_soundManager->Create(10, 0) != SUCCESS) {
			delete m_soundManager;
			m_soundManager = NULL;
			return FAILURE;
		}
	}

	if ((m_videoManager = new LegoVideoManager())) {
		if (m_videoManager->Create(p_param.GetVideoParam(), 100, 0) != SUCCESS) {
			delete m_videoManager;
			m_videoManager = NULL;
		}
	}

	if ((m_inputMgr = new LegoInputManager())) {
		if (m_inputMgr->Create(p_param.GetWindowHandle()) != SUCCESS) {
			delete m_inputMgr;
			m_inputMgr = NULL;
		}
	}

	m_viewLODListManager = new ViewLODListManager();
	m_gifManager = new GifManager();
	// TODO: there is another class here
	m_plantManager = new LegoPlantManager();
	m_animationManager = new LegoAnimationManager();
	m_buildingManager = new LegoBuildingManager();
	m_gameState = new LegoGameState();
	m_worldList = new LegoWorldList(TRUE);

	if (m_viewLODListManager && m_gifManager && m_worldList && m_plantManager && m_animationManager &&
		m_buildingManager) {
		// TODO: initialize a bunch of MxVariables
		RegisterScripts();
		FUN_1001a700();
		// todo: another function call. in legoomni maybe?
		m_bkgAudioManager = new MxBackgroundAudioManager();
		if (m_bkgAudioManager != NULL) {
			m_transitionManager = new MxTransitionManager();
			if (m_transitionManager != NULL) {
				if (m_transitionManager->GetDDrawSurfaceFromVideoManager() == SUCCESS) {
					m_notificationManager->Register(this);
					SetAppCursor(1);
					m_gameState->FUN_1003cea0(0);
					return SUCCESS;
				}
			}
		}
	}

	return FAILURE;
}

// FUNCTION: LEGO1 0x1005ac90
void LegoOmni::CreateInstance()
{
	MxOmni::DestroyInstance();
	MxOmni::SetInstance(new LegoOmni());
}

// FUNCTION: LEGO1 0x1005ad10
LegoOmni* LegoOmni::GetInstance()
{
	return (LegoOmni*) MxOmni::GetInstance();
}

// FUNCTION: LEGO1 0x1005ad20
void LegoOmni::AddWorld(LegoWorld* p_world)
{
	m_worldList->Append(p_world);
}

// FUNCTION: LEGO1 0x1005adb0
void LegoOmni::DeleteWorld(LegoWorld* p_world)
{
	if (m_worldList) {
		LegoWorldListCursor cursor(m_worldList);

		if (cursor.Find(p_world)) {
			cursor.Detach();

			if (m_currentWorld == p_world) {
				m_currentWorld = NULL;
			}

			delete p_world;
		}
	}
}

// FUNCTION: LEGO1 0x1005af10
void LegoOmni::RemoveWorld(const MxAtomId& p_atom, MxLong p_objectId)
{
	if (m_worldList) {
		LegoWorldListCursor a(m_worldList);
		LegoWorldListCursor b(m_worldList);
		LegoWorld* world;

		a.Head();
		while (a.Current(world)) {
			b = a;
			b.Next();

			if ((p_objectId == -1 || world->GetEntityId() == p_objectId) &&
				(!p_atom.GetInternal() || world->GetAtom() == p_atom)) {
				a.Detach();
				delete world;
			}

			a = b;
		}
	}
}

// FUNCTION: LEGO1 0x1005b0c0
LegoWorld* LegoOmni::FindWorld(const MxAtomId& p_atom, MxS32 p_entityid)
{
	if (m_worldList) {
		LegoWorldListCursor cursor(m_worldList);
		LegoWorld* world;

		while (cursor.Next(world)) {
			if ((p_entityid == -1 || world->GetEntityId() == p_entityid) &&
				(!p_atom.GetInternal() || world->GetAtom() == p_atom)) {
				return world;
			}
		}
	}

	return NULL;
}

// FUNCTION: LEGO1 0x1005b1d0
void LegoOmni::DeleteObject(MxDSAction& p_dsAction)
{
	if (p_dsAction.GetAtomId().GetInternal() != NULL) {
		LegoWorld* world = FindWorld(p_dsAction.GetAtomId(), p_dsAction.GetObjectId());
		if (world) {
			DeleteWorld(world);
			return;
		}

		if (m_currentWorld != NULL) {
			MxCore* entity = m_currentWorld->Find(p_dsAction.GetAtomId(), p_dsAction.GetObjectId());
			if (entity) {
				m_currentWorld->Remove(entity);

				if (entity->IsA("MxPresenter")) {
					Streamer()->FUN_100b98f0(((MxPresenter*) entity)->GetAction());
					((MxPresenter*) entity)->EndAction();
				}
				else {
					delete entity;
				}
				return;
			}
		}
	}
	MxOmni::DeleteObject(p_dsAction);
}

// FUNCTION: LEGO1 0x1005b2f0
MxEntity* LegoOmni::AddToWorld(const char* p_id, MxS32 p_entityId, MxPresenter* p_presenter)
{
	LegoWorld* world = NULL;

	if (strcmpi(p_id, g_current)) {
		world = FindWorld(MxAtomId(p_id, e_lowerCase2), p_entityId);
	}
	else {
		world = this->m_currentWorld;
	}

	if (world != NULL) {
		world->Add(p_presenter);
	}

	return world;
}

// FUNCTION: LEGO1 0x1005b3a0
void LegoOmni::NotifyCurrentEntity(MxNotificationParam* p_param)
{
	if (m_currentWorld) {
		NotificationManager()->Send(m_currentWorld, p_param);
	}
}

// FUNCTION: LEGO1 0x1005b3c0
MxBool LegoOmni::DoesEntityExist(MxDSAction& p_dsAction)
{
	if (MxOmni::DoesEntityExist(p_dsAction)) {
		if (FindWorld(p_dsAction.GetAtomId(), p_dsAction.GetObjectId()) == NULL) {
			return TRUE;
		}
	}
	return FALSE;
}

// FUNCTION: LEGO1 0x1005b400
MxS32 LegoOmni::GetCurrPathInfo(LegoPathBoundary** p_path, MxS32& p_value)
{
	if (::CurrentWorld() == NULL) {
		return FAILURE;
	}

	return ::CurrentWorld()->GetCurrPathInfo(p_path, p_value);
}

// FUNCTION: LEGO1 0x1005b4f0
void LegoOmni::FUN_1005b4f0(MxBool p_disable, MxU16 p_flags)
{
	if (p_disable) {
		if (p_flags & c_disableInput) {
			m_inputMgr->DisableInputProcessing();
		}

		if (p_flags & c_disable3d) {
			((LegoVideoManager*) m_videoManager)->SetRender3D(FALSE);
		}

		if (p_flags & c_clearScreen) {
			m_videoManager->GetDisplaySurface()->ClearScreen();
		}
	}
	else {
		m_inputMgr->EnableInputProcessing();
		((LegoVideoManager*) m_videoManager)->SetRender3D(TRUE);
		((LegoVideoManager*) m_videoManager)->UpdateView(0, 0, 0, 0);
	}
}

// FUNCTION: LEGO1 0x1005b560
void LegoOmni::CreateBackgroundAudio()
{
	if (m_bkgAudioManager) {
		m_bkgAudioManager->Create(*g_jukeboxScript, 100);
	}
}

// FUNCTION: LEGO1 0x1005b580
MxResult LegoOmni::Start(MxDSAction* p_dsAction)
{
	MxResult result = MxOmni::Start(p_dsAction);
	this->m_action.SetAtomId(p_dsAction->GetAtomId());
	this->m_action.SetObjectId(p_dsAction->GetObjectId());
	this->m_action.SetUnknown24(p_dsAction->GetUnknown24());
	return result;
}

// FUNCTION: LEGO1 0x1005b5f0
MxLong LegoOmni::Notify(MxParam& p_param)
{
	MxBool isCD = FALSE;

	if (((MxNotificationParam&) p_param).GetType() == c_notificationEndAction &&
		((MxActionNotificationParam&) p_param).GetAction()->GetAtomId() == *g_nocdSourceName) {
		isCD = TRUE;
	}

	MxLong result = MxOmni::Notify(p_param);
	if (isCD) {
		// Exit the game if nocd.si ended
		CloseMainWindow();
	}

	return result;
}

// FUNCTION: LEGO1 0x1005b640
void LegoOmni::StartTimer()
{
	MxOmni::StartTimer();
	SetAppCursor(2);
}

// FUNCTION: LEGO1 0x1005b650
void LegoOmni::StopTimer()
{
	MxOmni::StopTimer();
	SetAppCursor(0);
}
