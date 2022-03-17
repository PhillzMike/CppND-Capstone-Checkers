#include <sstream>
#include "Game.h"

Game::Game(Board &board, std::shared_ptr<UI> ui, std::unique_ptr<Player> firstPlayer, std::unique_ptr<Player> secondPlayer) :
        board_(board), gameIsFinished(false), ui_(std::move(ui)), firstPlayer_(std::move(firstPlayer)), secondPlayer_(std::move(secondPlayer)) {
}

bool canCapture(int playerId, CellState state) {
    return playerId == 1 && state == P2 || playerId == 2 && state == P1;
}

bool Game::validateMove(int playerId, std::shared_ptr<UI> ui, Move &move) {
    const Cell &source = board_.getCell(move.source);
    const Cell &dest = board_.getCell(move.destination);
    std::ostringstream error;
    if (source.getState() == EMPTY) {
        error << "Source (" << move.source.x << "," << move.source.y << ") cannot be empty, you have to move a piece";
        ui->showError(error.str());
        return false;
    }

    if (dest.getState() != EMPTY) {
        error << "Destination (" << move.destination.x << "," << move.destination.y
              << ") has to be empty, you have to move to a position that is already occupied by a piece";
        ui->showError(error.str());
        return false;
    }

    int diffX = std::abs(move.source.x - move.destination.x);
    int diffY = std::abs(move.source.y - move.destination.y);

    if (!((diffX == 1 || diffX == 2) && diffX == diffY)) {
        error << "Invalid move, you cannot move to that position, you can only move diagonally";
        ui->showError(error.str());
        return false;
    }

    if (diffX == 2 && !canCapture(playerId, board_.getCellState(getOpponentPieceToCapture(move)))) {
        error << "Invalid move, you cannot jump a square without capturing an opponents, piece";
        ui->showError(error.str());
        return false;
    }

    return true;
}

Position Game::getOpponentPieceToCapture(Move move) {
    return Position{(move.source.x - move.destination.x) / 2, (move.source.y - move.destination.y) / 2};
}

bool Game::hasGameFinished() {
    return gameIsFinished;
}

void Game::end() {

}

void Game::capture(Player* player, Move move) {
    if (std::abs(move.source.x - move.destination.x) != 2) {
        return;
    }
    Position opponentPiecePosition = getOpponentPieceToCapture(move);
    board_.clearCell(opponentPiecePosition);
    std::ostringstream message;
    message << "Player " << player->getId() << "just captured a piece on (" << opponentPiecePosition.x << ","
            << opponentPiecePosition.y << ")";
    ui_->showMsg(message.str());
    player->setScore(player->getScore() + 1);
}


void Game::start() {
    firstPlayerTurn_ = true;

    ui_->updateBoard();

    while (!hasGameFinished()) {
        auto currentPlayer = firstPlayerTurn_ ? firstPlayer_.get() : secondPlayer_.get();
        Move move = currentPlayer->play();
        if (!validateMove(currentPlayer->getId(), ui_, move)) {
            continue;
        }

        capture(currentPlayer, move);
        board_.moveCell(move.source, move.destination);
        ui_->updateBoard();
        gameIsFinished = true;
    }

}