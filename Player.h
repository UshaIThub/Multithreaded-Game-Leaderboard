#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <mutex>

class Player {
private:
    int id;
    std::string name;
    int score;

    mutable std::mutex scoreMutex;

public:
    Player(int playerId, std::string playerName);

    int getId();
    std::string getName();
    int getScore();

    void updateScore(int points);
};

#endif