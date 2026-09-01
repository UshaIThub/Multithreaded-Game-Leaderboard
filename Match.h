#ifndef MATCH_H
#define MATCH_H

#include "Player.h"

class Match {
private:
    int matchId;
    Player* player1;
    Player* player2;
    Player* winner;

public:
    Match(int id, Player* firstPlayer, Player* secondPlayer);
    Player* getPlayer1();
    void displayMatch();
    void setWinner(Player* winningPlayer);
    Player* getWinner();
    void finishMatch(Player* winningPlayer);
};

#endif