cmake_minimum_required(VERSION 3.10.2)

project(sudoku C)

set(CMAKE_C_STANDARD 99)
include_directories(${sudoku})
add_executable(sudoku main.c board.c print.c menu.c game.c valid.c highscores.c) 
