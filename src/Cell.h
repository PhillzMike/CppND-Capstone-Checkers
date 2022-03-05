#ifndef SRC_CELL_H_
#define SRC_CELL_H_

enum CellState {
  EMPTY,
  P1,
  P2
};

class Cell {
 public:
  Cell(CellState state):_state(state){};

  void makeKing();
  void setState(CellState state);

  bool isKing();
  const CellState& getState() const;

 private:
  CellState _state;
  bool _isKing{false};

};

#endif //SRC_CELL_H_
