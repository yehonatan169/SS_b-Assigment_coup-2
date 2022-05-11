#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup
{
    Player::Player(Game &game, string &name)
    {
        this->my_coins = 0;
        this->name = name;
        this->my_game = &game;
        this->status = 1;
        my_game->add_player(*this);
    }

    Player::~Player() {}

    int Player::coins() const
    {
        return this->my_coins;
    }

    // search in the queue if found p change his status
    void Player::coup(Player &p)
    {
        check_turn();
        if (p.status == 1)
        {
            if (this->my_coins >= MIN_FOR_COUP)
            {
                for (auto &i : this->my_game->player)
                {

                    if (i->name == p.name)
                    {
                        p.status = 3; // dead
                        this->my_game->action[this->name].second = "coup";
                        this->my_coins -= MIN_FOR_COUP;
                        this->my_game->update_game();
                        return;
                    }
                }

                throw invalid_argument("no such player p");
            }
            throw invalid_argument("not enough coins to make coup");
        }
        throw invalid_argument("the player is already dead");
    }

    void Player::income()
    {
        check_turn();
        check_game();
        if (this->my_coins >= MAX_FOR_NOT_COUP)
        {
            throw invalid_argument("the player mast make coup");
        }

        this->my_game->action[this->name].second = "income";
        this->my_coins += 1;
        this->my_game->update_game();
    }

    void Player::foreign_aid()
    {
        check_turn();
        check_game();
        if (this->my_coins >= MAX_FOR_NOT_COUP)
        {
            throw invalid_argument("the player mast make coup");
        }
        this->my_game->action[this->name].second = "foreign_aid";
        this->my_coins += 2;
        this->my_game->update_game();
    }

    string Player::role() const
    {
        return this->roll;
    }

    // check if its your turn
    void Player::check_turn() const
    {
        if (this->status == 1)
        {
            if (this->my_game->player[0]->name != this->name)
            {
                throw invalid_argument("not your turn");
            }
        }
        else
        {
            throw invalid_argument("you are dead");
        }
    }

    // check if the game can be start
    void Player::check_game() const
    {
        if (this->my_game->player.size() >= 2)
        {
            this->my_game->active = 1;
        }
        else
        {
            throw invalid_argument("the game can start only with minimum 2 players");
        }
    }
}