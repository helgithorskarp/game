#include "node.h"
#include <unordered_map>
#include "common.h"
#include <memory>
#include "User.h"
#include "fight_loop.h"
#include <cstdlib>
void clear_screen();
Node* StoryNode::run(std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) {
    clear_screen();
    for (const auto& line : text) {
        std::cout << line << "\n";
        std::string _;
        std::getline(std::cin, _);
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
    clear_screen();
    int i = 1;
    cout << text << '\n';
    for (auto decision : decisions) {
        cout << i << " " << decision.text << '\n';
        i++;
    }
    int choice;

    cout << "\nChoose a option!\n";
    cin >> choice;

    return nodes.at(decisions[choice - 1].node_id).get();
}


Node* EndNode::run(std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) {
    for (const auto& line : text) {
        std::cout << line << "\n";
        std::string _;
        std::getline(std::cin, _);
    }

    return nullptr;  
}


void clear_screen() {
    system("clear");
}
