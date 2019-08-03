import threading
from time import sleep

default_ammo = 1000
default_hold_time = 5
class Weapon:
    def __init__(self, ammo):
        self.ammo = ammo
        self.active = True
        
        
class Suit:
    def __init__(self):
        self.hp = 100
        self.active = True

def disable_active_change(player):
    sleep(default_hold_time)
    player.suit.active = True
    player.suit.active = True
        
class Player:
    def __init__(self, client_addr, ammo = default_ammo):
        self.addr = client_addr
        self.weapon = Weapon(ammo)
        self.suit = Suit()
    def player_hit(damage):
        if(damage < 0):
            return
        self.suit.hp -= damage
        self.weapon.active = False
        self.suit.active = False
        t = threading.Thread(target = disable_active_change, args = (self,))
        t.start()
        #I think it would not wait, it should'nt    
        