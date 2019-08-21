#pragma once

#include "Player.h"
#include<map>
#include<string>


typedef enum{
    SUCCESS, PLAYER_EXISTS, PLAYER_NOT_EXISTS, OUT_OF_MEMORY, KEY_EXISTS, KEY_NOT_EXISTS//to be continued...
}* ActionResult;

class GameSystem {
private:
    std::map<int, Player&> players;//id to player


public:
    GameSystem() = default;
    ~GameSystem() = default;

    // ActionResult operator+=(Player& p);
    // ActionResult operator-=(Player& p);
    ActionResult addPlayer(Player& p, int key);
    ActionResult removePlayer(int key);
    ActionResult removePlayer(Player& p);
    Player* getPlayer(int key);
};

