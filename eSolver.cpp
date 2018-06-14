#include "solverApi.hpp"

std::vector<int> eSolver::possible(std::vector<int> r, std::vector<int> c, std::vector<int> b){
  std::vector<int> values;
  std::vector<int> possibleValues;
  int ttl = 0;
  int value = 0;
  //fill values with all values taken already in row, col, box
  for(int i = 0;i < 9;i++){
    if(r[i] != 0)
      values.push_back(r[i]);
    if(c[i] != 0)
      values.push_back(c[i]);
    if(b[i] != 0)
      values.push_back(b[i]);
  }

  for(int i = 1;i <=9;i++){
    std::vector<int>::iterator it;
    it = find(values.begin(), values.end(), i);
    if(it == values.end()){
      ttl++;
      possibleValues.push_back(i);
    }
  }
  /*for(int i = 0;i < possibleValues.size();i++)
    std::cout << possibleValues[i] << " ";
  std::cout << std::endl;*/
  return possibleValues;
};

void eSolver::updateRow(int row, int col, int value){
  if(row == 0){
    _cur._rows[0][col] = value;
  }
  else if(row == 1){
    _cur._rows[1][col] = value;
  }
  else if(row == 2){
    _cur._rows[2][col] = value;
  }
  else if(row == 3){
    _cur._rows[3][col] = value;
  }
  else if(row == 4){
    _cur._rows[4][col] = value;
  }
  else if(row == 5){
    _cur._rows[5][col] = value;
  }
  else if(row == 6){
    _cur._rows[6][col] = value;
  }
  else if(row == 7){
    _cur._rows[7][col] = value;
  }
  else if(row == 8){
    _cur._rows[8][col] = value;
  }
}
void eSolver::updateCol(int row, int col, int value){
  if(col == 0){
    _cur._cols[0][row] = value;
  }
  else if(col == 1){
    _cur._cols[1][row] = value;
  }
  else if(col == 2){
    _cur._cols[2][row] = value;
  }
  else if(col == 3){
    _cur._cols[3][row] = value;
  }
  else if(col == 4){
    _cur._cols[4][row] = value;
  }
  else if(col == 5){
    _cur._cols[5][row] = value;
  }
  else if(col == 6){
    _cur._cols[6][row] = value;
  }
  else if(col == 7){
    _cur._cols[7][row] = value;
  }
  else if(col == 8){
    _cur._cols[8][row] = value;
  }
}
void eSolver::updateBox(int row, int col, int value){
  int box = _cur.BoardBox(row, col);
  int bRow, bCol, bPos;
  if(row >=3 && row < 6)
    bRow = row - 3;
  else if(row >= 6)
    bRow = row - 6;
  else{
    bRow = row;
  }
  if(col >=3 && col < 6)
    bCol = col - 3;
  else if(col >= 6)
    bCol = col - 6;
  else{
    bCol = col;
  }
  bPos = 3*bRow + bCol;

  //std::cout << row << " " << col << " " << bRow << " " << bCol << " " << bPos << " " <<std::endl;

  if(box == 0){
    _cur._boxes[0][bPos] = value;
  }
  else if(box == 1){
    _cur._boxes[1][bPos] = value;
  }
  else if(box == 2){
    _cur._boxes[2][bPos] = value;
  }
  else if(box == 3){
    _cur._boxes[3][bPos] = value;
  }
  else if(box == 4){
    _cur._boxes[4][bPos] = value;
  }
  else if(box == 5){
    _cur._boxes[5][bPos] = value;
  }
  else if(box == 6){
    _cur._boxes[6][bPos] = value;
  }
  else if(box == 7){
    _cur._boxes[7][bPos] = value;
  }
  else if(box == 8){
    _cur._boxes[8][bPos] = value;
  }
}

