
#include <string>
#include "Assassin.hpp"

using namespace std;
namespace coup {
    Assassin::Assassin(Game &game, string name) : Player(game, name) {
        this->roll = "Assassin";
    }

    Assassin::~Assassin() {}

    void Assassin::coup(Player &p) {
        check_turn();
        if (this->my_coins >= MIN_FOR_COUP) {
            Player::coup(p);
        } else {
            if (this->my_coins >= 3) {
                for (auto &i: this->my_game->player) {
                    if (i->name == p.name) {
                        if (p.status == 1) {
                            p.status = 2; // dead
                            this->my_coins -= 3;
                            this->my_game->action[this->name].first = &p;
                            this->my_game->action[this->name].second = "coup2";
                            this->my_game->update_game();
                            return;
                        }
                        throw invalid_argument("the player is already dead");
                    }
                }
                throw invalid_argument("no such player p");
            }
            throw invalid_argument("not enough coins to make coup");
        }
    }
}