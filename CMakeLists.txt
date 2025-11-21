cmake_minimum_required(VERSION 4.1.2)

project(HomePCB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_subdirectory(lib)
add_executable(HomePCB main.cpp)

target_link_libraries(HomePCB PRIVATE
    PCBCursor
    PCBApplication
    PCBScene
    PCBShapes
    PCBViewer
    PCBWidgets
)
