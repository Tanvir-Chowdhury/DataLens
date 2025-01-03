cmake_minimum_required(VERSION 3.10)

# Project name
project(Main)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)  # Enables automatic processing of .ui files
set(CMAKE_AUTOMOC ON)  # Enables automatic processing of Qt MOC files
set(CMAKE_AUTORCC ON)  # Enables automatic processing of Qt resource files

# Define paths for headers and source files

set(BACKEND_SRC_DIR ${CMAKE_SOURCE_DIR}/backend/src)
set(BACKEND_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/backend/include)

set(GUI_SRC_DIR ${CMAKE_SOURCE_DIR}/gui/src)
set(GUI_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/gui/include)

set(INTERFACE_SRC_DIR ${CMAKE_SOURCE_DIR}/tui/src)
set(INTERFACE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/tui/include)

# Include directories
include_directories(${BACKEND_INCLUDE_DIR} ${GUI_INCLUDE_DIR} ${INTERFACE_INCLUDE_DIR})
add_subdirectory(matplotplusplus)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_wrap_ui(UI ${GUI_SRC_DIR}/mainwindow.ui)
# Collect all source files
file(GLOB SOURCES
    ${BACKEND_SRC_DIR}/*.cpp
    ${GUI_SRC_DIR}/*.cpp
    ${INTERFACE_SRC_DIR}/*.cpp
)

# Collect all header files (optional, for IDEs)
file(GLOB HEADERS
    ${BACKEND_INCLUDE_DIR}/*.h
    ${GUI_INCLUDE_DIR}/*.h
    ${INTERFACE_INCLUDE_DIR}/*.h
)

add_executable(${PROJECT_NAME}
    main.cpp
    ${SOURCES}
    ${HEADERS}  # Optional: Include headers for IDE indexing
    ${UI}
)
target_include_directories(Main PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets matplot)

