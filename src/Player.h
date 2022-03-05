//
// Created by timilehin on 9/18/21.
//

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include "string"
#include "Move.h"

class Player {
 public:
  Player(std::string name);
  virtual Move play();

  int getScore();
  void setScore(int score);


 private:
  int score;
  std::string name;

};

#endif //SRC_PLAYER_H_
