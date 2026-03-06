#include "story_nodes.h"
#include "node.h"
#include "common.h"
#include <fstream>
#include <sstream>
#include <optional>


struct saved_game {
    string date;
    string character_type_name;
    string character_id;
    string name;
    int node_id;
};

std::unique_ptr<User> get_user_character(std::string name, std::string choice);
string get_character_choice();
string get_name();
std::optional<saved_game> get_saved_game();


inline const string welcome_screen = R"(
===========================================================================

░▒▓████████▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░ ░▒▓███████▓▒░  ░▒▓██████▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░
      ░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓██▓▒▓██▓▒░
    ░▒▓█▓▒░     ░▒▓████████▓▒░  ░▒▓███████▓▒░  ░▒▓████████▓▒░    ░▒▓█████▓▒░
  ░▒▓█▓▒░          ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓██▓▒▓██▓▒░
░▒▓████████▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░

                        -- FALL OF ICELAND --

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        [ 1 ]  NEW  GAME
        [ 2 ]  LOAD GAME

============================================================================

Choose a option: )";


inline const string choose_character_screen = R"(
===============================================================
                 CHOOSE YOUR CHARACTER CLASS
---------------------------------------------------------------

[ 1 ] C++ Warrior
      Durable melee fighter. Reliable attacks and strong armor.

[ 2 ] Nordic Sniper
      Deadly marksman. High damage and accuracy but less defense.

[ 3 ] Snowball Master
      Master of the frozen north. Fast snowball attacks and solid healing.

===============================================================

Choose your character: )";


inline const string choose_name_screen = R"(
===============================================================
                         ENTER YOUR NAME
---------------------------------------------------------------

What is your name, hero?

===============================================================

Name: )";


inline const string character_ready_screen = R"(
===============================================================
                         THE JOURNEY BEGINS
---------------------------------------------------------------

You are all set {}, great choice picking {} as your fighter class.

Press ENTER to begin/continue your journey.

===============================================================

)";

inline const string load_game_screen = R"(
====================================================
                     LOAD GAME
====================================================

write b for back

{}

----------------------------------------------------
Enter choice: )";


