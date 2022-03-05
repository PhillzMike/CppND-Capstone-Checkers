//
// Created by phill on 05/03/2022.
//
#include <memory>
#include "Player.h"
#include "UI/UI.h"

Player::Player(std::string name, std::shared_ptr<UI> ui): ui_(ui) {
    this->name = name;
}

Move Player::play() const{
    return ui_->getMove();
}

int Player::getScore() const{
    return 0;
}

void Player::setScore(int score) {
    this->score = score;
}




