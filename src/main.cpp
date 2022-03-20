#include <iostream>
#include "Board.h"
#include "Game.h"
#include "UI/Console/ConsoleUI.h"
#include "Player/AI/AI.h"

int main() {
    std::cout << "Hello World!" << "\n";

    int playerCount;
    int notValid = true;

    while(notValid) {
        try {
            std::cout << "How many players are playing? (1 or 2) ?: ";
            std::cin >> playerCount;
            notValid = false;
        } catch (std::exception e) {
            std::cout << "Wrong input please enter 1 or 2";
        }
    }

    Board board(8);
    std::shared_ptr<UI> consoleUi(new ConsoleUI(board));

    std::unique_ptr<BasePlayer> firstPlayer = std::make_unique<Player>("Timi", 1, consoleUi);
    std::unique_ptr<BasePlayer> secondPlayer;
    if (playerCount == 2) {
        secondPlayer = std::make_unique<Player>("Teni", 2, consoleUi);
    }else{
        secondPlayer = std::make_unique<AI>("Jarvis", 2, 1, consoleUi);
    }

    Game game(board, consoleUi, std::move(firstPlayer), std::move(secondPlayer));

    game.start();

    return 0;
}