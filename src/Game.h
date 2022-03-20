#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <memory>
#include "Board.h"
#include "Move.h"
#include "Player/Player.h"
#include "UI/UI.h"

class Game {
public:
    Game(Board &board, std::shared_ptr<UI> ui, std::unique_ptr<BasePlayer> firstPlayer, std::unique_ptr<BasePlayer> secondPlayer);

    void start();

    bool hasGameFinished();

    void end();


private:
    Board &board_;
    std::shared_ptr<UI> ui_;
    std::unique_ptr<BasePlayer> firstPlayer_;
    std::unique_ptr<BasePlayer> secondPlayer_;
    bool firstPlayerTurn_;
    bool gameIsFinished;

    bool validateMove(int playerId, std::shared_ptr<UI> ui, Move &move);


    Position getOpponentPieceToCapture(Move move);

    void capture(BasePlayer* player, Move move);

    void updateUI();
};

#endif //SRC_GAME_H_
