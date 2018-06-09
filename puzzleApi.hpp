#ifndef __PUZZLEAPI_H
#define __PUZZLEAPI_H

#include <vector>

class puzzle{
  std::vector<std::vector<int> > _rows;
  std::vector<std::vector<int> > _cols;
  std::vector<std::vector<int> > _boxes;
  std::vector<int> _cur;
  int zeros;
  int* _base;
public:
  void setBase(int* base);
  int* getBase();
  std::vector<int> getCur();

  void clear();
  
  void initBoard();
  void createRows();
  void createCols();
  void createBoxes();
  void init();
  void updateCur();
  void checkZeros();
  int BoardBox(int cRow, int cCol);
};

#endif
