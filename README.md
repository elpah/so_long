## **SO_LONG**

**so_long** is a 2D game built with C and MiniLibX. In this game, the player navigates a custom map, collects items, and reaches the exit to complete the level. This project highlights core programming skills, including map parsing, event handling, and sprite rendering.


## Preview
![solong_prev](https://github.com/user-attachments/assets/570cddc6-6a59-4525-9356-d0056f6b8cf2)


## **Project Overview**

- Map parsing from text files
- Sprite rendering with MiniLibX
- Event handling for player movement
- Memory management and error handling in C

## **Gameplay**

- **Objective**: Guide the character through the map, collect all items, and reach the exit to win.

  
## **Controls**:

  - W - Move Up
  - A - Move Left
  - S - Move Down
  - D - Move Right
  - ESC - Close the game window

## **Game Elements:**
- Player: The main character controlled by the player.
- Items: Collectible objects scattered across the map.
- Exit: The goal that ends the level once all items are collected.

## **Setup & Installation**

1. Clone this Repository:
 ```bash
    git clone git@github.com:elpah/so_long.git
 ```

2. CD in to the directory
 ```bash
    cd so_long
 ```

3. **Compile the Game**: Run make in the root directory to compile the project
   ```bash
    make
   ```

4. **Run the Game**: After compilation, run the executable with a map file:
   ```bash
    ./so_long maps/map.ber
   ```
## **Project Structure

```
so_long/
├── Makefile
├── gnl/
│   ├── *.c
│   ├── *.h
│   └── Makefile
├── printf.c/
│   ├── *.c
│   ├── *.h
│   └── Makefile
├── libft/
│   ├── *.c
│   ├── *.h
│   └── Makefile
├── src/
│   ├── *.c
│   ├── *.h
│   └── Makefile
├── maps/
│   └── *.ber
├── textures/
│   ├── png/
│   │   └── *.png
│   └── xpm/
│       └── *.xpm
└── README.md
```

## **Map Requirements**

- Maps are .ber files formatted as grids, where each character represents a game element:
  **Example of a Valid map**
  ```bash
    111111111111111111  
    110110011000CE0111  
    10P100110011000011  
    100C0C00C1010C0111  
    111111111111111111  
  ```

1 - Wall  
0 - Empty space  
P - Player's starting position  
C - Collectible item  
E - Exit  


## **Dependencies**
  **MiniLibX**: The graphics library used to render the game. Ensure you have it installed and properly linked.  

## **Contributing**

Contributions are welcome! Feel free to open issues or pull requests for improvements and bug fixes.
