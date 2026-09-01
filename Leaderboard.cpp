#include <iostream>
#include <algorithm>
#include "Leaderboard.h"

void Leaderboard::addPlayer(Player* player) {
    players.push_back(player);
}

void Leaderboard::displayLeaderboard() {

    std::sort(players.begin(), players.end(),
        [](Player* a, Player* b) {
            return a->getScore() > b->getScore();
        }
    );

    std::cout << "\n===== LEADERBOARD =====" << std::endl;

    int rank = 1;

    for (Player* player : players) {
        std::cout << rank << ". "
                  << player->getName()
                  << " - "
                  << player->getScore()
                  << std::endl;

        rank++;
    }
}

Player* Leaderboard::findPlayerById(int playerId) {

    for (Player* player : players) {

        if (player->getId() == playerId) {
            return player;
        }
    }

    return nullptr;
}