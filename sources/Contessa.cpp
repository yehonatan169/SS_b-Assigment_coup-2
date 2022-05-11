
#include "Contessa.hpp"
#include <string>

using namespace std;
namespace coup {
    Contessa::Contessa(Game &game, string name) : Player(game, name) {
        this->roll = "Contessa";
    }

    Contessa::~Contessa() {}

    void Contessa::block(Player &pl) {
        if (this->status == 1) {
            for (auto &i: this->my_game->player) {
                if (i->name == pl.name) {
                    if (pl.status == 1) {
                        if (pl.roll == "Assassin") {
                            if (pl.my_game->action[pl.name].second == "coup2") {

                                this->my_game->action[pl.name].first->status=1;
                                this->my_game->action[this->name].first = &pl;
                                this->my_game->action[this->name].second = "block";
                                return;
                            }
                            throw invalid_argument("the player Assassin didnt make coup2 action");
                        }
                        throw invalid_argument("the Contessa can block only Assassin");
                    }
                    throw invalid_argument("the player pl is already dead");
                }
            }
            throw invalid_argument("no such player pl");
        }
        throw invalid_argument("the player that try to make block is dead");
    }
}