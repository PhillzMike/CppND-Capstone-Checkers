//
// Created by phill on 05/03/2022.
//
#include <memory>
#include "Player.h"

Player::Player(std::string name, int id, std::shared_ptr<UI> ui): BasePlayer(name, id), ui_(ui) {}

Move Player::play() const{
    return ui_->getMove();
}




