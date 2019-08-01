#include<thread>
#include<mutex>
#include<time.h>
#include "player.h"


#define HOLD_AFTER_HIT 5
#define START_AMMO 1000

mutex player_mutex;

using namepsace std;

Weapon::Weapon()
{
    this->active = true;
    this->ammo = START_AMMO;
}
Weapon::Weapon(int ammo)
{
    this->active = true;
    this->ammo = ammo;
}

int Weapon::getAmmo()
{
    return this->ammo;
}

void Weapon::setActive(bool b){this->active = b; /*disable weapon hardware*/}
bool Weapon::getActive(){return this->active;}


Suit::Suit()
{
    this->active = true;
    this->hp = 100;
}

void Suit::setActive(bool b){this->active = b; /*disable weapon hardware*/}
bool Suit::getActive(){return this->active;}

Player::Player()
{
    this->suit = new Suit();
    this->weapon = new Weapon();
}

Player::Player(Weapon* w, Suit* s)
{
    this->suit = s;
    this->weapon = w;
}
Player::~Player()
{
    delete this->suit;
    delete this->weapon;
}

void cancelDisable(Player* p)
{
    time_t start = time(NULL);
    while(time(NULL) - start  > HOLD_AFTER_HIT);
    //using shared resource, should use mutex:
    player_mutex.lock();
    p->weapon->setActive(true);
    p->weapon->setActive(true);
    player_mutex.unlock();
}

void Player::playerHit()
{
    
    this->weapon->setActive(false);
    this->suit->setActive(false);
    thread t(cancelDisable, this);
    t.detach();
    
}