std::vector<std::vector<int> > eSolver::possibleByRow(int row){
  _cur.updateCur();
  int cBox;
  std::vector<int> possibleValues;
  std::vector<std::vector<int> > posForEachRow;
  std::vector<int> cols;
  for(int cCol = 0;cCol < 9;cCol++){
    cBox = _cur.BoardBox(row, cCol);
    if(_cur._cur[row*9 + cCol] == 0){
      cols.push_back(cCol);
      possibleValues = possible(_cur._rows[row], _cur._cols[cCol], _cur._boxes[cBox]);
      posForEachRow.push_back(possibleValues);
    }
  }
  posForEachRow.push_back(cols);
  /*
  //print possible for each row entry
  for(int i = 0;i < posForEachRow.size();i++){
    for(int j = 0;j < posForEachRow[i].size();j++){
      std::cout << posForEachRow[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  */
  return posForEachRow;
}
void eSolver::updateByRow(int row){
  std::vector<std::vector<int> > posForEachRowWithCol;
  std::vector<std::vector<int> > posForEachRow;
  posForEachRowWithCol = possibleByRow(row);
  for(int i=0;i < posForEachRowWithCol.size()-1;i++){
    posForEachRow.push_back(posForEachRowWithCol[i]);
  }
  std::vector<int> cols = posForEachRowWithCol[posForEachRowWithCol.size()-1];

  std::vector<std::vector<int> > possibleValues(posForEachRow.size());
  for(int i=0;i < posForEachRow.size();i++){
    for(int j=0;j < posForEachRow.size();j++){
      for(int k=0;k < posForEachRow[j].size();k++){
        if(i != j){
          possibleValues[i].push_back(posForEachRow[j][k]);
        }
      }
    }
  }

  int newValue = 0;
  for(int i=0;i < posForEachRow.size();i++){
    for(int j=0;j < posForEachRow[i].size();j++){
      std::vector<int>::iterator it;
      it = find(possibleValues[i].begin(), possibleValues[i].end(), posForEachRow[i][j]);
      if(it == possibleValues[i].end()){
        newValue = posForEachRow[i][j];
        //std::cout << "Found value (row): " << newValue << std::endl;
        updateRow(row, cols[i], newValue);
        updateCol(row, cols[i], newValue);
        updateBox(row, cols[i], newValue);
      }
    }
  }
}

std::vector<std::vector<int> > eSolver::possibleByCol(int col){
  _cur.updateCur();
  int cBox;
  std::vector<int> possibleValues;
  std::vector<std::vector<int> > posForEachCol;
  std::vector<int> rows;
  for(int cRow = 0;cRow < 9;cRow++){
    cBox = _cur.BoardBox(cRow, col);
    if(_cur._cur[cRow*9 + col] == 0){
      rows.push_back(cRow);
      possibleValues = possible(_cur._rows[cRow], _cur._cols[col], _cur._boxes[cBox]);
      posForEachCol.push_back(possibleValues);
    }
  }
  posForEachCol.push_back(rows);
  return posForEachCol;
}
void eSolver::updateByCol(int col){

  std::vector<std::vector<int> > posForEachColWithRow;
  std::vector<std::vector<int> > posForEachCol;
  posForEachColWithRow = possibleByCol(col);
  for(int i=0;i < posForEachColWithRow.size()-1;i++){
    posForEachCol.push_back(posForEachColWithRow[i]);
  }
  std::vector<int> rows = posForEachColWithRow[posForEachColWithRow.size()-1];

  std::vector<std::vector<int> > possibleValues(posForEachCol.size());
  for(int i=0;i < posForEachCol.size();i++){
    for(int j=0;j < posForEachCol.size();j++){
      for(int k=0;k < posForEachCol[j].size();k++){
        if(i != j){
          possibleValues[i].push_back(posForEachCol[j][k]);
        }
      }
    }
  }

  int newValue = 0;
  for(int i=0;i < posForEachCol.size();i++){
    for(int j=0;j < posForEachCol[i].size();j++){
      std::vector<int>::iterator it;
      it = find(possibleValues[i].begin(), possibleValues[i].end(), posForEachCol[i][j]);
      if(it == possibleValues[i].end()){
        newValue = posForEachCol[i][j];
        //std::cout << "Found value (col): " << newValue << std::endl;
        updateRow(rows[i], col, newValue);
        updateCol(rows[i], col, newValue);
        updateBox(rows[i], col, newValue);
      }
    }
  }
}

