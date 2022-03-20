//
// Created by timilehin on 9/18/21.
//

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

#include "string"
#include "../Move.h"
#include "../UI/UI.h"
#include "BasePlayer.h"
#include <memory>

class Player: public BasePlayer {
 public:
  Player(std::string name, int id, std::shared_ptr<UI> ui);
  Move play() const;


 private:
  std::shared_ptr<UI> ui_;

};

#endif //SRC_PLAYER_H_
