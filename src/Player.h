//
// Created by timilehin on 9/18/21.
//

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include "string"
#include "Move.h"
#include "UI/UI.h"

class Player {
 public:
  Player(std::string name, int id, std::shared_ptr<UI> ui);
  virtual Move play() const;

  int getScore() const;
  int getId() const;
  void setScore(int score);


 private:
  int score;
  int id_;
  std::string name_;
  std::shared_ptr<UI> ui_;

};

#endif //SRC_PLAYER_H_
