//
// Created by phill on 05/03/2022.
//

#ifndef HELLOWORLD_CONSOLEUI_H
#define HELLOWORLD_CONSOLEUI_H


#include "../UI.h"

class ConsoleUI: public UI{

public:
    ConsoleUI(Board &board);

    Move getMove() const;

    void updateBoard();
};


#endif //HELLOWORLD_CONSOLEUI_H
