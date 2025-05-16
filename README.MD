UnderHead is a text-based game set in a dark underground world where the player controls a character striving to survive and progress to higher levels. The player encounters various enemies, collects items, and improves their character's abilities. The goal of the game is to overcome all obstacles, defeat enemies, and become the master of the underground.

The game can be played on Linux systems and Mac OS X. For Windows, it is recommended to use Windows Subsystem for Linux.

## How to Play UnderHead

1. **Starting the Game**  
    When you run the downloaded binary file make sure to have file named `items` from GitHub. 

2. **Game Start**  
    After launching the game, the main menu will appear, offering the following options:
    - **NEW GAME**: Start a new game.
    - **LOAD GAME**: Load a saved game.
    - **EXIT**: Exit the game.

    Game is controled with keyboard. Use arrows keys or W/S/A/D keys for navigating in menu. Use enter key for selecting highlited option.

3. **Character Creation**  
    If you choose to start a new game, you can customize your character's attributes:
    - **Name**: Enter your character's name.
    - **Health**: Set the maximum health.
    - **Attack**: Set the attack level.
    - **Defense**: Set the defense level.
    - **Skill Points**: Distribute points among various attributes.

4. **Game Environment**  
    - The game is turn-based, alternating between you and the enemies.
    - You can fight, use items, or check your stats.

5. **Combat System**  
    - Choose the type of attack (normal or ultimate).
    - Follow the keys displayed on the screen and press them in the correct order.
    - Defeat enemies to gain experience and items.

6. **Items**  
    - Collect items that enhance your attributes.
    - Items can be equipped or used during the game.

7. **Saving and Loading the Game**  
    - You can save the current state of game and exit it by pressing Ctrl+C.
    - The saved state is loaded from the file `SaveFile.pam`.

8. **Game Objective**  
    - Your goal is to survive, defeat all enemies, and become the master of the underground.

Enjoy the game and good luck!

## Building the Game from Source

#### Downloading the Source Code
Download the game's source code from the GitHub repository using the command:
```sh
git clone https://github.com/OlinToman/UnderHead.git
```

#### Dependencies
To build the game, you need the following tools and libraries installed:
- **GCC**: A compiler for the C language.
- **Make**: A build automation tool.
- **ncurses**: A library for terminal-based user interfaces.

##### Installation
Use the following command:
```sh
sudo apt update
sudo apt install build-essential libncurses5-dev libncursesw5-dev
```

#### Building the Game
Navigate to the project folder:
```sh
cd UnderHead
```
Run the command:
```sh
make
```

#### Running the Game
After building, run the game using:
```sh
make run
```

#### Cleaning the Project
To remove built files, use:
```sh
make clean
```
For detailed documentation, refer to the [DOC.MD](doc/DOC.MD) file.
