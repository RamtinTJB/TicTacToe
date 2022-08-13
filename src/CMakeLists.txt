cmake_minimum_required(VERSION 3.12)
project (TicTacToe VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

add_library(LIBRARIES
	board.cpp game.cpp input.cpp
)

target_link_libraries(${PROJECT_NAME} LIBRARIES)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
