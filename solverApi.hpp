#ifndef __SOLVERAPI_H
#define __SOLVERAPI_H

#include "puzzleApi.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class solver{
  puzzle _cur;
public:
  solver(){}
  solver(puzzle cur){_cur = cur;}
  virtual ~solver() = 0;
  virtual puzzle update2() const = 0;
};

class eSolver {
  puzzle _cur;
public:
  eSolver(){}
  eSolver(puzzle cur){_cur = cur;}
  ~eSolver(){}
  std::vector<int> possible(std::vector<int> r, std::vector<int> c, std::vector<int> b);
  void updateRow(int row, int col, int value);
  void updateCol(int row, int col, int value);
  void updateBox(int row, int col, int value);
  std::vector<std::vector<int>> possibleByRow(int row);
  void updateByRow(int row);
  std::vector<std::vector<int>> possibleByCol(int col);
  void updateByCol(int col);
  std::vector<std::vector<int>> possibleByBox(int box);
  void updateByBox(int box);
  puzzle update();
};

class hSolver {
  puzzle _cur;
public:
  hSolver(){}
  hSolver(puzzle cur){_cur = cur;}
  ~hSolver(){}
  
};

#endif
