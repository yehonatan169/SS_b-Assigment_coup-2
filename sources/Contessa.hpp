#include <vector>
#include <iostream>
#include "Game.hpp"
#include <string>
#include "Player.hpp"

#pragma once
using namespace std;
namespace coup {
    class Contessa : public Player {
    private:

    public:
        Contessa(Game &game, string name);

        ~Contessa();

        void block(Player &pl);

    };
}