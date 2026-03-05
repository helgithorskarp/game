#ifndef ENT_H
#define ENT_H

#include "common.h"


enum ActionType {
    Heal,
    Attack
};

struct Action {
    std::string name;
    std::string description;
    ActionType type;
    int base_amount; /// minimum amount of damage / healing this actino does
    int range; /// additional random range on top of base amoung
    int hit_rate; /// always 100% for healing actions
};


struct ActionResults {
    bool hit;
    int amount;
};



class Entity {
public:
    int health;
    int max_health;
    int armor;
    std::string name;   

    Entity(int h, int mh, int a, std::string n)
        : health(h), max_health(mh), armor(a), name(n) {}

    bool is_alive() { return health > 0; }

    void take_dmg(int dmg) { 
        health = std::max(0, health - dmg);  
    }

    void heal(int amount) { 
        health = std::min(max_health, health + amount); 
    }

    /// A vector of actions each feild has name and description, with hit rate damage etc
    virtual vector<Action> actions() = 0;

    /// returns a string describing what kind of
    virtual string do_action(Entity& other, int id) = 0;

    virtual ~Entity() = default;  
}; 

#endif