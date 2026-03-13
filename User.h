#ifndef USER_H
#define USER_H
#include "Combatant.h"
#include "common.h"


namespace character_id {
    const string cpp_warrior = "1";
    const string nordic_sniper = "2";
    const string snowball_master = "3";
};

namespace character_names {
    const string cpp_warrior = "C++ Warrior";
    const string nordic_sniper = "Nordic Sniper";
    const string snowball_master = "Snowball Master";
};


class User : public Combatant {
public:
    User(string name, std::vector<Action> actions, string character_name, string character_id)
        : Combatant(
            100, 100, 15, name, actions
        ), character_name(character_name), character_id(character_id) {level = 1;}

    int current_node = 0; /// stores where we are so we can quickly store old progress
    string character_id;
    string character_name;
};


class cpp_warrior : public User {
public:
    cpp_warrior(std::string name)
        : User(name, {
            {"Pointer Strike", "Precise low-level strike. 85% hit chance. Good amount of damage!", Attack, 9, 6, 85},
            {"Template Smash", "Heavy templated swing. 70% hit chance. Legendary damage, low hit rate!", Attack, 14, 6, 70},
            {"Memory Management", "Recover lost health through discipline. Heal: 10-16.", Heal, 10, 6, 100}
        }, character_names::cpp_warrior, character_id::cpp_warrior)
    {level = 1;}
};


class nordic_sniper : public User {
public:
    nordic_sniper(std::string name)
        : User(name, {
            {"Longshot", "Precise rifle shot. 90% hit chance. Does good amount of damage!", Attack, 10, 6, 90},
            {"Headshot Attempt", "Carefully aimed shot. 65% hit chance. low accuracy, INSANE damage", Attack, 16, 8, 65},
            {"Steady Breath", "Calm focus restores health.", Heal, 8, 6, 100}
        }, character_names::nordic_sniper, character_id::nordic_sniper)
    {level = 1;}
};


class snowball_master : public User {
public:
    snowball_master(std::string name)
        : User(name, {
            {"Packed Snowball", "Tightly packed snowball throw. 85% hit chance. Decent amount of damage.", Attack, 8, 6, 85},
            {"Frozen Barrage", "Rapid volley of icy snowballs. 75% hit chance. Low hit rate, GREAT damage.", Attack, 12, 6, 75},
            {"Cold Recovery", "Draw strength and heal up from the cold.", Heal, 10, 8, 100}
        }, character_names::snowball_master, character_id::snowball_master)
    {level = 1;}
};

#endif 
