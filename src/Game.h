#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <memory>
#include "Board.h"
#include "Move.h"
#include "Player.h"
#include "UI/UI.h"

class Game {
public:
    Game(Board &board, std::shared_ptr<UI> ui, std::unique_ptr<Player> firstPlayer, std::unique_ptr<Player> secondPlayer);

    void start();

    bool hasGameFinished();

    void end();


private:
    Board &board_;
    std::shared_ptr<UI> ui_;
    std::unique_ptr<Player> firstPlayer_;
    std::unique_ptr<Player> secondPlayer_;
    bool firstPlayerTurn_;
    bool gameIsFinished;

    bool validateMove(int playerId, std::shared_ptr<UI> ui, Move &move);


    Position getOpponentPieceToCapture(Move move);

    void capture(Player* player, Move move);
};

#endif //SRC_GAME_H_
