# Multithreaded Game Leaderboard & Matchmaking System

A C++17 console-based game server simulation demonstrating object-oriented programming, STL data structures, matchmaking, leaderboard management, and multithreading.

## Features

- Player management
- Score management
- Leaderboard ranking
- Player lookup by ID
- FIFO matchmaking using `std::queue`
- Match creation
- Automatic winner score updates
- Thread-safe score updates
- Thread-safe matchmaking
- Concurrent matchmaking simulation
- Concurrent match processing
- Logging
- Automated Player tests
- CMake build system
- Smart pointers using `std::unique_ptr`

## Architecture

```text
                    GameManager
                         |
          +--------------+--------------+
          |              |              |
          v              v              v
       Players      Leaderboard    Matchmaking
                                        |
                                        v
                                      Match