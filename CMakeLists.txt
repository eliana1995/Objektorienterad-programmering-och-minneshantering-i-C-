cmake_minimum_required(VERSION 4.0)
project(rpg_game)
set(CMAKE_CXX_STANDARD 14)

add_executable(game 
${PROJECT_SOURCE_DIR}/main.cpp
${PROJECT_SOURCE_DIR}/src/Armor.cpp
${PROJECT_SOURCE_DIR}/src/Item.cpp
${PROJECT_SOURCE_DIR}/src/Player.cpp
${PROJECT_SOURCE_DIR}/src/Potion.cpp
${PROJECT_SOURCE_DIR}/src/Weapon.cpp
${PROJECT_SOURCE_DIR}/utils/src/InputHandlers.cpp

)

include_directories(game 
${PROJECT_SOURCE_DIR}/inc/
${PROJECT_SOURCE_DIR}/utils/inc
)
