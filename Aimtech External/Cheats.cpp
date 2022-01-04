#include "memory.h"
#include "Library.h"
#include <thread>
#include <iostream>

void Features::bunnyhop()
{
	while (true)
	{
		if (!GetAsyncKeyState(VK_XBUTTON2))
			continue;

		if (Localplayer::get_flags() & (1 << 0))
		{
			Localplayer::forcejump(6);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			Localplayer::forcejump(4);
		}
	}
}

void Features::triggerbot()
{
	while (true)
	{
		if (!Localplayer::get_crossid() || Localplayer::get_crossid() > 64)
			continue;

		if (Localplayer::get_team() == Localplayer::Incross::get_entitiesincross_team())
			continue;

		if (!Localplayer::Incross::get_entitiesincross_health())
			continue;

		if (GetAsyncKeyState(VK_MENU))
		{
			Localplayer::forceattack(6);
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			Localplayer::forceattack(4);
		}
	}
}



void Features::glow()
{
	while (true)
	{
		for (auto i = 0; i <= 64; ++i)
		{
			int B = 0;
			int G = (255 * Entitylist::get_health(i) / 100);
			int R = 255 - G;

			if (Entitylist::get_team(i)  == Localplayer::get_team())
				continue;

			Entitylist::force_glow(i, 0, 0, 0, 0, false, true);
			Entitylist::force_clrender(i, R, G, B);

			if (!Entitylist::get_ifdefusing(i) || !Entitylist::get_ifplanting(i))
				continue;

			Entitylist::force_glow(i, R, G, B, 140, true, true);

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}



