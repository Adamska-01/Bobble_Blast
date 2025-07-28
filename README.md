# Bobble Blast
<table>
  <tr>
    <td><img src="https://img.itch.zone/aW1hZ2UvMTUyMjg4MS8yMjA0MTk0NS5wbmc=/original/YP9U3R.png" alt="Screenshot 1" width="500"/></td>
    <td><img src="https://img.itch.zone/aW1hZ2UvMTUyMjg4MS8yMjA0MjAxNS5wbmc=/original/wNXX3p.png" alt="Screenshot 2" width="500"/></td>
  </tr>
</table>

A Puzzle Bobble-inspired arcade game built with the [DeadFrame2D](https://github.com/Adamska-01/DeadFrame2D) engine. Match and pop bobbles, and challenge your precision and strategy in this fast-paced bobble shooter!

### 🕹️ Gameplay
- **Shoot bobbles** from a rotating cannon!
- **Match 3 or more** of the same color to pop them!
- **Clear the board** before the ceiling drops too low!
- **Be fast** to earn bonus points!
  
### 🗂️ Project Structure
```
Bobble_Blast/
├── App/
│   ├── Assets         # Textures, sounds, fonts
│   ├── include        # Game headers (.h)
│   └── src            # Game logic (.cpp)
├── Scripts/           # Setup scripts  
└── Core               # DeadFrame2D Engine submodule
```


## 🚀 Getting Started

### 1. Generate project files
Run the batch script to generate project files and set up the environment:

| Platform |            Script           |
| -------- | --------------------------- |
| Windows  | `Scripts/Setup-Windows.bat` |
| Linux    | `Scripts/Setup-Linux.sh`    |

This will also update the submodules and add a git hook to retrigger the setup when a branch is checked out.  
(**On Linux** specifically it will pull and build all the SDL repos so that the application can dynamically link them.)

### 2. Build
Use your IDE (Visual Studio, CLion, etc.) or run make/ninja depending on the generated files.


## 🧩 Dependencies
- [DeadFrame2D](https://github.com/Adamska-01/DeadFrame2D) Engine (as a submodule)
  - [SDL2](https://github.com/libsdl-org/SDL) ([Image](https://github.com/libsdl-org/SDL_image), [Mixer](https://github.com/libsdl-org/SDL_mixer), [ttf](https://github.com/libsdl-org/SDL_ttf))
  - [Box2D](https://github.com/erincatto/box2d)
  - [TinyXML2](https://github.com/leethomason/tinyxml2)
  - [nlohmann](https://github.com/nlohmann/json)
 

## 🔗 Links
Check out the [Itch.io page](https://salvg.itch.io/bobble-blast) to download the latest release!
