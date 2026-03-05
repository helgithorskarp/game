#include "story_nodes.h"

int main(void) {

    /// this is a map where the id is a node id and the node is either a story node, fight node...
    auto node_map = get_story_map();
    Node * current = node_map.at(0).get();
    User user;

    while (current) {
        current = current->run(node_map, user);
    }
}

