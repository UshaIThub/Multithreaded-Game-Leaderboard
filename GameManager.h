#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "Player.h"
#include "Leaderboard.h"
#include "Matchmaking.h"

class GameManager {
private:
    std::vector<Player*> players;
    Leaderboard leaderboard;
    Matchmaking matchmaking;

public: 
    void simulateConcurrentScoreUpdates();
    void simulateConcurrentMatches();
    void simulateConcurrentMatchmaking();
    void addPlayer(Player* player);
    void addPlayerToMatchmaking(int playerId);
    void displayLeaderboard();
    void startMatch();
    void run();
};

#endif