#include <sstream>
#include "Game.h"

Game::Game(Board &board, std::shared_ptr<UI> ui, std::unique_ptr<BasePlayer> firstPlayer, std::unique_ptr<BasePlayer> secondPlayer) :
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

    int diffX = move.destination.x - move.source.x;
    int diffY = move.destination.y - move.source.y;

    if (playerId == 1 && diffY < 0 || playerId == 2 && diffY > 0) {
        ui->showError("You cannot move a piece backwards");
        return false;
    }

    diffX = std::abs(diffX);
    diffY = std::abs(diffY);


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
    int diffX = (move.destination.x - move.source.x) / 2;
    int diffY = ( move.destination.y - move.source.y) / 2;
    return Position{move.source.x + diffX,  move.source.y + diffY};
}

bool Game::hasGameFinished() {
    return gameIsFinished;
}

void Game::end() {

}

void Game::capture(BasePlayer* player, Move move) {
    if (std::abs(move.source.x - move.destination.x) != 2) {
        return;
    }
    Position opponentPiecePosition = getOpponentPieceToCapture(move);
    board_.clearCell(opponentPiecePosition);
    std::ostringstream message;
    message << "Player " << player->getId() << " just captured a piece on (" << opponentPiecePosition.x << ","
            << opponentPiecePosition.y << ")";
    ui_->showMsg(message.str());
    player->setScore(player->getScore() + 1);
}

std::string convertPositionToString(Position position) {
    std::ostringstream str_rep;
    str_rep << "(" << position.x << "," << position.y << ")";
    return str_rep.str();
}

std::string convertMoveToString(Move& move) {
    return convertPositionToString(move.source) + "->" + convertPositionToString(move.destination);
}


void Game::start() {
    firstPlayerTurn_ = true;

    ui_->updateBoard();

    while (!hasGameFinished()) {
        auto currentPlayer = firstPlayerTurn_ ? firstPlayer_.get() : secondPlayer_.get();
        std::ostringstream message;
        message << "Player " << currentPlayer->getId() << ": please enter your move ";
        ui_->showMsg(message.str());
        Move move = currentPlayer->play();
        message << "Player " << currentPlayer->getId() << " played the move " << convertMoveToString(move);

        if (!validateMove(currentPlayer->getId(), ui_, move)) {
            continue;
        }

        capture(currentPlayer, move);
        if (currentPlayer->getScore() > 6) {
            ui_->showMsg("Player has won!");
            ui_->showMsg("Game is over");
            gameIsFinished = true;
        }
        board_.moveCell(move.source, move.destination);
        ui_->updateBoard();
        firstPlayerTurn_ = !firstPlayerTurn_;
//        gameIsFinished = true;
    }

}