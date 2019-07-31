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


Suit::Suit()
{
    this->active = true;
    this->hp = 100;
}

Player::Player()
{
    this->suit = new Suit();
    this->weapon = new Weapon();
}

Player::Player(Weapon& w, Suit& s)
{
    this->suit = *s;
    this->weapon = *w;
}
Player::~Player()
{
    delete this->suit;
    delete this->weapon;
}