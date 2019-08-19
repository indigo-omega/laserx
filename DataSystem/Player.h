#ifndef PLAYER_H
#define PLAYER_H

#include<stdlib>
#include<String>


using namepsace std;

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
    void reduceAmmo();
    void setActive(bool);
    bool getActive();
}

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
    

}

class Player
{
public:
    //keep client address here...
    Weapon* weapon;
    Suit* suit;
    String name;
    mutex player_mutex;

    Player();
    Player(Weapon& w, Suit& s);
    ~Player();

    //function to return client address here...
    void playerHit(int);
    void playerShot();//returns whether the shot was successful.
    void friend cancelDisable(Player*, HIT_TYPE);
    String getName(){return this->name;}
}


#endif