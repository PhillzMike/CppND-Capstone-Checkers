#include "Game.h"

Game::Game(Board& board, Player& firstPlayer, Player& secondPlayer):
    board_(board), firstPlayer_(firstPlayer), secondPlayer_(secondPlayer){
}

void invalidMove(Move move) {

}

bool Game::validateMove(Move &move) {
    return false;
}

bool Game::hasGameFinished() {
    return false;
}

void Game::end() {

}

void Game::start() {
  firstPlayerTurn_ = true;

  while (!hasGameFinished()) {
    Player &currentPlayer = firstPlayerTurn_ ? firstPlayer_ : secondPlayer_;
    Move move = currentPlayer.play();
    if(!validateMove(move)) {
      invalidMove(move);
      break;
    }

  }

}