#include "memory.h"
#include "library.h"
#include <thread>
#include <iostream>
#include <string.h>

int main()
{
    std::cout << "Aimtech External Running..........";

    std::thread t_triggerbot(Features::triggerbot);
    std::thread t_glow(Features::glow);
    std::thread t_bunnyhop(Features::bunnyhop);

    t_triggerbot.join();
    t_glow.join();
    t_bunnyhop.join();
}
