//
// Created by phill on 17/03/2022.
//

#ifndef HELLOWORLD_BASEPLAYER_H
#define HELLOWORLD_BASEPLAYER_H


#include <string>
#include "../Move.h"

class BasePlayer {
public:
    BasePlayer(std::string name, int id);
    virtual Move play() const = 0;

    int getScore() const;
    int getId() const;
    void setScore(int score);


private:
    int score;
    int id_;
    std::string name_;
};


#endif //HELLOWORLD_BASEPLAYER_H
