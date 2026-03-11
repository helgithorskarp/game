level up system end of fight loop show menu

fix action description

refine fight loop results

good readme

make armor acutally work + show in fight loop

apply damage formula in do_action, using current level.

ascii art fightloop

rebalance monster random choices


EXTRA FEATURES

save game
leveling up system
story decision game, where story is built with tree, where you can make decisions and fight different monsters based on them
choose a starter class with different attibutes and names
end boss fight
different enemies with different action types
ascii menus rich UI, even though fight loop can maybe be added
more stats (armor)


==OFFICIAL README BEGINS HERE==

1. Player Manual

"ZYRAX - Fall of Iceland" is a turn based JRPG in which you as the player have to defeat the evil overlord, ZYRAX. The player can choose their own name and pick from three warrior classes; C++ Warrior (a durable melee fighter), Nordic Sniper (a deadly marksman), or Snowball Master (a master of the frozen north). After creating their character, the player must navigate through the wastes of the planet Vorthar, encountering a variety of monsters and experiencing a dynamic story depending on which path you pick to ultimately reach ZYRAX. When the player encounters an enemy, they enter a turn based battle with the opponent. The player has a selection of three different moves, which vary between each of the three starting classes. Each move has a different chance to connect, with higher damage moves usually being harder to hit (this principe applies to the player as well as the enemies). After winning a battle, the player becomes more experienced and gains an additional level. This increases their overall damage and max health. When out of combat, the player can quit and choose to save or not. If the player chooses to save and exit the game, they can enter the game again and choose to load the save instead of starting a new game, returning them to the same point in the game.

2. Programmer Manual

There are two main functionalities in the program, the turn based fighting system and traveling through nodes. The game is divided into a tree-like structure, where the player can either read some text describing their adventures (story nodes), choose between two different options (decision nodes) or enter a fight (fight nodes). There are multiple ways forward, but all of them culminate in a final boss battle which, when defeated, shows a final story node. The fights are turn based, with the player having three different actions depending on what class they chose at the beginning. If the player succedes, they continue to the next node and level up (increasing their overall damage). If they fail, they are returned to the node prior to the fight node they were on.

"game_loop.h" and "game_loop.cpp": Sets up the game by having the player choose between starting a new game or loading a save. It handles choosing a name and class if it's a new game.

"node.h" and "node.cpp": Defines the structure of all nodes. Parent class of "story_nodes.h" and "story_nodes.cpp".

"story_nodes.h" and "story_nodes.cpp": Builds all of the nodes in the game. Child class of "node.h" and "node.cpp".

"common.h": Includes models that are commonly used in different files.

"Entity.h": Defines how each entity (the player or monster) is structured (health, max health, damage, etc). It also handles how to store actions taken in combat (action type, result of an action, )







