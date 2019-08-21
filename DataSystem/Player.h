#pragma once

#include<new>
#include<String>
#include<mutex>
#include<string>

using namespace std;

typedef enum{
    HEAD = 50, BODY = 30, BACK = 20
} HIT_TYPE;

class Weapon
{
private:
    int ammo;//not necessary
public:
    bool active;

    Weapon();
    Weapon(int);

    int getAmmo();
    void reduceAmmo(int);
    void setActive(bool);
    bool getActive();
};

class Suit
{
private:

    bool active;
    int hp;//not necessary relevant
public:
    Suit();
    void setActive(bool);
    bool getActive();
    void reduceHp(int);//should be canceleld
    void restoreHp();
    int getHp();


};

class Player
{
public:
    //keep client address here...
    Weapon* weapon;
    Suit* suit;
    std::string name;
    std::mutex player_mutex;

    Player();
    Player(Weapon* w, Suit* s);
    ~Player();

    //function to return client address here...
    void playerHit(int);
    void playerShot(Player* hitted, HIT_TYPE hit);//returns whether the shot was successful.
    void friend cancelDisable(Player*, HIT_TYPE);
    std::string getName() { return this->name; }
};

