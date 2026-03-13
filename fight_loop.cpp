/// Runs a fight between a user and a monster
/// returns true if user wins, false if user looses
#include "fight_loop.h"

void print_combat_result(string result) {
  if (!result.empty())
    std::cout << ">> " << result << "\n";
}

void print_combat_header(User &userPlayer, Combatant &monster) {
  std::cout << "\n======== " << userPlayer.name << " vs " << monster.name
            << " ========\n\n";
  std::cout << userPlayer.name << " HP: " << userPlayer.health << "/"
            << userPlayer.max_health <<  " Armor: " << userPlayer.armor << "\n";
  std::cout << monster.name << " HP: " << monster.health << "/"
            << monster.max_health <<  " Armor: " << monster.armor << "\n\n";
  std::cout << "====================================================\n\n";
}

bool fight_loop(User &userPlayer, Combatant &monster) {
  string m_result = "";
  string p_result = "";
  string garb = "";
  int p_entry_health = userPlayer.health;
  int m_heal_count = 0;

  std::vector<Action> m_actions = monster.actions();
  std::vector<Action> p_actions = userPlayer.actions();

  // Main fight loop
  while (userPlayer.is_alive() && monster.is_alive()) {
    // If there are results, print them
    system("clear");
    print_combat_header(userPlayer, monster);

    for (int i = 0; i < p_actions.size(); ++i) {
      std::cout << "[" << i + 1 << "] " << p_actions[i].name << " ("
                << p_actions[i].description << ")\n";
    }
    std::cout << "\n[i] Enemy information\n";

    // Grab user action, ignore whitespace.
    // Do fumble if "invalid" input
    // Otherwise do selected action
    string input = "";
    std::cout << "\nChoose an action: ";
    std::getline(std::cin, input);

    if (input.empty())
      continue;

    try {
      if (input == "i") {
        system("clear");
        print_combat_header(userPlayer, monster);
        for (int i = 0; i < m_actions.size(); ++i) {
          std::cout << ">> " << m_actions[i].name << " ("
                    << m_actions[i].description << ")\n";
        }
        std::cout << "\nPress ENTER to continue..\n";
        std::getline(std::cin, garb);
        continue;
      }
      int choice = std::stoi(input);

      if (choice > 0 && choice <= p_actions.size()) {
        ActionReturn p_actionres =
            userPlayer.do_action(monster, p_actions[choice - 1]);
        p_result = p_actionres.description;
      } else {
        p_result = "You hesitated and lost your turn!";
      }
    } catch (...) {
      p_result = "You fumbled your choice and forfeit your turn!";
    }
    system("clear");
    print_combat_header(userPlayer, monster);
    print_combat_result(p_result);
    std::getline(std::cin, garb);
    system("clear");
    print_combat_header(userPlayer, monster);

    // Win condition
    if (!monster.is_alive()) {
      system("clear");
      print_combat_header(userPlayer, monster);
      std::cout << "\nVictory! " << monster.name << " has been defeated!\n";
      std::cout << "\nPress ENTER to continue..\n";
      std::getline(std::cin, garb);
      userPlayer.level += 1;
      userPlayer.max_health += (rand() % 5) + 5;
      if (userPlayer.health < (userPlayer.max_health / 3)) {
        userPlayer.health = userPlayer.max_health / 3;
      }
      return true;
    }

    // Do monster action.
    // Very simple random choice
    // Monster cannot heal consecutive rounds
    // but will always heal every 3rd rounds
    int enemy_idx;
    if (m_heal_count > 1) {
      enemy_idx = 2;
      m_heal_count = 0;
    } else {
      enemy_idx = rand() % (m_actions.size() - 1);
      ++m_heal_count;
    }

    ActionReturn m_actionres =
        monster.do_action(userPlayer, m_actions[enemy_idx]);
    m_result = m_actionres.description;

    system("clear");
    print_combat_header(userPlayer, monster);
    print_combat_result(m_result);
    std::getline(std::cin, garb);

    // Loss condition
    if (!userPlayer.is_alive()) {
      system("clear");
      print_combat_header(userPlayer, monster);
      std::cout << "\nYou have fallen in battle...\n";
      std::cout << "\nPress ENTER to continue from checkpoint\n";
      std::getline(std::cin, input);
      userPlayer.health = p_entry_health;
      monster.health = monster.max_health;
      return false;
    }
  }
  return false;
}
