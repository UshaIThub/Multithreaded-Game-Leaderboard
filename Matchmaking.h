#ifndef MATCHMAKING_H
#define MATCHMAKING_H

#include <queue>
#include <mutex>
#include <memory>
#include "Player.h"
#include "Match.h"

class Matchmaking {
private:
    std::queue<Player*> waitingPlayers;
    int nextMatchId;
    std::mutex matchmakingMutex;

public:
    Matchmaking();

    void addPlayer(Player* player);
    bool hasEnoughPlayers();
    std::unique_ptr<Match> createMatch();
};

#endif