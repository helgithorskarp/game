#include "Entity.h"
#include "common.h"


int roll() {return rand() % 100;}


std::string get_action_description(ActionResults actionResults, Action actionInfo, Entity& player) {
    if (actionInfo.type == Attack) {
        if (actionResults.hit) {
            return player.name + " used " + actionInfo.name + " and dealt " + std::to_string(actionResults.amount) + " damage!";
        } else {
            return player.name + " used " + actionInfo.name + " but missed!";
        }
    } 
    else if (actionInfo.type == Heal) {
        return player.name + " used " + actionInfo.name + " and healed " + std::to_string(actionResults.amount) + " health!";
    }

    return "";
}

ActionResults do_attack(Entity& victim, Action action) {
    if (roll() > action.hit_rate) {
        return {false, 0};
    }

    int additional_damage = roll() % action.range;
    int total_damage = additional_damage + action.base_amount;
    victim.take_dmg(total_damage);

    return {true, total_damage};
}


ActionResults do_heal(Entity& entity, Action action) {
    int additional_health = roll() % action.range;
    int total_health = additional_health + action.base_amount;
    entity.heal(total_health);

    return {true, total_health};
}

