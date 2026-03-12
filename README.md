==OFFICIAL README BEGINS HERE==

# HOW TO RUN
To run the program you need to navigate to the folder containing the game and run the command `make`. Then, after the game has been set up, you must run `./game` and the game will start!



# GAMEPLAY GUIDE
"ZYRAX - Fall of Iceland" is a turn based JRPG in which you as the player have to defeat the evil overlord, ZYRAX.

The player can choose their own name and pick from three warrior classes; C++ Warrior (a durable melee fighter), Nordic Sniper (a deadly marksman), or Snowball Master (a master of the frozen north). After creating their character, the player must navigate through the wastes of the planet Vorthar by choosing what path to follow, encountering a variety of monsters and experiencing a dynamic story depending on which path you pick to ultimately reach ZYRAX.

When the player encounters an enemy, they enter a turn based battle with the opponent. The player has a selection of three different moves, which vary between each of the three starting classes. Each move has a different chance to connect, with higher damage moves usually being harder to hit (this principe applies to the player as well as the enemies). After winning a battle, the player becomes more experienced and gains an additional level and increased maximum health. They get increased overall damage and defense. If the player loses, they can choose to continue from a previous checkpoint. The player can also peer into the details of the enemy they're fighting.

When out of combat, the player can quit and choose to save or not. If the player chooses to save and exit the game, they can enter the game again and choose to load the save instead of starting a new game, returning them to the same point in the game.


# EXTRA FEATURES

## STORY DECISION BASED GAME
In our implementation we have a decision tree game where the user has to decide his own story. How this exactly works is further explained in the Code description below.

## Leveling Up System
After each fight that the user wins, he levels up one level. At each level his attack and defence become stronger.

## Saving
In each game you can quit manually and save your game. When you load up the game again your run will be stored and you can choose to start right where you left off.

## Starter Classes and Special Attributes
Each user can choose between a couple of starter classes in the beginning of the game. Each has different strengths and weaknesses. Also, all entities have their own special set of attributes with different sets of actions.

## Richer Menu UI
The game clears the menu every time so it does not scroll. It also prints fancy looking ASCII menus.

## More Stats
On top of normal health, entities also store armor. This armor varies between characters and classes.

## Boss Fight
All paths of the story lead to an EPIC boss fight against the evil monster Zyrax. He has more health and better actions than the rest of the monsters. If you successfully beat him, you beat the game.



# Code Description
This code structure can be broken down into 2 different parts: story node logic and entity fighting logic.
---
## Entity Fighting Logic
The `entity.h` file defines the abstract class that all players (users and monsters) use. This class defines basic attributes such as `health`, `max_health`, `level`, `name`, etc. It also defines abstract methods/attributes that must be implemented: an `actions` vector, which defines which special actions this entity has, and a `do_action` function which applies the action defined in `actions`.

`combatant.h` defines the class that inherits from the `Entity` class. This class implements the `do_action` function. Monsters and users inherit from this class and store their own special actions. The `do_action()` function calls functions in `action_logic.cpp`, which ultimately apply the healing/damage.

`monsters.h` and `user.h` implement the classes that inherit from `Combatant`. Each monster/user declares its own set of special actions, how much damage they do, range, hit rate, etc.
The `fight_loop` file implements the whole fighting scene. It takes in two references to entities (user and a monster) and repeatedly prompts the user for an action, applies the action (calling the `do_action` function mentioned above), until either the monster or the user dies. When a user wins a fight, their health is kept for future fights, or healed if very low, and their level and max health increase. The monster logic is very simple, randomly choosing an attack but is guaranteed to heal every 3rd round to incentivize strategy.

---


## Node Logic
`node.h` defines all the different nodes that exist. The base class is `Node`, which is an abstract class that states that anyone who inherits from `Node` must implement a function called `run()`.

There are a few different types of nodes that inherit from `Node`:
- **DecisionNode** – stores a struct of decisions for the user to pick from  
- **RestNode** – not currently used  
- **StoryNode** – stores a vector of text to print out  
- **FightNode** – stores a monster reference that the user is supposed to fight  
- **EndNode** – the final node in the story

`node.cpp` actually implements the functionality that is run in each node (the `run()` function).
For example, the `run()` function in `StoryNode` repeatedly prints the text stored in the vector when the user presses enter, then returns the ID of the next node.
`FightNode` calls the `fight_loop` function in `fight_loop.cpp` and returns `true` if the user wins and `false` if the user loses.
etc.


---
`story_nodes.cpp` is where all the magic happens, it manually maps together the story. It creates nodes and declares what nodes are connected to what. Reading through this file might be a bit confusing but essentially what it does is the following:
Node = storyNode(Some text to print out, what node to jump to after this text has printed)
Node = fightNode(Reference to the monster being fought, what node to go to on win, what node to go to on loss)
node = decisionNode(A vector of decisions to print out, what node to go to on each decision)

## Game Flow
The whole game logic basically works as follows:
```
Current = Beginning_node
while we are not finished:
  current = run code in current node (run() function)
```

At each run, as you can see in the extra features, you can store the results. These results are saved in the `storage.txt` file. Every line in this file stores various information such as the name of the player, what level he was at, what node he was located at when he quit...


`game_loop.cpp` has the `main()` function of this program. The logic there is printing the base menu, allowing the user to either start a new game or load an old game. If an old game is loaded it reads all entries from the storage file and allows the user to choose. After all of this, the game loop shown above takes place.

<details>
    <summary>Notes for authors, please ignore</summary>
level up system end of fight loop show menu, show cool menu congratualting for leveling up, and stuff...

fix action description DONE

refine fight loop results

good readme

make armor acutally work + show armor in fight loop /// DONE , but still not shown in fight loop

apply damage formula in do_action, using current level. // DONE

ascii art fightloop

Add in fight loop that after each win max health increases by 5 or something


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
</details>
