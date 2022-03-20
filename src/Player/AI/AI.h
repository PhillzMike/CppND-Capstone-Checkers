//
// Created by phill on 17/03/2022.
//

#ifndef HELLOWORLD_AI_H
#define HELLOWORLD_AI_H


#include "../Player.h"

class AI: public BasePlayer {
public:
    AI(std::string name, int id, int opponentsId, std::shared_ptr<UI> ui);
    virtual Move play() const;


private:
    std::shared_ptr<UI> ui_;
    int _opponentsId;
//    vector<Move> getPossibleMovesForId(Board& board, int id);
//    vector<Move> getMovesForPiece(Board& board, Position piece, int id);
    Move getMove(Board board) const;


};


#endif //HELLOWORLD_AI_H
