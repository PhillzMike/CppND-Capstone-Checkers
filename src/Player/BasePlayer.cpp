//
// Created by phill on 17/03/2022.
//

#include "BasePlayer.h"

BasePlayer::BasePlayer(std::string name, int id): name_(name), id_(id),score(0) {}

int BasePlayer::getScore() const{
    return score;
}

int BasePlayer::getId() const {
    return id_;
}

void BasePlayer::setScore(int score) {
    this->score = score;
}
