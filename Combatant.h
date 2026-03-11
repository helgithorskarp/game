#ifndef COMB_H
#define COMB_H

#include "action_logic.h"
#include "Entity.h"


class Combatant : public Entity {
protected:
    std::vector<Action> _actions; 
public:
    Combatant(int hp, int max_hp, int armor, std::string name, std::vector<Action> actions)
        : Entity(hp, max_hp, armor, name), _actions(std::move(actions)) {}

    std::vector<Action> actions() override {
        return _actions;
    }

    ActionReturn do_action(Entity& other, Action action) override {
        ActionResults results;

        if (action.type == Heal) {
            results = do_heal(*this, action);
        } else if (action.type == Attack) {
            results = do_attack(other, *this, action);
        }

        ActionReturn returnItem;
        returnItem.description = get_action_description(results, action, *this);
        returnItem.results = results;


        return returnItem;
    }
};

#endif