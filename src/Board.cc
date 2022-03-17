#include "Board.h"
#include "Cell.h"
#include <iostream>
#include <algorithm>

void fillP1Pieces();

Board::Board(int size) {
    _size = size;
    _board = vector<vector<Cell>>(size, vector<Cell>(size, EMPTY));
    addPieces();
}

int Board::getSize() const {
    return _size;
}

void Board::addPieces() {
    fillP1Pieces();
    fillP2Pieces();
}

void Board::fillP1Pieces() {
    for (int i = 0; i < _board.size() / 2 - 1; i++) {
        fillPiecesOnRow(i, P1);
    }
}

void Board::fillP2Pieces() {
    for (int i = _board.size() / 2 + 1; i < _board.size(); i++) {
        fillPiecesOnRow(i, P2);
    }
}

void Board::fillPiecesOnRow(int i, CellState state) {
    for (int j = i % 2; j < _board.size(); j += 2) {
        _board[i][j] = state;
    }

}

void Board::clearCell(Position position) {
    getMutableCell(position).setState(EMPTY);
}

void Board::moveCell(Position from, Position to) {
    CellState state = getCell(from).getState();
    clearCell(from);
    getMutableCell(to).setState(state);
}

const CellState &Board::getCellState(Position position) const{
    return getCell(position).getState();
}

Cell &Board::getMutableCell(Position position) {
    return _board[position.x][position.y];
}

const Cell &Board::getCell(Position position) const{
   return _board[position.x][position.y];
}

const vector<vector<Cell>> &Board::getBoard() const {
    return _board;
}



