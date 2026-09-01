#include <iostream>
#include <thread>
#include <memory>
#include "GameManager.h"
#include "Logger.h"

void GameManager::addPlayer(Player* player) {
    players.push_back(player);
    leaderboard.addPlayer(player);
}

void GameManager::addPlayerToMatchmaking(int playerId) {

    for (Player* player : players) {

        if (player->getId() == playerId) {

            matchmaking.addPlayer(player);

            Logger::info(player->getName() + " joined matchmaking");

            return;
        }
    }

    Logger::error("Player not found");
}

void GameManager::displayLeaderboard() {
    leaderboard.displayLeaderboard();
}

void GameManager::startMatch() {

    std::unique_ptr<Match> match = matchmaking.createMatch();

    if (match == nullptr) {
        std::cout << "Not enough players for a match."
                  << std::endl;
        return;
    }

    match->displayMatch();
    Logger::info("Match created successfully");

    std::cout << "Match started!" << std::endl;

    match->finishMatch(match->getPlayer1());
    Logger::info("Match finished successfully");
}

void GameManager::simulateConcurrentMatchmaking() {

    std::thread t1([this]() {
        addPlayerToMatchmaking(101);
    });

    std::thread t2([this]() {
        addPlayerToMatchmaking(102);
    });

    std::thread t3([this]() {
        addPlayerToMatchmaking(103);
    });

    std::thread t4([this]() {
        addPlayerToMatchmaking(104);
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\nConcurrent matchmaking completed."
              << std::endl;
}

void GameManager::simulateConcurrentMatches() {

    addPlayerToMatchmaking(101);
    addPlayerToMatchmaking(102);
    addPlayerToMatchmaking(103);
    addPlayerToMatchmaking(104);

    std::thread matchThread1([this]() {
        startMatch();
    });

    std::thread matchThread2([this]() {
        startMatch();
    });

    matchThread1.join();
    matchThread2.join();

    std::cout << "\nConcurrent match processing completed."
              << std::endl;
}

void GameManager::simulateConcurrentScoreUpdates() {

    std::thread t1([this]() {
        players[0]->updateScore(100);
        std::cout << "Thread 1: Rahul +100" << std::endl;
    });

    std::thread t2([this]() {
        players[1]->updateScore(100);
        std::cout << "Thread 2: Priya +100" << std::endl;
    });

    std::thread t3([this]() {
        players[2]->updateScore(100);
        std::cout << "Thread 3: Amit +100" << std::endl;
    });

    std::thread t4([this]() {
        players[3]->updateScore(100);
        std::cout << "Thread 4: Sarah +100" << std::endl;
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "\nConcurrent score updates completed."
              << std::endl;
}

void GameManager::run() {

    int choice;

    while (true) {

        std::cout << "\n========================================" << std::endl;
        std::cout << "       MULTITHREADED GAME SERVER" << std::endl;
        std::cout << "========================================" << std::endl;

        std::cout << "1. View Leaderboard" << std::endl;
        std::cout << "2. Find Player" << std::endl;
        std::cout << "3. Join Matchmaking" << std::endl;
        std::cout << "4. Start Match" << std::endl;
        std::cout << "5. Run Concurrent Simulation" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                displayLeaderboard();
                break;

            case 2: {
                int playerId;

                std::cout << "Enter Player ID: ";
                std::cin >> playerId;

                Player* player = leaderboard.findPlayerById(playerId);

                if (player != nullptr) {

                    std::cout << "\nPlayer Found!" << std::endl;
                    std::cout << "ID: "
                              << player->getId()
                              << std::endl;

                    std::cout << "Name: "
                              << player->getName()
                              << std::endl;

                    std::cout << "Score: "
                              << player->getScore()
                              << std::endl;

                } else {

                    std::cout << "Player not found."
                              << std::endl;
                }

                break;
            }

            case 3: {
                int playerId;

                std::cout << "Enter Player ID: ";
                std::cin >> playerId;

                addPlayerToMatchmaking(playerId);
                break;
            }

            case 4:
                startMatch();
                break;

            case 5:
                simulateConcurrentMatches();
                break;

            case 6:
                std::cout << "Exiting game..."
                          << std::endl;
                return;

            default:
                std::cout << "Invalid choice."
                          << std::endl;
        }
    }
}