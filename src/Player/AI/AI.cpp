//
// Created by phill on 17/03/2022.
//

#include "AI.h"
#include <algorithm>
#include <iostream>

AI::AI(std::string name, int id, int opponentsId, std::shared_ptr<UI> ui): BasePlayer(name, id), ui_(ui), _opponentsId(opponentsId) {};

bool isEquals(int id, CellState state) {
    return id == 1 && state == P1 || id == 2 && state == P2;
}

vector<Position> getPieceWithId(Board &board, int id) {
    vector<Position> pieces;

    for (int i = 0; i  < board.getSize();i++) {
        for (int j = 0; j < board.getSize();j++) {
            if (isEquals(id, board.getCellState({i, j}))) {
                pieces.emplace_back(Position{i, j});
            }
        }
    }
    return pieces;
}

vector<Position> getOneStepMoves(Board &board, Position position, int playerId) {
    vector<Position> positions;
    if (playerId == 1 && position.y + 1 < board.getSize()) {
        if (position.x + 1 < board.getSize()) {
            positions.emplace_back(Position{position.x + 1, position.y + 1});
        }
        if (position.x - 1 >= 0) {
            positions.emplace_back(Position{position.x - 1, position.y + 1});
        }
    }

    if (playerId == 2 && position.y - 1 >= 0) {
        if (position.x + 1 < board.getSize()) {
            positions.emplace_back(Position{position.x + 1, position.y - 1});
        }
        if (position.x - 1 >= 0) {
            positions.emplace_back(Position{position.x - 1, position.y - 1});
        }
    }

    return positions;
}


Position getPositionAfterCapture(Board& board, Position piecePosition, Position potentialCapturePosition) {
    int diffX = potentialCapturePosition.x - piecePosition.x;
    int diffY = potentialCapturePosition.y - piecePosition.y ;

    Position destinationPosition = { piecePosition.x + (2*diffX), piecePosition.y + (2*diffY)};

    if (board.isCoordinateInBoard(destinationPosition.x) && board.isCoordinateInBoard(destinationPosition.y) && board.getCellState(destinationPosition) == EMPTY) {
        return destinationPosition;
    }
    return {};
}

vector<Move> getMovesForPiece(Board &board, Position piece, int id) {
    vector<Move> moves;

    for (auto position: getOneStepMoves(board, piece, id)) {
        if(board.getCellState(position) == EMPTY) {
            moves.emplace_back(Move{piece, position});
        } else if(!isEquals(id, board.getCellState(position))){
            Position newDestination = getPositionAfterCapture(board, piece, position);
            if (newDestination.x != -1) {
                moves.emplace_back(Move{piece, newDestination});
            }
        }
    }

    return moves;
}

vector<Move> getPossibleMovesForId(Board& board, int id) {
    vector<Position> pieces = getPieceWithId(board, id);
    vector<Move> moves;

    for(auto& piece: pieces) {
        vector<Move> pieceMoves = getMovesForPiece(board, piece, id);
        moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
    }

    return moves;
}

int playMove(Board& board, Move move) {
    board.moveCell(move.source, move.destination);

    int diffX = move.source.x - move.destination.x;
    int diffY = move.destination.y - move.destination.y;

    if (std::abs(diffX) == 2) {
        board.clearCell({move.source.x + diffX/2, move.source.y + diffY/2});
        return 1;
    }
    return 0;
}

int minmax(Board board, Move move, bool myTurn, int myId, int opponentsId, int depth, int score) {
    if (depth == 1) {
        return score - playMove(board, move);
    }
    int scoreFromMove = playMove(board, move);

    if (myTurn) {
        int opponentsBestScore = INT32_MAX;
        for (auto& move: getPossibleMovesForId(board, opponentsId)) {
            int opponentScore = minmax(board, move, false, myId, opponentsId, depth -1, score + scoreFromMove);
            if (opponentScore < opponentsBestScore) {
                opponentsBestScore = opponentScore;
            }
        }
        return opponentsBestScore;
    }else {
        int myBestScore = INT32_MIN;
        for (auto& move: getPossibleMovesForId(board, myId)) {
            int myScore = minmax(board, move, true, myId, opponentsId, depth -1, score - scoreFromMove);
            if (myScore > myBestScore) {
                myBestScore = myScore;
            }
        }
        return myBestScore;
    }

}

Move AI::getMove(Board board) const{
    int maxScore = INT32_MIN;
    Move bestMove = {};
    vector<Move>  moves = getPossibleMovesForId(board, getId());
    for(auto& move: moves) {
        int score = minmax(board, move, true, getId(),_opponentsId , 2, 0);
        if (score > maxScore) {
            maxScore = score;
            bestMove = move;
        }
    }

    return bestMove;
}

Move AI::play() const {
    return getMove(ui_->getBoard());
}