
#include <string>
#include "Captain.hpp"

using namespace std;
namespace coup {
    Captain::Captain(Game &game,  string name) : Player(game,name) {
        this->roll = "Captain";
        this->steal_coin = 0;
    }

    Captain::~Captain() {}

    void Captain::steal(Player &pl) {
        check_turn();
        for (auto &i: this->my_game->player) {
            if (i->name == pl.name) {
                if (pl.status == 1) {
                    if (this->my_coins >= MAX_FOR_NOT_COUP) {
                        this->coup(pl);
                        return;
                    }
                    if (pl.my_coins >= 2) // captain steal 2 coins
                    {
                        pl.my_coins -= 2;
                        this->my_coins += 2;
                        this->steal_coin = 2;

                        this->my_game->action[this->name].first = &pl; // from who the captain stole
                        this->my_game->action[this->name].second = "steal";
                    } else {
                        if (pl.my_coins == 1) // captain steal 0 coins
                        {
                            pl.my_coins -= 1;
                            this->my_coins += 1;
                            this->steal_coin = 1;

                            this->my_game->action[this->name].first = &pl; // from who the captain stole
                            this->my_game->action[this->name].second = "steal";
                        } else { // captain steal 0 coins
                            pl.my_coins -= 0;
                            this->my_coins += 0;
                            this->steal_coin = 0;

                            this->my_game->action[this->name].first = &pl; // from who the captain stole
                            this->my_game->action[this->name].second = "steal";
                        }
                    }

                    this->my_game->update_game();
                    return;
                }
                throw invalid_argument("the player pl is dead");
            }
        }
        throw invalid_argument("no such player pl");
    }

    void Captain::block(Player &pl) {

        if (this->status == 1) {
            for (auto &i: this->my_game->player) {
                if (i->name == pl.name) {
                    if (pl.status == 1) {
                        if (pl.roll == "Captain") {
                            if (pl.my_game->action[pl.name].second == "steal") {

                                Player *assaulted = this->my_game->action[pl.name].first;
                                Captain *temp = dynamic_cast<Captain *>(&pl);
                                if (assaulted->status == 1) {
                                    assaulted->my_coins += temp->steal_coin;
                                    if (temp->my_coins >= 2) {
                                        temp->my_coins -= temp->steal_coin;
                                    } else {
                                        temp->my_coins = 0;
                                    }

                                    this->my_game->action[this->name].first = &pl;
                                    this->my_game->action[this->name].second = "block";
                                    return;
                                }
                                throw invalid_argument("the victim is dead");
                            }
                            throw invalid_argument("the player pl didnt make steal action");
                        }
                        throw invalid_argument("the Captain can block only Captain");
                    }
                    throw invalid_argument("the player pl is already dead");
                }
            }
            throw invalid_argument("no such player pl");
        }
        throw invalid_argument("the player that try to make block is dead");
    }
}
