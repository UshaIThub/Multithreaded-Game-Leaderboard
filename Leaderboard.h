#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>
#include "Player.h"

class Leaderboard {
private:
    std::vector<Player*> players;

public:
    void addPlayer(Player* player);
    void displayLeaderboard();
    Player* findPlayerById(int playerId);
};

#endif
