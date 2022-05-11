#include "Player.hpp"
#include "Game.hpp"
#include <string>
#pragma once
using namespace std;
namespace coup {
    class Duke : public Player {
    public:
        Duke(Game &game, string name);
        ~Duke();
        void tax();
        void block(Player &pL);

    };
}