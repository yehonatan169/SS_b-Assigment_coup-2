#include "Game.hpp"

using namespace std;

namespace coup {
    Game::Game() {
        this->player = {};
        this->action = {};
        this->player_list = {};
        this->active = 0;
    }

    Game::~Game() {}

    vector <string> Game::players() { // itrat on the queue and copy his cells to vector and return the vector
        vector <string> t = {};
        for (auto &i: this->player_list) {
            if (i->status == 1) {
                t.push_back(i->name);
            }
        }
        return t;
    }

    string Game::turn() {
        for (auto &i: this->player) {
            if (i->status == 1) {
                return i->name;
            }
        }
        throw invalid_argument("all players are dead");
    }

    string Game::winner() {
        vector <string> t = this->players();
        if (this->active == 1) {
            if (t.size() == 1) {
                return t.at(0);
            }
            throw invalid_argument("there is still more players");
        }
        throw invalid_argument("the game didnt start yet -- the game can start only with minimum 2 players");

    }

    void Game::add_player(Player &p) {
        if (this->active == 0) {
            if (this->player.size() < MAX_PLAYER) { // max players is 6
                this->player.push_back(&p);
                this->player_list.push_back(&p);
                pair < Player * , string > act;
                act.first = nullptr; // on who we make the acdtion
                act.second = ""; // which action has done
                this->action[p.name] = act;
            } else {
                throw invalid_argument("maximum players in game is 6");
            }
        } else {
            throw invalid_argument("the game is already started");
        }
    }

    void Game::update_game() {
        this->player.push_back(this->player[0]);
        this->player.pop_front();


        while (this->player[0]->status != 1) {
            if (this->player[0]->status == 3) {
                this->player.pop_front();

            } else {
                this->player.push_back(this->player[0]);
                this->player.pop_front();
            }
        }
    }
}