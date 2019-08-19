#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H
#include "Player.h"
#include<map>
#include<string>


typedef enum struct{
    SUCCESS, PLAYER_EXISTS, PLAYER_NOT_EXISTS, OUT_OF_MEMORY, KEY_EXISTS, KEY_NOT_EXISTS//to be continued...
}* ActionResult;

class GameSystem{
private:
    map<int, &Player> players;//id to player


public:
    GameSystem() = default;
    ~GameSystem() = default;

    // ActionResult operator+=(Player& p);
    // ActionResult operator-=(Player& p);
    ActionResult addPlayer(Player& p, int key);
    ActionRsult removePlayer(int key);
    ActionRsult removePlayer(Player p); 
}

#endif