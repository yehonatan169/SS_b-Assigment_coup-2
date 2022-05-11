
#pragma once
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
const int MIN_FOR_COUP=7;
const int MAX_FOR_NOT_COUP=10;
using namespace std;
namespace coup {
    class Game;
    class Player{
    public:
        int my_coins;
        string name;
        string roll;
        int status; // 1= alive 2= almost dead 3=dead
        coup::Game *my_game;
        Player(coup::Game &game,string &name);
        ~Player();

        void income(); // coin++;
        void foreign_aid(); // coin + 2
        virtual void coup(Player &p1); // seek at mygame.players() the name p1 and delete him from the list, coin - 7

        int coins() const; // return my_coins
        string role() const; // return roll

        void check_turn() const;
        void check_game() const;

    };
    
}
