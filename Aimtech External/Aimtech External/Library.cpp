#include "Library.h"
#include "Memory.h"

namespace Localplayer
{
	const int get_localplayer()
	{
		return Game::memory.Read<std::uintptr_t>(Game::client + Offsets::dwLocalPlayer);
	}

	const int get_team()
	{
		return Game::memory.Read<std::uintptr_t>(get_localplayer() + Offsets::m_iTeamNum);
	}

	const int get_flags()
	{
		return Game::memory.Read<std::uintptr_t>(get_localplayer() + Offsets::m_fFlags);
	}

	const int get_crossid()
	{
		return Game::memory.Read<std::uintptr_t>(get_localplayer() + Offsets::m_iCrosshairId);
	}

	namespace Incross
	{
		const int get_entitiesincross()
		{
			return 	Game::memory.Read<std::uintptr_t>(Game::client + Offsets::dwEntityList + (Localplayer::get_crossid() - 1) * 0x10);
		}

		const int get_entitiesincross_team()
		{
			return 	Game::memory.Read<std::uintptr_t>(get_entitiesincross() + Offsets::m_iTeamNum);
		}

		const int get_entitiesincross_health()
		{
			return 	Game::memory.Read<std::uintptr_t>(get_entitiesincross() + Offsets::m_iHealth);
		}
	}

	void forcejump(int jumpid)
	{
		Game::memory.Write<std::uintptr_t>(Game::client + Offsets::dwForceJump, jumpid);
	}

	void forceattack(int attackid)
	{
		Game::memory.Write<std::uintptr_t>(Game::client + Offsets::dwForceAttack, attackid);
	}
	
}


namespace Entitylist
{
	const int get_entitylist(int Index)
	{
		return Game::memory.Read<std::uintptr_t>(Game::client + Offsets::dwEntityList + Index * 0x10);
	}

	const int get_team(int Index)
	{
		return Game::memory.Read<std::uintptr_t>(get_entitylist(Index) + Offsets::m_iTeamNum);
	}

	const int get_health(int Index)
	{
		return Game::memory.Read<std::uintptr_t>(get_entitylist(Index) + Offsets::m_iHealth);
	}

	const int get_ifdefusing(int Index)
	{
		return Game::memory.Read<std::uintptr_t>(get_entitylist(Index) + Offsets::m_bIsDefusing);
	}

	const int get_ifplanting(int Index)
	{
		return Game::memory.Read<std::uintptr_t>(get_entitylist(Index) + Offsets::m_bStartedArming);
	}

	const int get_glowindex(int Index)
	{
		return Game::memory.Read<std::uintptr_t>(get_entitylist(Index) + Offsets::m_iGlowIndex);
	}

	const int get_glowobjectmanager()
	{
		return Game::memory.Read<std::int32_t>(Game::client + Offsets::dwGlowObjectManager);
	}

	void force_clrender(int Index, int r, int g, int b)
	{
		Game::memory.Write<Color>(get_entitylist(Index) + Offsets::m_clrRender, Color(r, g, b));
	}

	void force_glow(int Index, float r, float g, float b, float a, bool occluded, bool unoccluded)
	{
		Game::memory.Write<float>(get_glowobjectmanager() + (get_glowindex(Index) * 0x38) + 0x8, r/255);
		Game::memory.Write<float>(get_glowobjectmanager() + (get_glowindex(Index) * 0x38) + 0xC, g/255);
		Game::memory.Write<float>(get_glowobjectmanager() + (get_glowindex(Index) * 0x38) + 0x10, b/255);
		Game::memory.Write<float>(get_glowobjectmanager() + (get_glowindex(Index) * 0x38) + 0x14, a/255);

		Game::memory.Write<bool>(get_glowobjectmanager() + (get_glowindex(Index) * 0x38) + 0x27, occluded);
		Game::memory.Write<bool>(get_glowobjectmanager() + (get_glowindex(Index) * 0x38) + 0x28, unoccluded);
	}
}