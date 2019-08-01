#ifndef PLAYER_H
#define PLAYER_H

#include<stdlib>
#include<String>

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
    void setActive(bool);
    bool getActive();
}

class Suit
{
private:
    bool active;
    int hp;
public:
    Suit();
    void setActive(bool);
    bool getActive();

}

class Player
{
protected:
    Weapon* weapon;
    Suit* suit;
    String name;
public:
    Player();
    Player(Weapon& w, Suit& s);
    ~Player();

    void playerHit();
}


#endif