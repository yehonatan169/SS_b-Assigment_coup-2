#include <string>
#include "Ambassador.hpp"
#include "Captain.hpp"

using namespace std;
namespace coup {
    Ambassador::Ambassador(Game &game, string name) : Player(game, name) {
        this->roll = "Ambassador";
    }

    Ambassador::~Ambassador() {}

    void Ambassador::transfer(Player &give, Player &taker) {
        check_turn();
        for (auto &i: this->my_game->player) {
            if (i->name == give.name) {
                if (give.status == 1) {
                    if (give.my_coins > 0) {
                        for (auto &j: this->my_game->player) {
                            if (j->name == taker.name) {

                                give.my_coins -= 1;
                                taker.my_coins += 1;

                                this->my_game->action[this->name].first = nullptr;
                                this->my_game->action[this->name].second = "transfer";
                                this->my_game->update_game();
                                return;
                            }
                        }
                        throw invalid_argument("the player taker not exist");
                    }
                    throw invalid_argument("not enough coin to transfer");
                }
                throw invalid_argument("the player give is dead ");
            }
        }
        throw invalid_argument("the player give not exist ");
    }

    void Ambassador::block(Player &pl) {
        if (this->status == 1) // check if the Ambassador is alive
        {
            for (auto &i: this->my_game->player) // fond the player that shuld be block
            {
                if (i->name == pl.name) {
                    if (pl.status == 1) // check if the player is alive
                    {
                        if (pl.roll == "Captain") // check if the player is Captain
                        {
                            if (pl.my_game->action[pl.name].second == "steal") // check if the Captain make steal
                            {

                                Captain *temp = dynamic_cast<Captain *>(&pl); // make dynamic cating to Captain

                                this->my_game->action[pl.name].first->my_coins += temp->steal_coin; // give him back the stolen coin
                                if (temp->my_coins >= 2) {
                                    temp->my_coins -= temp->steal_coin; // take from the captain the coins he stole
                                } else {
                                    temp->my_coins = 0;
                                }

                                this->my_game->action[this->name].first = &pl; // keep on who the Ambassador make block
                                this->my_game->action[this->name].second = "block"; // keep the action of the Ambassador
                                return;

                            }
                            throw invalid_argument("the player pl didnt make steal action");
                        }
                        throw invalid_argument("the Ambassador can block only Captain");
                    }
                    throw invalid_argument("the player pl is already dead");
                }
            }
            throw invalid_argument("no such player pl");
        }
        throw invalid_argument("the player that try to make block is dead");
    }

}