#ifndef __SOLVERAPI_H
#define __SOLVERAPI_H

#include "puzzleApi.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class solver{
public:
  solver(){}
  virtual ~solver(){}
  void createRows(puzzle cur);
  void createCols(int base[81]);
  void createBoxes(int base[81]);
  void initBoard();
  void init();
  void updateCur();
  void printCur();
  void checkZeros();
  int currentBox(int row, int col);
  virtual void solve() const = 0;
};

#endif
