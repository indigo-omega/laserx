#ifndef PLAYER_H
#define PLAYER_H

#include<stdlib>

using namepsace std;
class Weapon
{
private:
    int ammo;//not necessary
public:
    bool active;

    Weapon();
    Weapon(int);

    int getAmmo();
}

class Suit
{
private:
    bool active;
    int hp;
public:
    Suit();

}

class Player
{
protected:
    Weapon* weapon;
    Suit* suit;
public:
    Player();
    Player(Weapon& w, Suit& s);
    ~Player();
}


#endif