#include <vector>
#include <iostream>
#include "Game.hpp"
#include <string>
#include "Player.hpp"

#pragma once
using namespace std;
namespace coup {
    class Ambassador : public Player {
    private:

    public:
        Ambassador(Game &game, string name);

        ~Ambassador();

        void transfer(Player &give, Player &taker);

        void block(Player &pl);

    };
}