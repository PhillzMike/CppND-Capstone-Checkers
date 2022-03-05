#include "Board.h"
#include "Cell.h"
#include <iostream>

void fillP1Pieces();
Board::Board(int size) {
  _size = size;
  _board = vector<vector<Cell>>(size, vector<Cell>(size, EMPTY));
  addPieces();
}

int Board::getSize() {
  return _size;
}

void Board::addPieces() {
  fillP1Pieces();
  fillP2Pieces();
}

void Board::fillP1Pieces() {
  for(int i = 0; i < _board.size()/2 - 1; i++) {
    fillPiecesOnRow(i, P1);
  }
}

void Board::fillP2Pieces() {
  for(int i = _board.size()/2 + 1; i < _board.size(); i++) {
    fillPiecesOnRow(i, P2);
  }
}
void Board::fillPiecesOnRow(int i, CellState state) {
  for(int j= i%2; j < _board.size(); j+=2) {
    _board[i][j] = state;
  }

}

void Board::clearCell(Position position) {
  getCell(position).setState(EMPTY);
}

void Board::moveCell(Position from, Position to) {
  CellState state = getCell(from).getState();
  clearCell(from);
  getCell(to).setState(state);
}

const CellState& Board::getCellState(Position position) {
  return getCell(position).getState();
}

Cell& Board::getCell(Position position) {
  return _board[position.x][position.y];
}

std::string printCell(Cell &cell) {
  switch(cell.getState()){
    case P1: return "o";
    case P2: return "x";
    default: return " ";
  }
}

void printRow(vector<Cell> row) {
  std::cout << "|";
  for(auto &cell: row) {
    std::cout << printCell(cell) << "|";
  }
  std::cout << std::endl;
}

void Board::printDivider() {
  std::cout << std::string(_board.size(), '_') << std::endl;
}

void Board::printBoard() {
  printDivider();
  for(int i = 0; i < _size;i++) {
    printRow(_board[i]);
      printDivider();

  }

}
