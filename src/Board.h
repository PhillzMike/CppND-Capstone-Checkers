#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_

#include <vector>
#include "Cell.h"
#include "Position.h"

using std::vector;

class Board {
 public:
  Board(int size);
  void clearCell(Position position);
  void moveCell(Position from, Position to);
  const CellState& getCellState(Position position);
  void printBoard();

  vector<vector<Cell>> _board;
  int getSize();

 private:
  int _size;
  Cell& getCell(Position position);
  void addPieces();
  void fillP1Pieces();
  void fillP2Pieces();
  void printDivider();


  void fillPiecesOnRow(int i, CellState state);
};

#endif //SRC_BOARD_H_
