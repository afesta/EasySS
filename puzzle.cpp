#include "puzzleApi.hpp"

void puzzle::setBase(int* base){
  _base = base;
}
int* puzzle::getBase(){
  return _base;
}
std::vector<int> puzzle::getCur(){
  return _cur;
}

void puzzle::clear(){
  _rows.clear();
  _cols.clear();
  _boxes.clear();
  _cur.clear();
}

void puzzle::initBoard(){
    std::vector<int> temp;
    for(int i = 0;i < 9;i++){
      _rows.push_back(temp);
      _cols.push_back(temp);
      _boxes.push_back(temp);
    }
  }

void puzzle::createRows(){
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

void puzzle::createCols(){
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
void puzzle::createBoxes(){
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

void puzzle::init(){
  initBoard();
  createRows();
  createCols();
  createBoxes();
  for(int i = 0;i <= 80;i++){
    _cur.push_back(_base[i]);
  }
}
  
void puzzle::updateCur(){
  std::vector<int> newCur;
  for(int i = 0;i < _rows.size();i++){
    for(int j = 0;j < _rows[i].size();j++){
      newCur.push_back(_rows[i][j]);
    }
  }
  _cur = newCur;
}

void puzzle::checkZeros(){
  int count = 0;
  for(int i = 0;i < 9;i++){
    for(int j = 0;j < 9;j++){
      if(_cur[9*i + j] == 0){
        count++;
      }
    }
  }
  zeros = count;
}

int puzzle::BoardBox(int cRow, int cCol){
  int cBox;
  if (cRow < 3 && cCol < 3) {
    cBox = 0;
  }
  else if (cRow < 3 && cCol < 6 && cCol > 2) {
    cBox = 1;
  }
  else if (cRow < 3 && cCol > 5) {
    cBox = 2;
  }
  else if (cRow > 2 && cRow < 6 && cCol < 3) {
    cBox = 3;
  }
  else if (cRow > 2 && cRow < 6 && cCol > 2 && cCol < 6) {
    cBox = 4;
  }
  else if (cRow > 2 && cRow < 6 && cCol > 5) {
    cBox = 5;
  }
  else if (cRow > 5 && cCol < 3) {
    cBox = 6;
  }
  else if (cRow > 5 && cCol > 2 && cCol < 6) {
    cBox = 7;
  }
  else if (cRow > 5 && cCol > 5) {
    cBox = 8;
  }
  return cBox;
}

/*
create rows/cols/boxes
initBoard
init
update
checkZeros
currentBox
*/
