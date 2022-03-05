#include <iostream>
#include "Board.h"
#include "Game.h"
#include "UI/Console/ConsoleUI.h"

int main() {
    std::cout << "Hello World!" << "\n";
    Board board(8);
    std::unique_ptr<UI> consoleUi(new ConsoleUI(board));
    Game game(board, std::move(consoleUi));

    game.start();

    return 0;
}