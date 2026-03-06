#ifndef NODE_H
#define NODE_H

#include "common.h"
#include "Combatant.h"
#include "User.h"
#include <unordered_map>


enum class NodeType {
    Story,
    Decision,
    Rest,
    Fight,
    End
};

struct decision {
    string text;
    int node_id;
};



class Node {
public:
    int id;
    NodeType type;


    Node(int _id, NodeType _type) : id(_id), type(_type) {}
    virtual ~Node() = default;
    virtual Node* run( std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) = 0;
};

void clear_screen();

class StoryNode : public Node {
public:
    vector<string> text;
    int id_next;

    StoryNode(int id, int _next, vector<string> _text)
        : Node(id, NodeType::Story), text(_text), id_next(_next) {}

    Node* run( std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) override;

 };

class DecisionNode : public Node {
public:
    vector<decision> decisions;
    string text;

    DecisionNode(int id, vector<decision> _decisions, string _text)
        : Node(id, NodeType::Decision), decisions(_decisions), text(_text) {}

    Node* run( std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) override;
};

class RestNode : public Node {
public:
    vector<string> text;
    int heal_amount;
    int id_next;

    RestNode(int id, int heal, int _next, vector<string> _text)
        : Node(id, NodeType::Rest), text(_text), heal_amount(heal), id_next(_next) {}

    Node* run( std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) override;
};

class FightNode : public Node {
public:
    Combatant enemy;
    int win_next;
    int lose_next;

    FightNode(int id, Combatant& enemy, int win, int lose)
        : Node(id, NodeType::Fight), enemy(enemy), win_next(win), lose_next(lose) {}

    Node* run( std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) override;
};

class EndNode : public Node {
public:
    vector<string> text;

    EndNode(int id, vector<string> _text)
        : Node(id, NodeType::End), text(_text) {}

    Node* run( std::unordered_map<int, std::unique_ptr<Node>>& nodes, User& user) override;
};


#endif