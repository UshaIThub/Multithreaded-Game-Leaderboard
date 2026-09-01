#include <iostream>
#include "Player.h"

Player::Player(int playerId, std::string playerName) {
    id = playerId;
    name = playerName;
    score = 0;
}

int Player::getId() {
    return id;
}

std::string Player::getName() {
    return name;
}

int Player::getScore() {
    std::lock_guard<std::mutex> lock(scoreMutex);
    return score;
}

void Player::updateScore(int points) {

    if (points < 0) {
        std::cout << "Invalid score. Points cannot be negative."
                  << std::endl;
        return;
    }

    std::lock_guard<std::mutex> lock(scoreMutex);

    score += points;
}