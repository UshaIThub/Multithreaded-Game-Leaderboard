#include "Matchmaking.h"

Matchmaking::Matchmaking() {
    nextMatchId = 2001;
}

void Matchmaking::addPlayer(Player* player) {
    std::lock_guard<std::mutex> lock(matchmakingMutex);
    waitingPlayers.push(player);
}

bool Matchmaking::hasEnoughPlayers() {
    std::lock_guard<std::mutex> lock(matchmakingMutex);
    return waitingPlayers.size() >= 2;
}

std::unique_ptr<Match> Matchmaking::createMatch() {

    std::lock_guard<std::mutex> lock(matchmakingMutex);

    if (waitingPlayers.size() < 2) {
        return nullptr;
    }

    Player* firstPlayer = waitingPlayers.front();
    waitingPlayers.pop();

    Player* secondPlayer = waitingPlayers.front();
    waitingPlayers.pop();

    auto match = std::make_unique<Match>(
        nextMatchId,
        firstPlayer,
        secondPlayer
    );

    nextMatchId++;

    return match;
}