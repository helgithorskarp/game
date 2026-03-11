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
        "An evil alien known as Zyrax arrived on Earth.\nSearching for a place to conquer and rule,\nhe chose an island of his liking — Iceland.",

        "Without warning, Zyrax ripped Iceland from\nthe Earth and moved it across\nthe stars to his dark planet Vorthar.\nThe land was no longer the same.\nIceland had been torn away from everything\nit once knew and placed in a horrible world\nwhere there was no safety, no prosperity,\nand danger was everywhere.",

        "Strange creatures roamed the landscape.\nThe skies were much darker. The people lived in alot of fear.\nNow a hero must rise and fight through\nthe creatures of Vorthar, defeat Zyrax,\nand free Iceland from the alien planet\nbefore it will be lost forever."
    });

    /// setup here inbetween to set up user name and such who is playing

    nodes[1] = make_unique<StoryNode>(1, 2, vector<string>{
        "A brave warrior named {PLAYER} steps forward.\nWhile many feared the alien conqueror Zyrax,\nthis warrior refuses to stand by while Iceland\nsuffers on the dark planet Vorthar.",

        "Determined to free the island and its people,\n{PLAYER} sets out on a dangerous journey\nto confront Zyrax and his growing army\nof aliens. But the path will not be easy.",

        "Strange monsters roam the land,\nBefore reaching Zyrax himself,\nthe hero must survive the many dangers that are in Iceland."
    });

    nodes[2] = make_unique<DecisionNode>(
        2,
        vector<decision>{
            {"Investigate the ruined city.", 99},
            {"Take the path through the dark forest.", 4}
        },
        "While searching for Zyrax, {PLAYER} reaches a fork in the path.\n"
        "One road leads through the ruined city. It is the shorter route, but it is\n"
        "far more dangerous and likely filled with Zyrax's creatures.\n"
        "The other path leads through the dark forest. It will take longer, but it may be safer\n"
        "The soldier must decide:"
    );

    nodes[4] = make_unique<StoryNode>(4, 5, vector<string>{
        "The player decides to take the safer path\nand walk through the forest.",

        "{PLAYER} spends hours wandering through\nthe trees trying to find the way forward,\nslowly losing health due to exhaustion.",

        "Suddenly, a large creature emerges\nfrom the shadows. It is part of Zyrax's army, the Snake Man.",

        "The creature hisses and prepares to attack.",
        "BATTLE BEGINS!"
    });

    SnakeMan SnakeMan;
    nodes[5] = make_unique<FightNode>(5, SnakeMan, 6, 4);

    nodes[6] = make_unique<StoryNode>(6, 7, vector<string>{
        "The snake man was no match for the brave {PLAYER}.\nYou continue wandering through the forest, but when it gets dark,\nthe cold starts getting to you.\nYou search desperately for a place to stay over the night and suddenly\nyou find a small house where an old lady lives.\nShe offers you food and a place to rest. You tell her about your journey\nand soon go to sleep.",

        "In the middle of the night\nyou suddenly hear a loud sound outside...."
    });

    nodes[7] = make_unique<DecisionNode>(
        7,
        vector<decision>{
            {"Check outside to see what it was", 8},
            {"Go back to sleep", 9}
        },
        "What are you going to do now?"
    );

    nodes[9] = make_unique<StoryNode>(9, 10, vector<string>{
        "You decide the sound is not worth the risk\nand go back to sleep.",

        "When you wake up in the morning,\nthe old lady is nowhere to be found.\nThe house is empty and silent.\nOn a small table you notice\na shining piece of armor.",

        "You take the armor with you\nbefore continuing your journey."
    });

    nodes[8] = make_unique<StoryNode>(8, 11, vector<string>{
        "You slowly open the door and step outside\nto investigate the strange noise.\n You feel something weird, like somebody is watching you.\nas you carefully look around the dark forest,\ntrying to see what could have made the sound.",

        "Suddenly the old lady appears behind you,\nlaughing really loudly.\nIn that moment you realize she was never\nan ordinary old lady at all \nshe is the evil Witch of the Forest.",

        "Before you can react,\nthe witch raises her hands\nand prepares a strike on you.",

        "BATTLE BEGINS!"
    });

    EvilWitch evilWitch;
    nodes[11] = make_unique<FightNode>(11, evilWitch, 10, 7);

    nodes[10] = make_unique<StoryNode>(10, 12, vector<string>{
        "After a strange night in the forest,\n{PLAYER} decides to continue the journey.\nNot long after leaving the small house behind,\nyou finally find your way out of the forest\nand back onto a safer path."
    });

    nodes[99] = make_unique<StoryNode>(99, 100, vector<string>{
        "The player decides to wander\ninto the ruined city.\nAs the soldier walks through the empty streets,\nhe is shocked by how destroyed everything looks.",

        "Suddenly, a large man jumps down\nfrom a ruined building and lands in front of him.\nIt is one of Zyrax's warriors... the Evil Clown.",

        "\"I have heard about your attempts to stop the king,\"\nhe laughs.\"I'm not going to let you do that!\"\nThe Evil Clown attacks!",
        "BATTLE BEGINS!"
    });

    EvilClown evilClown;
    nodes[100] = make_unique<FightNode>(100, evilClown, 101, 99);

    nodes[101] = make_unique<StoryNode>(101, 102, vector<string>{
        "After defeating the Evil Clown,\n{PLAYER} is badly hurt and decides\nto rest in one of the ruined buildings\nto regain strength.",

        "After a good sleep in the abandoned building,\n{PLAYER} wakes up feeling stronger and continues the journey\nto defeat Zyrax."
    });

    nodes[102] = make_unique<DecisionNode>(
        102,
        vector<decision>{
            {"Search the nearby supply depot for useful equipment.", 103},
            {"Continue forward toward Zyrax's fortress without stopping.", 105}
        },
        "Soon {PLAYER} reaches a place where he is unsure where to go\n{PLAYER} must make another decision:"
    );

    nodes[103] = make_unique<StoryNode>(103, 104, vector<string>{
        "{PLAYER} decides to search the nearby supply depot\nfor anything useful.",

        "Far away in the distance, {PLAYER} spots\nsomething unexpected... it looks like delicious food!",

        "Curious and really hungry from the journey,\n{PLAYER} moves closer and finds a fresh plate of spaghetti.",

        "Unable to resist, {PLAYER} takes a big bite.\nBut suddenly the food jumps into the air!",

        "It spins and grows into a massive creature...\nIt is the Spaghetti Overlord!",

        "BATTLE BEGINS!"
    });

    SpaghettiOverlord spaghettiOverlord;
    nodes[104] = make_unique<FightNode>(104, spaghettiOverlord, 107, 103);

    nodes[107] = make_unique<StoryNode>(107, 12, vector<string>{
        "That was a close one! Spaghetti Overlord was\na tougher match than {PLAYER} expected.",

        "The good news is that after killing him,\nthere were delicious spaghetti remains everywhere.",

        "You eat some of it and continue your journey out of the city."
    });


    nodes[105] = make_unique<StoryNode>(105, 106, vector<string>{
        "{PLAYER} believes that he needs to stop Zyrax\nas soon as possible. He has no time to waste!",

        "After making it out of the ruined city, he feels\nthat he is finally getting closer to Zyrax's kingdom.",

        "Suddenly you hear an annoying\nbut yet so familiar sound...\n\nSKRAAAA SKRAA SKRAAAAAA!!",

        "A seagull lands right in front of {PLAYER},\nscreaming painfully loud.",

        "{PLAYER} has hated seagulls all his life.\nThis one is no different.\nIn fact, this one might be the worst one yet.",

        "{PLAYER} decides this seagull must die.",

        "BATTLE BEGINS!"
    });

    AnnoyingSeagull annoyingSeagull;
    nodes[106] = make_unique<FightNode>(106, annoyingSeagull, 12, 105);



    nodes[12] = make_unique<StoryNode>(12, 13, vector<string>{
        "Not far in the distance\nyou can see Zyrax's kingdom.\nIts dark towers rise above the horizon.",

        "But there is one problem...",

        "A guard stands at the only entrance.\nHe quickly notices you and runs toward you,\nblocking your path.",

        "\"STOP!\" he shouts.\n\"No one will enter Zyrax's kingdom\nwhile I guard it!\"\nHe raises his weapon and laughs.",

        "\"I am Drakthar,\nthe Guardian of the Gate.\nIf you wnat to pass…\nyou must KILL me!\"",

        "BATTLE BEGINS!"
    });

    DarktharTheGuard darktharTheGuard;
    nodes[13] = make_unique<FightNode>(13, darktharTheGuard, 14, 12);

    nodes[14] = make_unique<StoryNode>(14, 15, vector<string>{
        "After defeating Drakthar,\nthe Guardian of the Gate,\nyou make your way into Zyrax's kingdom.\nThe dark towers surround you\nas you step deeper into the fortress\nthat has held Iceland captive\non the alien world of Vorthar.",

        "There he is \nthe being who stole the country you love.\nZyrax stands right in front of you,\nwatching calmly as if he has been expecting\nthis moment all along.",

        "This is your chance.\nThe fate of Iceland now rests on your shoulders.\n\nBOSS FIGHT."
    });

    Zyrax zyrax;
    nodes[15] = make_unique<FightNode>(15, zyrax, 16, 14);

    nodes[16] = make_unique<EndNode>(16, vector<string>{
        "With Zyrax finally defeated,\nthe dark ruler of Vorthar collapses\nto the ground.\nHis army all run away scared of you",

        "You search the fortress and soon discover\nthat the President of Iceland,\nHalla Tómasdóttir,\nhas been imprisoned in a guarded cell.\nAfter freeing her,\nyou both begin planning\nhow to return Iceland back to Earth.",

        "Using equipment from Zyrax's own spaceship,\nyou manage to move the entire island of Iceland\nback through space toward Earth.\nBut while adjusting the controls\nyou decide to move it slightly south\ninto warmer waters in the Atlantic Ocean,\nbecause after everything you have been through,\nyou really cannot stand\nthe Icelandic snow anymore.",

        "THE END"
    });

    return nodes;
}