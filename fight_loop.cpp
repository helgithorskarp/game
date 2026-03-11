/// Runs a fight between a user and a monster
/// returns true if user wins, false if user looses
#include "fight_loop.h"

void print_combat_result(string result) {
  if (!result.empty()) {
    std::cout << ">> " << result << "\n";
  }
}

void print_combat_header(User &userPlayer, Combatant &monster) {
  std::cout << "\n--- " << userPlayer.name << " vs " << monster.name
            << " ---\n";
  std::cout << userPlayer.name << " HP: " << userPlayer.health << "/"
            << userPlayer.max_health << "\n";
  std::cout << monster.name << " HP: " << monster.health << "/"
            << monster.max_health << "\n";
  std::cout << "------------------------------------------\n";
}

bool fight_loop(User &userPlayer, Combatant &monster) {
  string m_result = "";
  string p_result = "";

  std::vector<Action> m_actions = monster.actions();
  std::vector<Action> p_actions = userPlayer.actions();

  while (userPlayer.is_alive() && monster.is_alive()) {
    system("clear");
    print_combat_result(p_result);
    print_combat_result(m_result);

    print_combat_header(userPlayer, monster);

    for (int i = 0; i < p_actions.size(); ++i) {
      std::cout << "[" << i + 1 << "] " << p_actions[i].name << " ("
                << p_actions[i].description << ")\n";
    }

    string input = "";
    std::cout << "Choose an action: ";
    std::getline(std::cin, input);

    if (input.empty())
      continue;

    try {
      int choice = std::stoi(input);

      if (choice > 0 && choice <= p_actions.size()) {
        ActionReturn res = userPlayer.do_action(monster, p_actions[choice - 1]);
        p_result = res.description;
      } else {
        p_result = "You hesitated and lost your turn!";
      }
    } catch (...) {
      p_result = "You fumbled your choice and forfeit your turn!";
    }

    if (!monster.is_alive()) {
      system("clear");
      print_combat_header(userPlayer, monster);
      std::cout << "\nVictory! " << monster.name << " has been defeated.\n";
      std::getline(std::cin, input);
      userPlayer.health = userPlayer.max_health;

      return true;
    }

    std::vector<Action> m_actions = monster.actions();
    int enemy_idx = rand() % m_actions.size();

    ActionReturn _Result = monster.do_action(userPlayer, m_actions[enemy_idx]);
    m_result = _Result.description;

    if (!userPlayer.is_alive()) {
      system("clear");
      print_combat_header(userPlayer, monster);
      std::cout << "\nYou have fallen in battle...\n";
      std::getline(std::cin, input);
      userPlayer.health = userPlayer.max_health;
      monster.health = monster.max_health;
      return false;
    }
  }
  return false;
}
