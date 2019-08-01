#include<thread>

#include "player.h"

#define START_AMMO

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

void Player::playerHit()
{
    this->weapon
}