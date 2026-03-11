#include "common.h"
#include "Entity.h"
#include "action_logic.h"
#include "Combatant.h"


//// here are all the monster defintions

class SnakeMan : public Combatant {
public:
    SnakeMan()
        : Combatant(
            65, 65, 10, "Snake Man",
            {
                {"Bite", "Quick fang strike. 85% hit chance. Good amount of damage", Attack, 8, 4, 85},
                {"Poison Fang", "Venomous bite. 70% hit chance. Great damage, low hit rate", Attack, 10, 5, 70},
                {"Shed Skin", "Regenerate by shedding skin. Heal: 10-15.", Heal, 10, 5, 100}
            }
        ) {level = 1;}
};

class EvilClown : public Combatant {
public:
    EvilClown()
        : Combatant(
            80, 80, 8, "Evil Clown",
            {
                {"Juggle Blades", "Spinning blade toss. 80% hit chance. Good amount of damage", Attack, 9, 5, 80},
                {"Honk Smash", "Brutal hammer swing. 65% hit chance. Insane damage, low hit rate", Attack, 12, 6, 65},
                {"Creepy Laugh", "Restores focus through madness. Heal: 8-13.", Heal, 8, 5, 100}
            }
        ) {level = 1;}
};

class SpaghettiOverlord : public Combatant {
public:
    SpaghettiOverlord()
        : Combatant(
            95, 95, 12, "Spaghetti Overlord",
            {
                {"Noodle Whip", "Lashing noodle strike. 85% hit chance. Good amount of damage", Attack, 8, 5, 85},
                {"Sauce Splash", "Hot sauce burst. 75% hit chance. Insane damage, low hit rate.", Attack, 10, 6, 75},
                {"Pasta Feast", "Devours carbs to recover. Heal: 12-18.", Heal, 12, 6, 100}
            }
        ) {level = 1;}
};

class EvilWitch : public Combatant {
public:
    EvilWitch()
        : Combatant(
            70, 70, 6, "Evil Witch",
            {
                {"Hex Bolt", "Dark magic shot. 85% hit chance. Decent damage.", Attack, 9, 6, 85},
                {"Curse Flame", "Burning curse. 70% hit chance. Increadible damage, low hit rate.", Attack, 12, 7, 70},
                {"Blood Brew", "Bitter potion recovery. Heal: 10-16.", Heal, 10, 6, 100}
            }
        ) {level = 1;}
};

class DarktharTheGuard : public Combatant {
public:
    DarktharTheGuard()
        : Combatant(
            110, 110, 18, "Darkthar the Guard",
            {
                {"Shield Bash", "Heavy bash. 80% hit chance. Decent damage amount", Attack, 10, 6, 80},
                {"Halberd Cleave", "Wide cleave. 65% hit chance. Great damage, low hit rate", Attack, 14, 8, 65},
                {"Stand Firm", "Catches breath behind armor. Heal: 8-14.", Heal, 8, 6, 100}
            }
        ) {level = 1;}
};

class AnnoyingSeagull : public Combatant {
public:
    AnnoyingSeagull()
        : Combatant(
            50, 50, 5, "Annoying Seagull",
            {
                {"Peck", "Sharp beak jab. 90% hit chance. Good damage amount.", Attack, 6, 4, 90},
                {"Deafening Screech", "Ear-splitting scream. 75% hit chance. Legendary damage, low hit rate.", Attack, 10, 6, 75},
                {"Steal Snack", "Steals food and eats it. Heal: 6-12.", Heal, 6, 6, 100}
            }
        ) {level = 1;}
};


/// THE BOSS FIGHT
class Zyrax : public Combatant {
public:
    Zyrax()
        : Combatant(
            160, 160, 20, "Zyrax",
            {
                {"Void Slash", "Rift blade strike. 80% hit chance. High damage, high hit rate", Attack, 14, 8, 80},
                {"Tyrant Beam", "Overcharged beam. 70% hit chance. GOATED damage, low hit rate.", Attack, 18, 10, 70},
                {"Royal Reforge", "Regains power and flesh. Heal: 15-25.", Heal, 15, 10, 100}
            }
        ) {level = 1;}
};