std::vector<std::vector<int> > eSolver::possibleByBox(int box){
  _cur.updateCur();
  std::vector<int> possibleValues;
  std::vector<std::vector<int> > posForEachBox;
  std::vector<int> rows, cols;

  if(box == 0){
    for(int cRow = 0;cRow < 3;cRow++){
      for(int cCol = 0;cCol < 3;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 1){
    for(int cRow = 0;cRow < 3;cRow++){
      for(int cCol = 3;cCol < 6;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 2){
    for(int cRow = 0;cRow < 3;cRow++){
      for(int cCol = 6;cCol < 9;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 3){
    for(int cRow = 3;cRow < 6;cRow++){
      for(int cCol = 0;cCol < 3;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 4){
    for(int cRow = 3;cRow < 6;cRow++){
      for(int cCol = 3;cCol < 6;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 5){
    for(int cRow = 3;cRow < 6;cRow++){
      for(int cCol = 6;cCol < 9;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 6){
    for(int cRow = 6;cRow < 9;cRow++){
      for(int cCol = 0;cCol < 3;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 7){
    for(int cRow = 6;cRow < 9;cRow++){
      for(int cCol = 3;cCol < 6;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 8){
    for(int cRow = 6;cRow < 9;cRow++){
      for(int cCol = 6;cCol < 9;cCol++){
        if(_cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(_cur._rows[cRow], _cur._cols[cCol], _cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }

  posForEachBox.push_back(rows);
  posForEachBox.push_back(cols);
  return posForEachBox;
}
void eSolver::updateByBox(int box){
  std::vector<std::vector<int> > posForEachBoxWithRowAndCol;
  std::vector<std::vector<int> > posForEachBox;
  posForEachBoxWithRowAndCol = possibleByBox(box);
  for(int i=0;i < posForEachBoxWithRowAndCol.size()-2;i++){
    posForEachBox.push_back(posForEachBoxWithRowAndCol[i]);
  }
  std::vector<int> rows = posForEachBoxWithRowAndCol[posForEachBoxWithRowAndCol.size()-2];
  std::vector<int> cols = posForEachBoxWithRowAndCol[posForEachBoxWithRowAndCol.size()-1];

  std::vector<std::vector<int> > possibleValues(posForEachBox.size());
  for(int i=0;i < posForEachBox.size();i++){
    for(int j=0;j < posForEachBox.size();j++){
      for(int k=0;k < posForEachBox[j].size();k++){
        if(i != j){
          possibleValues[i].push_back(posForEachBox[j][k]);
        }
      }
    }
  }

  int newValue = 0;
  for(int i=0;i < posForEachBox.size();i++){
    for(int j=0;j < posForEachBox[i].size();j++){
      std::vector<int>::iterator it;
      it = find(possibleValues[i].begin(), possibleValues[i].end(), posForEachBox[i][j]);
      if(it == possibleValues[i].end()){
        newValue = posForEachBox[i][j];
        //std::cout << "Found value (box): " << newValue << std::endl;
        updateRow(rows[i], cols[i], newValue);
        updateCol(rows[i], cols[i], newValue);
        updateBox(rows[i], cols[i], newValue);
      }
    }
  }
}

puzzle eSolver::update(){
  _cur.updateCur();
  _cur.checkZeros();
  while(_cur.zeros > 0){
    //printCur(cur);
    for(int i = 0;i < 9;i++){
      updateByRow(i);
    }
    for(int i = 0;i < 9;i++){
      updateByCol(i);
    }
    for(int i = 0;i < 9;i++){
      updateByBox(i);
    }
    _cur.updateCur();
    _cur.checkZeros();
  }
  return _cur;
}
