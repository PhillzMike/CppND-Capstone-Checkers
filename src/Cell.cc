#include "Cell.h"

void Cell::makeKing() {
  _isKing = true;
}

bool Cell::isKing() {
  return _isKing;
}

const CellState& Cell::getState() const{
  return _state;
}

void Cell::setState(CellState state) {
  _state = state;
}


