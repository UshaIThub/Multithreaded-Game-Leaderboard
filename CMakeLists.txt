cmake_minimum_required(VERSION 3.16)

project(GameLeaderboard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game
    main.cpp
    Player.cpp
    Leaderboard.cpp
    Match.cpp
    Matchmaking.cpp
    GameManager.cpp
)

add_executable(test_player
    tests/test_player.cpp
    Player.cpp
)