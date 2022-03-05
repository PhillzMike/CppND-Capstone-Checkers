#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "Board.h"
#include "Move.h"
#include "Player.h"

class Game {
 public:
  Game(Board &board, Player &firstPlayer, Player &secondPlayer);

  void start();
  bool hasGameFinished();
  void end();


 private:
  Board board_;
  bool firstPlayerTurn_;
  Player firstPlayer_;
  Player secondPlayer_;

  bool validateMove(Move &move);


};

#endif //SRC_GAME_H_
