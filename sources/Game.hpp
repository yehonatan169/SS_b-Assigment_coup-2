/*
I got some advice from amit gofer - in functions and also at the fuction update_game : insted using front() to use [0] to accecc the first element of the deque
*/

#pragma once
#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Player.hpp"
#include <stdexcept>
const int MIN_PLAYER = 2;
const int MAX_PLAYER = 6;
using namespace std;
namespace coup {
    class Player;
    class Game{
    public:
        deque<Player*>player;
        vector<Player*>player_list;
        int active;
        unordered_map<string,pair<Player*,string>> action;
        Game();
        ~Game();
        string turn(); //if player not empty cout << player.top << endl;
        vector<string> players(); // return vector of all name in player
        string winner(); // if player size is 1 return the name of the winner
        void add_player(coup::Player &p);// add the player to the game
        void update_game();
        void active_game();

    };
}