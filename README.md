# DataLens: Data analysis project on Olympic 2024 Dataset

DataLens is a comprehensive C++ application designed to manage and analyze Olympic Games data. It features a custom-built backend for data management, a graphical user interface (GUI) built with Qt6 for interactive analysis, and a terminal user interface (TUI) for quick data access and administration.

## Features

### Backend
- **Custom Database Engine**: Implemented using custom `LinkedList` data structures and `unordered_map` for efficient table management.
- **Data Persistence**: Supports loading and saving data from CSV files.
- **Core Operations**: Insert, remove, search, and display data records.
- **Graph Algorithms**: Includes graph-based analysis for data relationships.

### Visualization & Analysis
- **Data Plotting**: Utilizes `matplotplusplus` for generating statistical charts.
- **Analysis Modules**:
  - Gender Distribution analysis.
  - Total Medal Count by Country.
  - Visual analysis viewer in GUI.

### User Interfaces
- **GUI (Qt6)**:
  - **Table Viewer**: View datasets in a structured table format.
  - **Search Tool**: Advanced search capabilities within CSV data.
  - **Analysis Dashboard**: View generated plots and analysis results.
- **TUI (Terminal)**:
  - **User Management**: Member registration and login system.
  - **Role-based Access**: Separate menus for Admins and Users.
  - **Data Management**: Submenus for searching Athletes, Coaches, and Teams.

## Tech Stack

- **Language**: C++17
- **GUI Framework**: Qt6 (Core, Gui, Widgets)
- **Build System**: CMake (>= 3.10)
- **Visualization**: Matplot++

## Project Structure

```
.
├── backend/            # Core logic and data structures (Database, LinkedList, Graphs)
├── gui/                # Qt-based graphical user interface
├── tui/                # Terminal-based user interface and menu handling
├── data/               # CSV datasets (Athletes, Coaches, Medals, etc.)
├── matplotplusplus/    # Plotting library submodule
├── CMakeLists.txt      # Build configuration
└── main.cpp            # Application entry point
```

## Prerequisites

Ensure you have the following installed on your system:

- C++ Compiler supporting C++17 (e.g., GCC, Clang, MSVC)
- CMake (Version 3.10 or higher)
- Qt6 Development Libraries

## Build Instructions

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Tanvir-Chowdhury/DataLens.git
    cd DataLens
    ```

2.  **Create a build directory:**
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure the project with CMake:**
    ```bash
    cmake ..
    ```

4.  **Build the application:**
    ```bash
    make
    ```

## Usage

After building, you can run the executable generated in the `build` directory.

**Note:** The application currently expects data files to be in a specific directory. You may need to update the `dataFolder` path in `main.cpp` to point to your local `data/` or `data1/` directory before building.

```cpp
// main.cpp
std::string dataFolder = "/path/to/your/datalens/data1";
```

