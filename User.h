#ifndef USER_H
#define USER_H
#include "Combatant.h"

class User : public Combatant {
public:
    User()
        : Combatant(
            100, 100, 15, "PLAYER_NAME",
            {
                {"Sword Strike", "Quick sword attack. 85% hit chance. Damage: 9-15.", Attack, 9, 6, 85},
                {"Heavy Swing", "Powerful overhead swing. 70% hit chance. Damage: 14-20.", Attack, 14, 6, 70},
                {"Second Wind", "Take a moment to recover strength. Heal: 10-16.", Heal, 10, 6, 100}
            }
        ) {}
};
#endif 