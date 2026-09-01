#include "Player.h"
#include "GameManager.h"
#include <thread>

int main() {

    Player player1(101, "Rahul");
    Player player2(102, "Priya");
    Player player3(103, "Amit");
    Player player4(104, "Sarah");

    player1.updateScore(500);
    player2.updateScore(1200);
    player3.updateScore(800);
    player4.updateScore(700);

    GameManager gameManager;

    gameManager.addPlayer(&player1);
    gameManager.addPlayer(&player2);
    gameManager.addPlayer(&player3);
    gameManager.addPlayer(&player4);

    gameManager.run();

    return 0;
}