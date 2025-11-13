# Cub3D - A Raycasting Game Engine

<div align="center">

![Cub3D Logo](https://img.shields.io/badge/Cub3D-Raycasting_Engine-blue?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c)
![Graphics](https://img.shields.io/badge/Graphics-MLX42-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)

*A 3D game engine inspired by Wolfenstein 3D, built from scratch using raycasting techniques*

[Features](#features) • [Installation](#installation) • [Usage](#usage) • [Documentation](#documentation) • [Architecture](#architecture)

</div>

---

## 🎯 Overview

Cub3D is a **3D game engine** that renders a first-person perspective view from a 2D map using the **raycasting** technique made famous by id Software's Wolfenstein 3D (1992). This project demonstrates advanced graphics programming concepts including:

- Real-time 3D rendering from 2D data
- Digital Differential Analysis (DDA) algorithm
- Texture mapping and pixel manipulation
- Efficient collision detection
- Frame-based game loop architecture

### What is Raycasting?

Raycasting is a rendering technique that creates a 3D perspective in a 2D world by casting rays from the player's position and calculating wall distances. Unlike modern 3D engines that use polygon rendering, raycasting:

- ✅ Runs efficiently with minimal computational resources
- ✅ Provides convincing 3D perspective using only 2D mathematics
- ✅ Enables fast rendering by casting one ray per screen column
- ✅ Was revolutionary in early 1990s game development

---

## ✨ Features

### Core Features

- **🎮 Full 3D Rendering**
  - Real-time raycasting engine at 60 FPS
  - Textured walls with different textures per direction (N/S/E/W)
  - Customizable floor and ceiling colors
  - Smooth wall rendering without fish-eye distortion

- **🗺️ Advanced Map System**
  - Custom `.cub` map file format
  - Flood-fill validation for map closure
  - Support for irregular map shapes
  - Comprehensive error detection and reporting

- **🕹️ Smooth Controls**
  - WASD movement system
  - Strafing with collision detection
  - Arrow key rotation
  - Frame-independent movement speed

- **🖼️ Texture Management**
  - PNG texture loading via MLX42
  - Automatic fallback textures for missing files
  - Efficient texture-to-pixel mapping
  - Support for 64x64 texture resolution

- **💾 Memory Safety**
  - No memory leaks (Valgrind verified)
  - Proper cleanup on all exit paths
  - Defensive programming practices
  - Robust error handling

---

## 🛠️ Technology Stack

| Component | Technology | Purpose |
|-----------|-----------|---------|
| **Language** | C (C99) | Core implementation |
| **Graphics Library** | MLX42 | Window management and rendering |
| **Graphics API** | OpenGL (via MLX42) | Hardware-accelerated rendering |
| **Build System** | Make | Compilation automation |
| **Debugging** | Valgrind, GDB | Memory and runtime debugging |
| **Version Control** | Git | Source code management |

### Dependencies

- **MLX42**: Modern graphics library for 42 projects
  - OpenGL-based
  - Cross-platform support (Linux/macOS)
  - Hardware acceleration
  
- **System Libraries**:
  - `math.h` - Trigonometry and mathematical operations
  - `stdlib.h` - Memory allocation
  - `unistd.h` - File operations
  - `fcntl.h` - File control

---

## 📥 Installation

### Prerequisites

```bash
# macOS
brew install cmake glfw

# Ubuntu/Debian
sudo apt-get update
sudo apt-get install build-essential libglfw3-dev cmake

# Fedora
sudo dnf install glfw-devel cmake
```

### Clone and Build

```bash
# Clone the repository
git clone https://github.com/yourusername/cub3d.git
cd cub3d

# Build MLX42 (if not already installed)
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build
cmake --build build
cd ..

# Build Cub3D
make

# Clean build (if needed)
make fclean
make re
```

### Compilation Flags

The project uses strict compilation flags for code quality:

```makefile
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -I./inc -I./MLX42/include
LDFLAGS = -L./MLX42/build -lmlx42 -lglfw -lm
```

---

## 🚀 Usage

### Basic Usage

```bash
./cub3D maps/valid/simple_valid.cub
```

### Command Line Arguments

```bash
./cub3D <map_file.cub>
```

**Parameters:**
- `map_file.cub` - Path to a valid `.cub` configuration file

**Example:**
```bash
./cub3D maps/valid/test_map.cub
```

### Exit Codes

| Code | Meaning |
|------|---------|
| `0` | Success |
| `1` | Error (invalid arguments, file not found, parsing error, etc.) |

---

## 🗺️ Map File Format

### File Structure

A `.cub` file consists of three sections:

```
1. TEXTURE PATHS    (NO, SO, WE, EA)
2. COLORS           (F, C)
3. MAP              (Grid of 1, 0, N/S/E/W)
```

### Complete Example

```
NO ./textures/N/BRICK_2B.PNG
SO ./textures/S/BRICK_3B.PNG
WE ./textures/W/BRICK_3D.PNG
EA ./textures/E/BRICK_1A.PNG

F 220,100,0
C 225,30,0

111111111
100000001
100N00001
100000001
111111111
```

### Configuration Elements

#### 1. Texture Identifiers

```
NO <path>    North-facing wall texture
SO <path>    South-facing wall texture
WE <path>    West-facing wall texture
EA <path>    East-facing wall texture
```

**Requirements:**
- Must be PNG format (`.png` or `.PNG`)
- Recommended size: 64×64 pixels
- Path can be relative or absolute

**Example:**
```
NO ./textures/north_wall.png
SO ./textures/south_wall.png
WE ./textures/west_wall.png
EA ./textures/east_wall.png
```

#### 2. Color Definitions

```
F <R>,<G>,<B>    Floor color (RGB 0-255)
C <R>,<G>,<B>    Ceiling color (RGB 0-255)
```

**Requirements:**
- Values must be integers 0-255
- Comma-separated (spaces optional)

**Example:**
```
F 220,100,0      Floor: Orange
C 135,206,235    Ceiling: Sky blue
```

#### 3. Map Grid

**Valid Characters:**

| Character | Meaning |
|-----------|---------|
| `1` | Wall |
| `0` | Empty space (walkable) |
| `N` | Player starting position facing North |
| `S` | Player starting position facing South |
| `E` | Player starting position facing East |
| `W` | Player starting position facing West |
| ` ` (space) | Empty (for irregular shapes) |

**Map Requirements:**
- Must be surrounded by walls (`1`) or spaces
- Must contain exactly **one** player start position (N/S/E/W)
- All walkable areas must be enclosed
- Can be irregular shapes (using spaces for padding)

**Example Maps:**

**Simple Rectangular:**
```
111111
100001
100N01
111111
```

**Irregular Shape:**
```
        1111111111
        1000000001
        1000N00001
111111111000000001
100000000000000001
110000000000000001
 1111111111111111
```

### Validation Rules

The parser validates:

✅ File extension is `.cub`  
✅ All 4 textures are defined (no duplicates)  
✅ Both colors are defined (no duplicates)  
✅ RGB values are in range [0-255]  
✅ Texture files exist and are readable  
✅ Map contains exactly one player  
✅ Map is closed (flood-fill algorithm)  
✅ All map characters are valid  

---

## 🎮 Controls

### Keyboard Layout

```
Movement:
  W          Move forward
  S          Move backward
  A          Strafe left
  D          Strafe right

Rotation:
  ←          Rotate view left
  →          Rotate view right

System:
  ESC        Exit game
```

### Movement System

**Speed Constants:**
```c
MOVE_SPEED   = 0.05 units/frame  (3 units/second at 60 FPS)
ROTATE_SPEED = 0.12 radians/frame (~7 degrees/frame)
```

**Features:**
- ✅ Smooth, frame-independent movement
- ✅ Collision detection with 0.2-unit buffer
- ✅ Wall sliding (can move along walls diagonally)
- ✅ Separate X/Y collision for corner handling

---

## 🏗️ Architecture

### Project Structure

```
cub3d/
├── inc/
│   ├── cub3d.h              Main header with structures
│   └── cub3d_bonus.h        Bonus features
│
├── src_mandatory/
│   ├── main.c               Entry point
│   ├── main_utils.c         Initialization helpers
│   │
│   ├── parsing/             FILE PARSING SYSTEM
│   │   ├── parse_file.c          Read .cub file
│   │   ├── parse_file_content_*.c Parse textures/colors
│   │   ├── parse_map_*.c         Extract map
│   │   ├── parse_textures_*.c    Texture path parsing
│   │   ├── parse_rgb_*.c         Color parsing
│   │   └── validate_map_*.c      Map validation
│   │
│   ├── engine/              GAME ENGINE
│   │   ├── init_game.c          Initialize game
│   │   ├── init_setup_*.c       Setup player/camera
│   │   ├── raycasting.c         Ray casting engine
│   │   ├── raycasting_utils_*.c Ray calculations
│   │   ├── rendering.c          Draw to screen
│   │   ├── rendering_utils.c    Render helpers
│   │   ├── textures.c           Texture loading
│   │   ├── textures_utils_*.c   Texture management
│   │   ├── movement.c           Player movement
│   │   ├── input.c              Keyboard input
│   │   ├── keys.c               Key handling
│   │   └── math_utils.c         Math functions
│   │
│   └── utils/               UTILITY FUNCTIONS
│       ├── error.c              Error handling
│       ├── free.c               Memory cleanup
│       └── utils_*.c            Helper functions
│
├── maps/                    MAP FILES
│   ├── valid/                   Valid test maps
│   └── invalid/                 Invalid maps for testing
│
├── textures/                TEXTURE FILES
│   ├── N/                       North wall textures
│   ├── S/                       South wall textures
│   ├── E/                       East wall textures
│   └── W/                       West wall textures
│
├── Makefile                 Build system
└── README.md                This file
```

### Data Structures

#### Main Data Structure

```c
typedef struct s_data
{
    // MLX42 Graphics
    mlx_t           *mlx;
    mlx_image_t     *image;
    
    // Textures
    char            *texture_paths[4];
    t_texture       textures[4];
    
    // Colors
    t_color         floor_color;
    t_color         ceiling_color;
    
    // Map Data
    char            **map;
    int             map_width;
    int             map_height;
    
    // Player Data
    double          player_x;
    double          player_y;
    char            player_dir;
    double          player_angle;
    
    // Raycasting Vectors
    t_vector        player_pos;
    t_vector        player_dir_vec;
    t_vector        camera_plane;
    
    // Game State
    int             game_running;
    t_keys          keys;
    
} t_data;
```

#### Supporting Structures

**Vector:**
```c
typedef struct s_vector
{
    double x;
    double y;
} t_vector;
```

**Color:**
```c
typedef struct s_color
{
    int         r;      // Red (0-255)
    int         g;      // Green (0-255)
    int         b;      // Blue (0-255)
    uint32_t    hex;    // Packed RGBA
} t_color;
```

**Texture:**
```c
typedef struct s_texture
{
    mlx_texture_t   *mlx_texture;
    int             width;
    int             height;
    uint32_t        **pixels;    // 2D array for fast access
} t_texture;
```

**Ray:**
```c
typedef struct s_ray
{
    t_vector    pos;            // Ray start
    t_vector    dir;            // Ray direction
    t_vector    delta_dist;     // Distance per grid unit
    t_vector    side_dist;      // Distance to next grid line
    int         map_x, map_y;   // Current map position
    int         hit;            // Wall hit flag
    int         side;           // Vertical/horizontal wall
    double      wall_dist;      // Distance to wall
    int         line_height;    // Wall height on screen
    int         draw_start;     // Draw start Y
    int         draw_end;       // Draw end Y
    int         tex_num;        // Texture index
    double      wall_x;         // Hit position on wall
    int         tex_x;          // Texture X coordinate
} t_ray;
```

### System Flow

```
┌─────────────────────────────────────────────────────┐
│                 PROGRAM START                        │
└────────────────────┬────────────────────────────────┘
                     │
          ┌──────────▼──────────┐
          │  1.PARSE .CUB FILE  │
          │  - Validate format  │
          │  - Extract textures │
          │  - Parse colors     │
          │  - Load map         │
          │  - Validate map     │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │  2.INITIALIZE MLX42 │
          │  - Create window    │
          │  - Create image     │
          │  - Load textures    │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │  3.SETUP PLAYER     │
          │  - Position vectors │
          │  - Direction vectors│
          │  - Camera plane     │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────┐
          │  4.REGISTER HOOKS   │
          │  - Keyboard callback│
          │  - Game loop hook   │
          └──────────┬──────────┘
                     │
          ┌──────────▼──────────────┐
          │    5. GAME LOOP(60 FPS) │
          │  ┌────────────────────┐ │
          │  │  Process Input     │←┤
          │  │        ↓           │ │
          │  │  Update Movement   │ │
          │  │        ↓           │ │
          │  │  Cast Rays         │ │
          │  │        ↓           │ │
          │  │  Render Frame      │ │
          │  │        ↓           │ │
          │  │  Display           │─┤
          │  └────────────────────┘ │
          └─────────────┬───────────┘
                        │
                   [ESC pressed]
                        │
          ┌─────────────▼───────────┐
          │    6. CLEANUP & EXIT    │
          │  - Free textures        │
          │  - Free map             │
          │  - Terminate MLX        │
          │  - Free all memory      │
          └─────────────────────────┘
```

---

### Key Algorithms

#### 1. Digital Differential Analysis (DDA)

```c
void perform_dda(t_data *data, t_ray *ray)
{
    while (!ray->hit)
    {
        // Step to next grid line
        if (ray->side_dist.x < ray->side_dist.y)
        {
            ray->side_dist.x += ray->delta_dist.x;
            ray->map_x += ray->step.x;
            ray->side = 0;  // Vertical wall
        }
        else
        {
            ray->side_dist.y += ray->delta_dist.y;
            ray->map_y += ray->step.y;
            ray->side = 1;  // Horizontal wall
        }
        
        // Check for wall hit
        if (data->map[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}
```

**Purpose:** Efficiently traverse grid to find wall intersections

#### 2. Flood Fill Validation

```c
void flood_fill(char **map, int x, int y, t_data *data)
{
    // Boundary checks
    if (y < 0 || y >= data->map_height || x < 0)
        return;
    
    // Stop conditions
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    
    // Mark as filled
    map[y][x] = 'F';
    
    // Recursively fill neighbors
    flood_fill(map, x + 1, y, data);  // Right
    flood_fill(map, x - 1, y, data);  // Left
    flood_fill(map, x, y + 1, data);  // Down
    flood_fill(map, x, y - 1, data);  // Up
}
```

**Purpose:** Verify map closure by checking all reachable areas

#### 3. Texture Mapping

```c
uint32_t get_texture_pixel(t_data *data, t_ray *ray, int y)
{
    double step = (double)TEXTURE_SIZE / ray->line_height;
    double tex_pos = (y - WINDOW_HEIGHT / 2 + ray->line_height / 2) * step;
    int tex_y = (int)tex_pos & (TEXTURE_SIZE - 1);
    
    return data->textures[ray->tex_num].pixels[tex_y][ray->tex_x];
}
```

**Purpose:** Map screen pixels to texture pixels with correct scaling

---

<div align="center">

**Cub3D** - *Where 2D becomes 3D through the magic of mathematics* ✨


[⬆ Back to Top](#cub3d---a-raycasting-game-engine)

</div>
