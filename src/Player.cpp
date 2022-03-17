//
// Created by phill on 05/03/2022.
//
#include <memory>
#include "Player.h"
#include "UI/UI.h"

Player::Player(std::string name, int id, std::shared_ptr<UI> ui): ui_(ui), name_(name), id_(id) {}

Move Player::play() const{
    return ui_->getMove();
}

int Player::getScore() const{
    return 0;
}

int Player::getId() const {
    return id_;
}

void Player::setScore(int score) {
    this->score = score;
}




