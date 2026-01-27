cmake_minimum_required(VERSION 3.16)
project(VGP241_Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        app VGP241-Class-Code/Main.cpp
        VGP241-Class-Code/Player.cpp
        VGP241-Class-Code/Item.cpp
        VGP241-Class-Code/Inventory.cpp
)
