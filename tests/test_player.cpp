#include <iostream>
#include "../Player.h"

int main() {

    Player player(101, "TestPlayer");

    player.updateScore(500);

    if (player.getScore() == 500) {
        std::cout << "PASS: Score update test" << std::endl;
    } else {
        std::cout << "FAIL: Score update test" << std::endl;
    }

    player.updateScore(-100);

    if (player.getScore() == 500) {
        std::cout << "PASS: Negative score validation test" << std::endl;
    } else {
        std::cout << "FAIL: Negative score validation test" << std::endl;
    }

    return 0;
}