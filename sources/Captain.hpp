#include <vector>
#include <iostream>
#include "Game.hpp"
#include <string>
#include "Player.hpp"
#pragma once
using namespace std;

namespace coup
{
    class Captain : public Player
    {
    public:
        int steal_coin;
        Captain(Game &game,  string name);
        ~Captain();
        void steal(Player &pl);
        void block(Player &pl);
    };
}