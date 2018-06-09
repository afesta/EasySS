#ifndef __SOLVERAPI_H
#define __SOLVERAPI_H

#include <iostream>
#include <vector>
#include <algorithm>

class solver{
  std::vector<std::vector<int> > _rows;
  std::vector<std::vector<int> > _cols;
  std::vector<std::vector<int> > _boxes;
  std::vector<int> _cur;
  int zeros;
  int _base[81];

public:
  solver(){}
  virtual ~solver(){}
  void createRows(int base[81]);
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
