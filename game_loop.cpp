#include "game_loop.h"


int main(void) {

    /// Game set up, prompt user to either create a new game or choose a game stored
    bool setup_complete = false;
    string name;
    string character_choice;
    int node_id = 0; /// optional but for stored games they might overwrite the starting point

    while (!setup_complete) {
        string user_asnwer;
        clear_screen();
        cout << welcome_screen;

        std::getline(cin, user_asnwer);

        if (user_asnwer == "1") {
            /// set up screen to create a new game
            name = get_name();
            character_choice = get_character_choice();
            setup_complete = true;

        } else if (user_asnwer == "2") {
            /// gets returned a saved_game struct with the details needed
            /// or nothing if user pressed back
            std::optional<saved_game> game = get_saved_game();
            if (!game) continue;
            name = game->name;
            character_choice = game->character_id;
            node_id = game->node_id;
            setup_complete = true;
        }
    }
    clear_screen();
    std::unique_ptr<User> user_ptr = get_user_character(name, character_choice);
    std::string screen = std::vformat(character_ready_screen,std::make_format_args(name, user_ptr->character_name));
    std::cout << screen;
    string _;
    std::getline(cin, _);

    User& user = *user_ptr;
    user.current_node = node_id;


    /// this is a map where the id is a node id and the node is either a story node, fight node...


    /// HERE THE GAME STARTS RUN A NODE UNTIL YOU GET A NULLPTR RETURNED
    auto node_map = get_story_map();
    Node * current = node_map.at(node_id).get();

    while (current) {
        current = current->run(node_map, user);
    }
}




string get_name() {
    string name;
    while (name.empty())
    {
        clear_screen();
        cout << choose_name_screen;
        std::getline(std::cin, name);
    }

    return name;
}



string get_character_choice() {
    string choice = "";

    while (choice != "1" && 
           choice != "2" && 
           choice != "3") {

        clear_screen();
        cout << choose_character_screen;
        std::getline(cin, choice);
    }

    return choice;
}




std::unique_ptr<User> get_user_character(std::string name, std::string choice) {
    if (choice == "1") {
        return std::make_unique<cpp_warrior>(name);
    } 
    else if (choice == "2") {
        return std::make_unique<nordic_sniper>(name);
    } 
    else if (choice == "3") {
        return std::make_unique<snowball_master>(name);
    }

    return nullptr;
}




/// this function returns returns an optional saved game, depending if user presses back or not
std::optional<saved_game> get_saved_game() {
    /// get all the saved games from the vector
    vector<saved_game> saved_games;

    std::ifstream f("storage.txt");
    string line;
    while(std::getline(f, line)) {
        std::istringstream ss(line);

        std::string name;
        std::getline(ss, name, ';');

        std::string character_name;
        std::getline(ss, character_name, ';');

        std::string node_id;
        std::getline(ss, node_id, ';');

        std::string character_id;
        std::getline(ss, character_id, ';');

        std::string time;
        std::getline(ss, time);

        saved_game game;
        game.character_id = character_id;
        game.character_type_name = character_name;
        game.date = time;
        game.name = name;
        game.node_id = std::stoi(node_id);


        saved_games.push_back(game);
    }

    /// build a formatted string with all the saved games
    string formatted_game_string;
    int i = 1;

    for (auto game : saved_games) {
        formatted_game_string += std::to_string(i++) + ". " + game.name + " (" + game.character_type_name + ") - " + game.date + "\n";
    }

    /// this is the screen that is printed out, with the formatted string inside it
    std::string screen;
    if (!formatted_game_string.empty())
        screen = std::vformat(load_game_screen,std::make_format_args(formatted_game_string));
    else
        screen = std::vformat(load_game_screen,std::make_format_args("You currently have no stored games!"));


    while (true) {
        clear_screen();
        string user_input;

        cout << screen;
        std::getline(cin, user_input);

        if (user_input == "b") {
            return std::nullopt;
        }
        int choice;
        try {
            choice = std::stoi(user_input);
        }
        catch (...) {
            continue;
        }

        if (choice >= 1 && choice <= saved_games.size()) {
            return saved_games[choice - 1];
        }

    }



}