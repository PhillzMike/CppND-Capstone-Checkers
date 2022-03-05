//
// Created by phill on 05/03/2022.
//

#ifndef HELLOWORLD_UI_H
#define HELLOWORLD_UI_H


#include "../Board.h"
#include "../Move.h"

class UI {

public:
    UI(Board& board);

    virtual void updateBoard() = 0;
    virtual Move getMove() const = 0 ;

protected:
    const Board& board_;

};


#endif //HELLOWORLD_UI_H
