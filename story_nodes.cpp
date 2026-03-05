#include "node.h"
#include <unordered_map>
#include "common.h"
#include <memory>
#include "monsters.h"
using std::make_unique;



/// basically just a long file building every single node in the story :/

std::unordered_map<int, std::unique_ptr<Node>> get_story_map() {
    std::unordered_map<int, std::unique_ptr<Node>> nodes;


nodes[0] = make_unique<StoryNode>(0, 1, vector<string>{
"An evil alien known as Zyrax arrived on Earth. Searching for a place to conquer and rule, he chose an island of his liking — Iceland.",

"Without warning, Zyrax ripped Iceland from the Earth itself and transported it across the stars to his dark planet Vorthar. The land was no longer the same. Iceland had been torn away from everything it once knew and placed in a hostile world where there was no safety, no prosperity, and danger lurked everywhere.",

"Strange creatures roamed the landscape. The skies were darker. The people lived in fear. Now a hero must rise and fight through the creatures of Vorthar, defeat Zyrax, and free Iceland from the alien planet before it is lost forever."
});

/// setup here inbetween to set up user name and such who is playing

nodes[1] = make_unique<StoryNode>(1, 2, vector<string>{
"A brave warrior named {PLAYER} steps forward. While many feared the alien conqueror Zyrax, this warrior refuses to stand by while Iceland suffers on the dark planet Vorthar.",

"Determined to free the island and its people, {PLAYER} sets out on a dangerous journey to confront Zyrax and his growing army of alien creatures. But the path will not be easy.",

"Strange monsters roam the land, twisted by the energy of Vorthar. Before reaching Zyrax himself, the hero must survive the many dangers that guard his fortress.",
});

nodes[2] = make_unique<DecisionNode>(
    2,
    vector<decision>{
        {"Investigate the ruined city.", 99},
        {"Take the path through the dark forest.", 4}
    },
    "While searching for Zyrax, {PLAYER} reaches a fork in the path. The soldier must decide:"
);

    nodes[4] = make_unique<StoryNode>(4, 5, vector<string>{
    "The player decides to take the safer path and walk through the forest.",

    "{PLAYER} spends hours wandering through the dense trees trying to find the way forward, slowly losing health due to exhaustion.",

    "Suddenly, a large creature emerges from the shadows. It is part of Zyrax's army — the Snake Man.",

    "The creature hisses and prepares to attack.",
     "BATTLE BEGINS!"
    });

    SnakeMan SnakeMan;
    nodes[5] = make_unique<FightNode>(5, SnakeMan, 6, 4);

    nodes[6] = make_unique<StoryNode>(6, 7, vector<string>{
    "The snake man was no match for the brave {PLAYER}. You continue wandering through the forest, but when it gets dark, the cold starts getting to you. You search desperately for a place to stay over the night and suddenly you find a small house where an old lady lives. She offers you food and a place to rest. You tell her about your journey and soon go to sleep.",

    "In the middle of the night you suddenly hear a loud sound outside...."
    });


    nodes[7] = make_unique<DecisionNode>(
    7,
    vector<decision>{
        {"Check outside to see what it was", 8},
        {"Go back to sleep", 9}
    },
    "The snake man was no match for the brave {PLAYER}. You continue wandering through the forest, but when it gets dark, the cold starts getting to you. You search desperately for a place to stay over the night and suddenly you find a small house where an old lady lives. She offers you food and a place to rest. You tell her about your journey and soon go to sleep.\n\nIn the middle of the night you suddenly hear a loud sound outside.\n\nWhat are you going to do now?"
);

    nodes[9] = make_unique<StoryNode>(9, 10, vector<string>{
    "You decide the sound is not worth the risk and go back to sleep.",

    "When you wake up in the morning, the old lady is nowhere to be found. The house is empty and silent. On a small table you notice a shining piece of armor.",

    "You take the armor with you before continuing your journey."
    });


    nodes[8] = make_unique<StoryNode>(8, 11, vector<string>{
    "You slowly open the door and step outside to investigate the strange noise. The cold night air hits your face as you carefully look around the dark forest, trying to see what could have made the sound.",

    "Suddenly the old lady appears behind you, laughing loudly. In that moment you realize she was never an ordinary old lady at all — she is the evil Witch of the Forest.",

    "Before you can react, the witch raises her hands and prepares to strike.",

    "BATTLE BEGINS!"
    });

    EvilWitch evilWitch;
    nodes[11] = make_unique<FightNode>(11, evilWitch, 10, 7);

    nodes[10] = make_unique<StoryNode>(10, 12, vector<string>{
    "After a strange night in the forest, {PLAYER} decides to continue the journey. Not long after leaving the small house behind, you finally find your way out of the forest and back onto a safer path."
    });


    nodes[99] = make_unique<StoryNode>(99, 100, vector<string>{
    "The player decides to wander into the ruined city. As the soldier walks through the empty streets, he is shocked by how destroyed everything looks.",

    "Suddenly, a large figure jumps down from a ruined building and lands in front of him. It is one of Zyrax's warriors — the **Evil Clown**.",

    "\"I have heard about your attempts to stop the king,\" he laughs. \"I'm not going to let you do that!\" The Evil Clown attacks!",
     "BATTLE BEGINS!"
    });

    EvilClown evilClown;
    nodes[100] = make_unique<FightNode>(100, evilClown, 101, 99);

    nodes[101] = make_unique<StoryNode>(101, 12, vector<string>{
    "After defeating the Evil Clown, {PLAYER} is badly hurt and decides to rest in one of the ruined buildings to regain strength.",

    "After a good sleep in the abandoned building, {PLAYER} wakes up feeling stronger and continues the journey to defeat Zyrax."
    });


    nodes[102] = make_unique<DecisionNode>(
        102,
        vector<decision>{
            {"Search the nearby supply depot for useful equipment.", 103},
            {"Continue forward toward Zyrax's fortress without stopping.", 12}
        },
        "Soon {PLAYER} reaches a damaged crossroads just outside the ruins. The soldier must make another decision:"
    );



nodes[12] = make_unique<StoryNode>(12, 13, vector<string>{
    "Not far in the distance you can see Zyrax's kingdom. Its dark towers rise above the horizon.",

    "But there is one problem...",

    "A guard stands at the only entrance. He quickly notices you and runs toward you, blocking your path.",

    "\"Halt!\" he shouts. \"None may enter Zyrax's kingdom while I stand guard!\" He raises his weapon and smirks.",

    "\"I am Drakthar, the Guardian of the Gate. If you wish to pass… you must defeat me!\"",

    "BATTLE BEGINS!"
});

    DarktharTheGuard darktharTheGuard;
    nodes[13] = make_unique<FightNode>(13, darktharTheGuard, 14, 12);

    nodes[14] = make_unique<StoryNode>(14, 15, vector<string>{
"After defeating Drakthar, the Guardian of the Gate, you make your way into Zyrax's kingdom. The dark towers surround you as you step deeper into the fortress that has held Iceland captive on the alien world of Vorthar.",

"There he is — the being who stole the country you love. Zyrax stands before you, watching calmly as if he has been expecting this moment all along.",

"This is your chance. The fate of Iceland now rests on your shoulders.\n\nBOSS FIGHT."
});


    Zyrax zyrax;
    nodes[15] = make_unique<FightNode>(15, zyrax, 16, 14);


    nodes[16] = make_unique<EndNode>(16, vector<string>{
"With Zyrax finally defeated, the dark ruler of Vorthar collapses to the ground. His army scatters across the planet and the dark fortress grows silent.",

"You search the fortress and soon discover that the President of Iceland, Halla Tómasdóttir, has been imprisoned in a guarded cell. After freeing her, you both begin planning how to return Iceland back to Earth.",

"Using equipment from Zyrax's own spaceship, you manage to move the entire island of Iceland back through space toward Earth. But while adjusting the controls you decide to move it slightly south into warmer waters in the Atlantic Ocean, because after everything you have been through, you really cannot stand the Icelandic snow anymore.",

"THE END"
});
    return nodes;



}