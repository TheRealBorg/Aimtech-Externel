#pragma once
#include "Memory.h"
#include "Library.h"
#include <string.h>

namespace Game
{
	const auto memory = Memory("csgo.exe");
	const auto client = memory.GetModuleAddress("client.dll");
	const auto engine = memory.GetModuleAddress("engine.dll");
}

namespace Localplayer
{
    const int get_localplayer();
    const int get_team();
    const int get_flags();

    const int get_crossid();
    namespace Incross
    {
        const int get_entitiesincross();
        const int get_entitiesincross_team();
        const int get_entitiesincross_health();
    }

    void forcejump(int jumpid);
    void forceattack(int attackid);
}

namespace Entitylist
{
    const int get_entitylist(int Index);
    const int get_team(int Index);
    const int get_health(int Index);
    const int get_ifdefusing(int Index);
    const int get_ifplanting(int Index);
    const int get_glowindex(int Index);
    const int get_glowobjectmanager();

    struct Color {std::uint8_t r, g, b;};

    void force_clrender(int  Index, int r, int g, int b);
    void force_glow(int Index, float r, float g, float b, float a, bool occluded, bool unoccluded);
}

namespace Features
{
    void triggerbot();
    void glow();
    void bunnyhop();
}

namespace Offsets
{
      const auto cs_gamerules_data = 0x0;
      const auto m_ArmorValue = 0x117CC;
      const auto m_Collision = 0x320;
      const auto m_CollisionGroup = 0x474;
      const auto m_Local = 0x2FCC;
      const auto m_MoveType = 0x25C;
      const auto m_OriginalOwnerXuidHigh = 0x31D4;
      const auto m_OriginalOwnerXuidLow = 0x31D0;
      const auto m_SurvivalGameRuleDecisionTypes = 0x1328;
      const auto m_SurvivalRules = 0xD00;
      const auto m_aimPunchAngle = 0x303C;
      const auto m_aimPunchAngleVel = 0x3048;
      const auto m_angEyeAnglesX = 0x117D0;
      const auto m_angEyeAnglesY = 0x117D4;
      const auto m_bBombDefused = 0x29C0;
      const auto m_bBombPlanted = 0x9A5;
      const auto m_bBombTicking = 0x2990;
      const auto m_bFreezePeriod = 0x20;
      const auto m_bGunGameImmunity = 0x9990;
      const auto m_bHasDefuser = 0x117DC;
      const auto m_bHasHelmet = 0x117C0;
      const auto m_bInReload = 0x32B5;
      const auto m_bIsDefusing = 0x997C;
      const auto m_bIsQueuedMatchmaking = 0x74;
      const auto m_bIsScoped = 0x9974;
      const auto m_bIsValveDS = 0x7C;
      const auto m_bSpotted = 0x93D;
      const auto m_bSpottedByMask = 0x980;
      const auto m_bStartedArming = 0x3400;
      const auto m_bUseCustomAutoExposureMax = 0x9D9;
      const auto m_bUseCustomAutoExposureMin = 0x9D8;
      const auto m_bUseCustomBloomScale = 0x9DA;
      const auto m_clrRender = 0x70;
      const auto m_dwBoneMatrix = 0x26A8;
      const auto m_fAccuracyPenalty = 0x3340;
      const auto m_fFlags = 0x104;
      const auto m_flC4Blow = 0x29A0;
      const auto m_flCustomAutoExposureMax = 0x9E0;
      const auto m_flCustomAutoExposureMin = 0x9DC;
      const auto m_flCustomBloomScale = 0x9E4;
      const auto m_flDefuseCountDown = 0x29BC;
      const auto m_flDefuseLength = 0x29B8;
      const auto m_flFallbackWear = 0x31E0;
      const auto m_flFlashDuration = 0x10470;
      const auto m_flFlashMaxAlpha = 0x1046C;
      const auto m_flLastBoneSetupTime = 0x2928;
      const auto m_flLowerBodyYawTarget = 0x9ADC;
      const auto m_flNextAttack = 0x2D80;
      const auto m_flNextPrimaryAttack = 0x3248;
      const auto m_flSimulationTime = 0x268;
      const auto m_flTimerLength = 0x29A4;
      const auto m_hActiveWeapon = 0x2F08;
      const auto m_hBombDefuser = 0x29C4;
      const auto m_hMyWeapons = 0x2E08;
      const auto m_hObserverTarget = 0x339C;
      const auto m_hOwner = 0x29DC;
      const auto m_hOwnerEntity = 0x14C;
      const auto m_hViewModel = 0x3308;
      const auto m_iAccountID = 0x2FD8;
      const auto m_iClip1 = 0x3274;
      const auto m_iCompetitiveRanking = 0x1A84;
      const auto m_iCompetitiveWins = 0x1B88;
      const auto m_iCrosshairId = 0x11838;
      const auto m_iDefaultFOV = 0x333C;
      const auto m_iEntityQuality = 0x2FBC;
      const auto m_iFOV = 0x31F4;
      const auto m_iFOVStart = 0x31F8;
      const auto m_iGlowIndex = 0x10488;
      const auto m_iHealth = 0x100;
      const auto m_iItemDefinitionIndex = 0x2FBA;
      const auto m_iItemIDHigh = 0x2FD0;
      const auto m_iMostRecentModelBoneCounter = 0x2690;
      const auto m_iObserverMode = 0x3388;
      const auto m_iShotsFired = 0x103E0;
      const auto m_iState = 0x3268;
      const auto m_iTeamNum = 0xF4;
      const auto m_lifeState = 0x25F;
      const auto m_nBombSite = 0x2994;
      const auto m_nFallbackPaintKit = 0x31D8;
      const auto m_nFallbackSeed = 0x31DC;
      const auto m_nFallbackStatTrak = 0x31E4;
      const auto m_nForceBone = 0x268C;
      const auto m_nTickBase = 0x3440;
      const auto m_nViewModelIndex = 0x29D0;
      const auto m_rgflCoordinateFrame = 0x444;
      const auto m_szCustomName = 0x304C;
      const auto m_szLastPlaceName = 0x35C4;
      const auto m_thirdPersonViewAngles = 0x31E8;
      const auto m_vecOrigin = 0x138;
      const auto m_vecVelocity = 0x114;
      const auto m_vecViewOffset = 0x108;
      const auto m_viewPunchAngle = 0x3030;
      const auto m_zoomLevel = 0x33E0;
      const auto anim_overlays = 0x2990;
      const auto clientstate_choked_commands = 0x4D30;
      const auto clientstate_delta_ticks = 0x174;
      const auto clientstate_last_outgoing_command = 0x4D2C;
      const auto clientstate_net_channel = 0x9C;
      const auto convar_name_hash_table = 0x2F0F8;
      const auto dwClientState = 0x589FC4;
      const auto dwClientState_GetLocalPlayer = 0x180;
      const auto dwClientState_IsHLTV = 0x4D48;
      const auto dwClientState_Map = 0x28C;
      const auto dwClientState_MapDirectory = 0x188;
      const auto dwClientState_MaxPlayer = 0x388;
      const auto dwClientState_PlayerInfo = 0x52C0;
      const auto dwClientState_State = 0x108;
      const auto dwClientState_ViewAngles = 0x4D90;
      const auto dwEntityList = 0x4DD0AB4;
      const auto dwForceAttack = 0x3200FC4;
      const auto dwForceAttack2 = 0x3200FE8;
      const auto dwForceBackward = 0x3201018;
      const auto dwForceForward = 0x320100C;
      const auto dwForceJump = 0x527A9AC;
      const auto dwForceLeft = 0x3201024;
      const auto dwForceRight = 0x3201030;
      const auto dwGameDir = 0x628780;
      const auto dwGameRulesProxy = 0x52EDA2C;      
      const auto dwGetAllClasses = 0xDDEA8C;
      const auto dwGlobalVars = 0x589CC8;
      const auto dwGlowObjectManager = 0x5318E50;
      const auto dwInput = 0x5222088;
      const auto dwInterfaceLinkList = 0x961934;
      const auto dwLocalPlayer = 0xDB558C;
      const auto dwMouseEnable = 0xDBB120;
      const auto dwMouseEnablePtr = 0xDBB0F0;
      const auto dwPlayerResource = 0x31FF350;
      const auto dwRadarBase = 0x520582C;
      const auto dwSensitivity = 0xDBAFBC;
      const auto dwSensitivityPtr = 0xDBAF90;
      const auto dwSetClanTag = 0x8A290;
      const auto dwViewMatrix = 0x4DC23B4;
      const auto dwWeaponTable = 0x5222B6C;
      const auto dwWeaponTableIndex = 0x326C;
      const auto dwYawPtr = 0xDBAD80;
      const auto dwZoomSensitivityRatioPtr = 0xDC0BD0;
      const auto dwbSendPackets = 0xD9372;
      const auto dwppDirect3DDevice9 = 0xA5050;
      const auto find_hud_element = 0x5C0546E0;
      const auto force_update_spectator_glow = 0x3B7F1A;
      const auto interface_engine_cvar = 0x3E9EC;
      const auto is_c4_owner = 0x3C4F10;
      const auto m_bDormant = 0xED;
      const auto m_flSpawnTime = 0x103C0;
      const auto m_pStudioHdr = 0x2950;
      const auto m_pitchClassPtr = 0x5205AC8;
      const auto m_yawClassPtr = 0xDBAD80;
      const auto model_ambient_min = 0x58D03C;
      const auto set_abs_angles = 0x1E5010;
      const auto set_abs_origin = 0x1E4E50;
}



