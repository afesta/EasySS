#ifndef __INTERFACE_H
#define __INTERFACE_H

#include "puzzleApi.hpp"

class interface{
private:
  bool _loop;
  puzzle _current;
  //status: 0 for no puzzle, 1 for easy, 2 for hard
  int status;
public:
  void start();
  void input();
  int* genEasy();
  int* genHard();
  void print();
  void solve();
};



#endif
