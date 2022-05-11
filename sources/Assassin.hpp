#include "Player.hpp"
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
#pragma once
using namespace std;
namespace coup{
    class Assassin : public Player{

    public:
        Assassin(Game &game,string name );
        ~Assassin();
        void coup(Player &p1) override;

    };
}