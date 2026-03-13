#include "node.h"
#include <unordered_map>
#include "common.h"
#include <memory>
#include "User.h"
#include "fight_loop.h"
#include <cstdlib>
#include <fstream>
#include <regex>
void clear_screen();
void store_results(Node& node, User& user);




const string Header = R"(
====================================================
            ZYRAX: FALL OF ICELAND
====================================================

)";



void input_name(string& text, const string& name) {
    std::string string_to_replace = "{PLAYER}";

    while (text.contains(string_to_replace)) {
        size_t pos = text.find(string_to_replace);
        text.replace(pos, string_to_replace.length(), name);
    }
}
Node* StoryNode::run(std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) {
    clear_screen();
    std::cout << Header;
    std::cout << "Name: " << user.name << ", Health: " << user.health << "/" << user.max_health << " Armor: " << user.armor << ", Level: " << user.level << "\n";
    std::cout << "Press ENTER to continue the Story, or q to quit\n\n";
    for (auto& line : text) {
        input_name(line, user.name);
        std::cout << line << "\n";
        std::string _;
        std::getline(std::cin, _);

        if (_ == "q") {
            user.current_node = id;
            store_results(*this, user);
            return nullptr;
        }
    }

    return nodes.at(id_next).get();  
}


Node* FightNode::run(std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) {
    clear_screen();
    bool win = fight_loop(user, this->enemy);
    if (win) {
        return nodes.at(win_next).get();  
    } else {
        return nodes.at(lose_next).get();
    }

}

Node* DecisionNode::run(std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) {
    string choice;
    while (true) {
        clear_screen();
        std::cout << Header;
        std::cout << "You can write q to quit\n\n";
        int i = 1;
        input_name(text, user.name);
        cout << text << "\n\n";
        for (auto decision : decisions) {
            cout << "   [ " << i << " ] " << decision.text << '\n';
            i++;
        }

        cout << "\nChoose a option: ";
        std::getline(cin, choice);

        if (choice == "q") {
            user.current_node = id;
            store_results(*this, user);
            return nullptr;
        }

        if (choice.length() != 1) continue;
        if (!isdigit(choice[0])) continue;

        if (std::stoi(choice) >= 1 && std::stoi(choice) < i) break;
    }

    return nodes.at(decisions[std::stoi(choice) - 1].node_id).get();
}


Node* EndNode::run(std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) {
    clear_screen();
    std::cout << Header;
    std::cout << "Press ENTER to continue the Story, or q to quit\n\n";
    for (auto& line : text) {
        input_name(line, user.name);
        std::cout << line << "\n";
        std::string _;
        std::getline(std::cin, _);
    }

    return nullptr;  
}


void clear_screen() {
    system("clear");
}



void store_results(Node& node, User& user) {
    /// ask user if he want to store the results of this run so he can go back to it later
    bool valid = false;

    while (!valid) {
        clear_screen();
        cout << Header;
        cout << R"(
Do you want to save the results of this run?

[ 1 ] Yes
[ 2 ] No
----------------------------------------------------
Choose an option:)";
        
            std::string choice;
            std::getline(std::cin, choice);

            if (choice == "1") {
                break;
            }

            if (choice == "2") {
                return;
            }}



    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    auto time = std::ctime(&now_c);
    std::ofstream file("storage.txt", std::ios::app);

    file << user.name << ";" << user.character_name << ";" << node.id << ";" << user.character_id << ";" << user.level << ";" << time;
    file.close();
}