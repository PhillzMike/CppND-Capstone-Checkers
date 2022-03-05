#include "Game.h"

Game::Game(Board &board, std::shared_ptr<UI> ui) :
        board_(board), gameIsFinished(false), ui_(std::move(ui)) {
}

void invalidMove(Move move) {

}

bool Game::validateMove(Move &move) {
    return true;
}

bool Game::hasGameFinished() {
    return gameIsFinished;
}

void Game::end() {

}

void Game::start() {
    firstPlayerTurn_ = true;
    Player firstPlayer_ = Player("Timi", ui_);
    Player secondPlayer_ = Player("Deji", ui_);

    ui_->updateBoard();

    while (!hasGameFinished()) {
        Player &currentPlayer = firstPlayerTurn_ ? firstPlayer_ : secondPlayer_;
        Move move = currentPlayer.play();
        if (!validateMove(move)) {
            invalidMove(move);
            continue;
        }
        board_.moveCell(move.source, move.destination);
        ui_->updateBoard();
        gameIsFinished = true;
    }

}