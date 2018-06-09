#include "solverApi.hpp"

class eSolver : public solver {
  std::vector<std::vector<int> > _rows;
  std::vector<std::vector<int> > _cols;
  std::vector<std::vector<int> > _boxes;
  std::vector<int> _cur;
  int zeros;
  int _base[81];

public:
  void createRows(){
    for(int i = 0;i <= 80;i++){
      if(i <= 8)
	_rows[0].push_back(_base[i]);
      else if(i <= 17)
	_rows[1].push_back(_base[i]);
      else if(i <= 26)
	_rows[2].push_back(_base[i]);
      else if(i <= 35)
	_rows[3].push_back(_base[i]);
      else if(i <= 44)
	_rows[4].push_back(_base[i]);
      else if(i <= 53)
	_rows[5].push_back(_base[i]);
      else if(i <= 62)
	_rows[6].push_back(_base[i]);
      else if(i <= 71)
	_rows[7].push_back(_base[i]);
      else if(i <= 80)
	_rows[8].push_back(_base[i]);
    }
  }
  void createCols(){
    for(int i = 0;i <= 80;i = i + 9){
      _cols[0].push_back(_base[i]);
      _cols[1].push_back(_base[i+1]);
      _cols[2].push_back(_base[i+2]);
      _cols[3].push_back(_base[i+3]);
      _cols[4].push_back(_base[i+4]);
      _cols[5].push_back(_base[i+5]);
      _cols[6].push_back(_base[i+6]);
      _cols[7].push_back(_base[i+7]);
      _cols[8].push_back(_base[i+8]);
    }
  }
  void createBoxes(){
    int rCount = 0;
    int numCount = 0;
    for(int i = 0;i <= 80;i++){
      if(rCount < 3){
        if(i - rCount*9 < 3){
          _boxes[0].push_back(_base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 6){
          _boxes[1].push_back(_base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 9){
          _boxes[2].push_back(_base[i]);
          numCount++;
        }
        if(numCount == 9){
          rCount++;
          numCount = 0;
        }
      }
      else if(rCount >= 3 && rCount < 6){
        if(i - rCount*9 < 3){
          _boxes[3].push_back(_base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 6){
          _boxes[4].push_back(_base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 9){
          _boxes[5].push_back(_base[i]);
          numCount++;
        }
        if(numCount == 9){
          rCount++;
          numCount = 0;
        }
      }
      else if(rCount >= 6 && rCount < 9){
        if(i - rCount*9 < 3){
          _boxes[6].push_back(_base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 6){
          _boxes[7].push_back(_base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 9){
          _boxes[8].push_back(_base[i]);
          numCount++;
        }
        if(numCount == 9){
          rCount++;
          numCount = 0;
        }
      }
    }
  }

  void initBoard(){
    std::vector<int> temp;
    for(int i = 0;i < 9;i++){
      _rows.push_back(temp);
      _cols.push_back(temp);
      _boxes.push_back(temp);
    }
  }

  void init(){
    initBoard();
    createRows();
    createCols();
    createBoxes();
    for(int i = 0;i <= 80;i++){
      _cur.push_back(_base[i]);
    }
  }
  
  void updateCur(){
    std::vector<int> newCur;
    for(int i = 0;i < _rows.size();i++){
      for(int j = 0;j < _rows[i].size();j++){
	newCur.push_back(_rows[i][j]);
      }
    }
    _cur = newCur;
  }

  
}
