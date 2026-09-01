#include <iostream>
#include "Match.h"

Match::Match(int id, Player* firstPlayer, Player* secondPlayer) {
    matchId = id;
    player1 = firstPlayer;
    player2 = secondPlayer;
    winner = nullptr;
}

void Match::displayMatch() {
    std::cout << "\n===== MATCH =====" << std::endl;
    std::cout << "Match ID: " << matchId << std::endl;
    std::cout << player1->getName()
              << " VS "
              << player2->getName()
              << std::endl;
}

void Match::setWinner(Player* winningPlayer) {
    if (winningPlayer == player1 || winningPlayer == player2) {
        winner = winningPlayer;
    }
}

Player* Match::getPlayer1() {
    return player1;
}

void Match::finishMatch(Player* winningPlayer) {
    setWinner(winningPlayer);

    if (winner != nullptr) {
        winner->updateScore(100);

        std::cout << "Match finished!" << std::endl;
        std::cout << "Winner: "
                  << winner->getName()
                  << " (+100 points)"
                  << std::endl;
    }
}