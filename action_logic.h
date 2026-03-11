#include "Entity.h"

std::string get_action_description(ActionResults actionResults, Action actionInfo, Entity& player);
ActionResults do_attack(Entity &victim, Entity& attacker,Action action);
ActionResults do_heal(Entity& entity, Action action);