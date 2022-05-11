
#include <string>
#include "Duke.hpp"

using namespace std;
namespace coup {
    Duke::Duke(Game &game, string name) : Player(game, name) {
        this->roll = "Duke";
    }

    Duke::~Duke() {}

    void Duke::block(Player &pl) {
        if (this->status == 1) {
            for (auto &i: this->my_game->player) {
                if (i->name == pl.name) {
                    if (pl.status == 1) {

                        if (pl.my_game->action[pl.name].second == "foreign_aid") {
                            pl.my_coins -= 2;
                            this->my_game->action[this->name].first = &pl;
                            this->my_game->action[this->name].second = "block";
                            return;
                        }
                        throw invalid_argument("the player pl didnt make foreign_aid action");
                    }
                    throw invalid_argument("the player pl is already dead");
                }
            }
            throw invalid_argument("no such player p");
        }
        throw invalid_argument("the player that try to make block is dead");
    }

    void Duke::tax() {
        check_turn();
        if (this->my_coins >= MAX_FOR_NOT_COUP) {
            throw invalid_argument("the duke mast make coup");
        }

        this->my_coins += 3;
        this->my_game->action[this->name].first = this;
        this->my_game->action[this->name].second = "tax";
        this->my_game->update_game();

    }
}