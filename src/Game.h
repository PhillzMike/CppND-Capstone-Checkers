#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <memory>
#include "Board.h"
#include "Move.h"
#include "Player.h"
#include "UI/UI.h"

class Game {
 public:
  Game(Board &board, std::shared_ptr<UI> ui);

  void start();
  bool hasGameFinished();
  void end();


 private:
    Board &board_;
    std::shared_ptr<UI>  ui_;
  bool firstPlayerTurn_;
  bool gameIsFinished;

  bool validateMove(Move &move);


};

#endif //SRC_GAME_H_
