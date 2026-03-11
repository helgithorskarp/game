#include "Entity.h"
#include "common.h"
#include <cmath>

int roll() { return rand() % 100; }

std::string get_action_description(ActionResults actionResults,
                                   Action actionInfo, Entity &player) {
  if (actionInfo.type == Attack) {
    if (actionResults.hit) {
      return player.name + " used " + actionInfo.name + " and dealt " +
             std::to_string(actionResults.amount) + " damage!";
    } else {
      return player.name + " used " + actionInfo.name + " but missed!";
    }
  } else if (actionInfo.type == Heal) {
    return player.name + " used " + actionInfo.name + " and healed " +
           std::to_string(actionResults.amount) + " health!";
  }

  return "";
}

ActionResults do_attack(Entity &victim, Entity& attacker,Action action) {
  if (roll() > action.hit_rate) {
    return {false, 0};
  }

  /// the action it self has some base level damage and range
  /// however the amount of damage it actually does depends on few factors
  /// formula used to calculate damage is:

  /// (base amount + random additional range) * damage_Level_amount / oppenents defence, if hit

  float damage_Level_amount = pow(attacker.damage_level_multiplier, attacker.level -1);
  float defence_level_amount = pow(victim.defence_level_multplier, victim.level -1);
  int additional_damage = roll() % action.range;
  int total_damage = (additional_damage + action.base_amount) * damage_Level_amount / defence_level_amount;
  victim.take_dmg(total_damage);

  return {true, total_damage};
}

ActionResults do_heal(Entity &entity, Action action) {
  int additional_health = roll() % action.range;
  int total_health = additional_health + action.base_amount;
  entity.heal(total_health);

  return {true, total_health};
}
