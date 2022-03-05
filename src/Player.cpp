//
// Created by phill on 05/03/2022.
//
#include "Player.h"

Player::Player(std::string name) {
    this->name = name;
}

Move Player::play() {
    return {.source={1,1}, .destination={1,2}};
}

int Player::getScore() {
    return 0;
}

void Player::setScore(int score) {
    this->score = score;
}




