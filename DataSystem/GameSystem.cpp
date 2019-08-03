#include "GameSystem.h"

using namespace std;
bool playerExists(map<int, Player&> m, player& p)
{
    for(map<int, Player&>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if(it->second.getName() == p.getName)//can change to comparing references
            return true;
    }
    return false;
}
bool keyExists(map<int, Player&> m, int key)
{
    for(map<int, Player&>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if(it->first == key)
            return true;
    }
    return false;
}

ActionResult GameSystem::addPlayer(Player& p, int key)
{
    if(playerExists(this->players, p))
        return PLAYER_EXISTS;
    else if(keyExists(this->players, key))
        return KEY_EXISTS;

    this->players.insert(map<int, Player&>::pair(key, p));
    return SUCCESS;

}

ActionResult GameSystem::removePlayer(int key)
{
    if(!keyExists(this->players, key))
        return KEY_NOT_EXISTS;
    map<int, Player&p>::iterator it = this->players.find(key);
    this->players.erase(it);
    return SUCCESS;
}

ActionResult GameSystem::removePlayer(Player& p)
{
    if(!keyExists(this->players, key))
        return KEY_NOT_EXISTS;
    for(map<int, Player&p>::iterator it = this->players.begin(); it != this->players.end(); ++it)
    {
        if(it->second.getName() == p.getName())
        {
            this->players.erase(it);
            return SUCCESS;
        }
    }
    return SUCCESS;
}