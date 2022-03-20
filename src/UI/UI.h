//
// Created by phill on 05/03/2022.
//

#ifndef HELLOWORLD_UI_H
#define HELLOWORLD_UI_H


#include <string>
#include "../Board.h"
#include "../Move.h"

class UI {

public:
    UI(Board& board);

    virtual void updateBoard() = 0;
    virtual Move getMove() const = 0 ;
    virtual void showError(std::string error) const = 0;
    virtual void showMsg(std::string msg) const = 0;

    Board getBoard() const;

protected:
    const Board& board_;

};


#endif //HELLOWORLD_UI_H
