#include <iostream>
#include <vector>
#include <algorithm>

struct Board{
  std::vector<std::vector<int> > _rows;
  std::vector<std::vector<int> > _cols;
  std::vector<std::vector<int> > _boxes;
  std::vector<int> _cur;
  int zeros;
};

void createRows(int base[81], Board &cur){
  for(int i = 0;i <= 80;i++){
    if(i <= 8)
      cur._rows[0].push_back(base[i]);
    else if(i <= 17)
      cur._rows[1].push_back(base[i]);
    else if(i <= 26)
      cur._rows[2].push_back(base[i]);
    else if(i <= 35)
      cur._rows[3].push_back(base[i]);
    else if(i <= 44)
      cur._rows[4].push_back(base[i]);
    else if(i <= 53)
      cur._rows[5].push_back(base[i]);
    else if(i <= 62)
      cur._rows[6].push_back(base[i]);
    else if(i <= 71)
      cur._rows[7].push_back(base[i]);
    else if(i <= 80)
      cur._rows[8].push_back(base[i]);
  }
}
void createCols(int base[81], Board &cur){
  for(int i = 0;i <= 80;i = i + 9){
      cur._cols[0].push_back(base[i]);
      cur._cols[1].push_back(base[i+1]);
      cur._cols[2].push_back(base[i+2]);
      cur._cols[3].push_back(base[i+3]);
      cur._cols[4].push_back(base[i+4]);
      cur._cols[5].push_back(base[i+5]);
      cur._cols[6].push_back(base[i+6]);
      cur._cols[7].push_back(base[i+7]);
      cur._cols[8].push_back(base[i+8]);
  }
}
void createBoxes(int base[81], Board &cur){
    int rCount = 0;
    int numCount = 0;
    for(int i = 0;i <= 80;i++){
      if(rCount < 3){
        if(i - rCount*9 < 3){
          cur._boxes[0].push_back(base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 6){
          cur._boxes[1].push_back(base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 9){
          cur._boxes[2].push_back(base[i]);
          numCount++;
        }
        if(numCount == 9){
          rCount++;
          numCount = 0;
        }
      }
      else if(rCount >= 3 && rCount < 6){
        if(i - rCount*9 < 3){
          cur._boxes[3].push_back(base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 6){
          cur._boxes[4].push_back(base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 9){
          cur._boxes[5].push_back(base[i]);
          numCount++;
        }
        if(numCount == 9){
          rCount++;
          numCount = 0;
        }
      }
      else if(rCount >= 6 && rCount < 9){
        if(i - rCount*9 < 3){
          cur._boxes[6].push_back(base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 6){
          cur._boxes[7].push_back(base[i]);
          numCount++;
        }
        else if(i - rCount*9 < 9){
          cur._boxes[8].push_back(base[i]);
          numCount++;
        }
        if(numCount == 9){
          rCount++;
          numCount = 0;
        }
      }
    }
}
void initBoard(Board &cur){
  std::vector<int> temp;
  for(int i = 0;i < 9;i++){
    cur._rows.push_back(temp);
    cur._cols.push_back(temp);
    cur._boxes.push_back(temp);
  }
}

void init(int base[81], Board &cur){
  initBoard(cur);
  createRows(base, cur);
  createCols(base, cur);
  createBoxes(base, cur);
  for(int i = 0;i <= 80;i++){
    cur._cur.push_back(base[i]);
  }
}

void updateCur(Board &cur){
  std::vector<int> newCur;
  for(int i = 0;i < cur._rows.size();i++){
    for(int j = 0;j < cur._rows[i].size();j++){
      newCur.push_back(cur._rows[i][j]);
    }
  }
  cur._cur = newCur;
}

void printRows(Board cur){
  for(int i=0; i<cur._rows[0].size(); ++i)
    std::cout << cur._rows[0][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[1].size(); ++i)
    std::cout << cur._rows[1][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[2].size(); ++i)
    std::cout << cur._rows[2][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[3].size(); ++i)
    std::cout << cur._rows[3][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[4].size(); ++i)
    std::cout << cur._rows[4][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[5].size(); ++i)
    std::cout << cur._rows[5][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[6].size(); ++i)
    std::cout << cur._rows[6][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[7].size(); ++i)
    std::cout << cur._rows[7][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._rows[8].size(); ++i)
    std::cout << cur._rows[8][i] << ' ';
  std::cout << std::endl;
}
void printCols(Board cur){
  for(int i=0; i<cur._cols[0].size(); ++i)
    std::cout << cur._cols[0][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[1].size(); ++i)
    std::cout << cur._cols[1][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[2].size(); ++i)
    std::cout << cur._cols[2][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[3].size(); ++i)
    std::cout << cur._cols[3][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[4].size(); ++i)
    std::cout << cur._cols[4][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[5].size(); ++i)
    std::cout << cur._cols[5][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[6].size(); ++i)
    std::cout << cur._cols[6][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[7].size(); ++i)
    std::cout << cur._cols[7][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._cols[8].size(); ++i)
    std::cout << cur._cols[8][i] << ' ';
  std::cout << std::endl;
}
void printBoxes(Board cur){
  for(int i=0; i<cur._boxes[0].size(); ++i)
    std::cout << cur._boxes[0][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[1].size(); ++i)
    std::cout << cur._boxes[1][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[2].size(); ++i)
    std::cout << cur._boxes[2][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[3].size(); ++i)
    std::cout << cur._boxes[3][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[4].size(); ++i)
    std::cout << cur._boxes[4][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[5].size(); ++i)
    std::cout << cur._boxes[5][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[6].size(); ++i)
    std::cout << cur._boxes[6][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[7].size(); ++i)
    std::cout << cur._boxes[7][i] << ' ';
  std::cout << std::endl;
  for(int i=0; i<cur._boxes[8].size(); ++i)
    std::cout << cur._boxes[8][i] << ' ';
  std::cout << std::endl;
}
void printCur(Board cur){
  for(int i = 0;i < cur._cur.size();i=i+9){
    std::cout << cur._cur[i] << ' ';
    std::cout << cur._cur[i+1] << ' ';
    std::cout << cur._cur[i+2] << ' ';
    std::cout << cur._cur[i+3] << ' ';
    std::cout << cur._cur[i+4] << ' ';
    std::cout << cur._cur[i+5] << ' ';
    std::cout << cur._cur[i+6] << ' ';
    std::cout << cur._cur[i+7] << ' ';
    std::cout << cur._cur[i+8] << ' ';
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void checkZeros(Board &cur){
  int count = 0;
  for(int i = 0;i < 9;i++){
    for(int j = 0;j < 9;j++){
      if(cur._cur[9*i + j] == 0){
        count++;
      }
    }
  }
  cur.zeros = count;
}

std::vector<int> possible(std::vector<int> &r, std::vector<int> &c, std::vector<int> &b){
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
}

int BoardBox(int cRow, int cCol){
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

void printPossibles(Board &cur){

  std::vector<int> possibleValues;
  int cBox = 0;
  int curValue = 0;
  for(int cRow = 0;cRow < 9;cRow++){
    for(int cCol = 0;cCol < 9;cCol++){
      cBox = BoardBox(cRow, cCol);
      if(cur._cur[cRow*9 + cCol] == 0){
        possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[cBox]);
        std::cout << cRow*9 + cCol << " : ";
        for(int i = 0;i < possibleValues.size();i++){
          std::cout << possibleValues[i] << ' ';
        }
        std::cout << std::endl;
      }
      curValue++;
    }
  }
}

void updateRow(Board &cur, int row, int col, int value){
  if(row == 0){
    cur._rows[0][col] = value;
  }
  else if(row == 1){
    cur._rows[1][col] = value;
  }
  else if(row == 2){
    cur._rows[2][col] = value;
  }
  else if(row == 3){
    cur._rows[3][col] = value;
  }
  else if(row == 4){
    cur._rows[4][col] = value;
  }
  else if(row == 5){
    cur._rows[5][col] = value;
  }
  else if(row == 6){
    cur._rows[6][col] = value;
  }
  else if(row == 7){
    cur._rows[7][col] = value;
  }
  else if(row == 8){
    cur._rows[8][col] = value;
  }
}
void updateCol(Board &cur, int row, int col, int value){
  if(col == 0){
    cur._cols[0][row] = value;
  }
  else if(col == 1){
    cur._cols[1][row] = value;
  }
  else if(col == 2){
    cur._cols[2][row] = value;
  }
  else if(col == 3){
    cur._cols[3][row] = value;
  }
  else if(col == 4){
    cur._cols[4][row] = value;
  }
  else if(col == 5){
    cur._cols[5][row] = value;
  }
  else if(col == 6){
    cur._cols[6][row] = value;
  }
  else if(col == 7){
    cur._cols[7][row] = value;
  }
  else if(col == 8){
    cur._cols[8][row] = value;
  }
}
void updateBox(Board &cur, int row, int col, int value){
  int box = BoardBox(row, col);
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
    cur._boxes[0][bPos] = value;
  }
  else if(box == 1){
    cur._boxes[1][bPos] = value;
  }
  else if(box == 2){
    cur._boxes[2][bPos] = value;
  }
  else if(box == 3){
    cur._boxes[3][bPos] = value;
  }
  else if(box == 4){
    cur._boxes[4][bPos] = value;
  }
  else if(box == 5){
    cur._boxes[5][bPos] = value;
  }
  else if(box == 6){
    cur._boxes[6][bPos] = value;
  }
  else if(box == 7){
    cur._boxes[7][bPos] = value;
  }
  else if(box == 8){
    cur._boxes[8][bPos] = value;
  }
}

std::vector<std::vector<int> > possibleByRow(Board &cur, int row){
  updateCur(cur);
  int cBox;
  std::vector<int> possibleValues;
  std::vector<std::vector<int> > posForEachRow;
  std::vector<int> cols;
  for(int cCol = 0;cCol < 9;cCol++){
    cBox = BoardBox(row, cCol);
    if(cur._cur[row*9 + cCol] == 0){
      cols.push_back(cCol);
      possibleValues = possible(cur._rows[row], cur._cols[cCol], cur._boxes[cBox]);
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
void updateByRow(Board &cur, int row){
  std::vector<std::vector<int> > posForEachRowWithCol;
  std::vector<std::vector<int> > posForEachRow;
  posForEachRowWithCol = possibleByRow(cur, row);
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
        updateRow(cur, row, cols[i], newValue);
        updateCol(cur, row, cols[i], newValue);
        updateBox(cur, row, cols[i], newValue);
      }
    }
  }
}

std::vector<std::vector<int> > possibleByCol(Board &cur, int col){
  updateCur(cur);
  int cBox;
  std::vector<int> possibleValues;
  std::vector<std::vector<int> > posForEachCol;
  std::vector<int> rows;
  for(int cRow = 0;cRow < 9;cRow++){
    cBox = BoardBox(cRow, col);
    if(cur._cur[cRow*9 + col] == 0){
      rows.push_back(cRow);
      possibleValues = possible(cur._rows[cRow], cur._cols[col], cur._boxes[cBox]);
      posForEachCol.push_back(possibleValues);
    }
  }
  posForEachCol.push_back(rows);
  return posForEachCol;
}
void updateByCol(Board &cur, int col){

  std::vector<std::vector<int> > posForEachColWithRow;
  std::vector<std::vector<int> > posForEachCol;
  posForEachColWithRow = possibleByCol(cur, col);
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
        updateRow(cur, rows[i], col, newValue);
        updateCol(cur, rows[i], col, newValue);
        updateBox(cur, rows[i], col, newValue);
      }
    }
  }
}

std::vector<std::vector<int> > possibleByBox(Board &cur, int box){
  updateCur(cur);
  std::vector<int> possibleValues;
  std::vector<std::vector<int> > posForEachBox;
  std::vector<int> rows, cols;

  if(box == 0){
    for(int cRow = 0;cRow < 3;cRow++){
      for(int cCol = 0;cCol < 3;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 1){
    for(int cRow = 0;cRow < 3;cRow++){
      for(int cCol = 3;cCol < 6;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 2){
    for(int cRow = 0;cRow < 3;cRow++){
      for(int cCol = 6;cCol < 9;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 3){
    for(int cRow = 3;cRow < 6;cRow++){
      for(int cCol = 0;cCol < 3;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 4){
    for(int cRow = 3;cRow < 6;cRow++){
      for(int cCol = 3;cCol < 6;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 5){
    for(int cRow = 3;cRow < 6;cRow++){
      for(int cCol = 6;cCol < 9;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 6){
    for(int cRow = 6;cRow < 9;cRow++){
      for(int cCol = 0;cCol < 3;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 7){
    for(int cRow = 6;cRow < 9;cRow++){
      for(int cCol = 3;cCol < 6;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }
  else if(box == 8){
    for(int cRow = 6;cRow < 9;cRow++){
      for(int cCol = 6;cCol < 9;cCol++){
        if(cur._cur[cRow*9 + cCol] == 0){
          rows.push_back(cRow);
          cols.push_back(cCol);
          possibleValues = possible(cur._rows[cRow], cur._cols[cCol], cur._boxes[box]);
          posForEachBox.push_back(possibleValues);
        }
      }
    }
  }

  posForEachBox.push_back(rows);
  posForEachBox.push_back(cols);
  return posForEachBox;
}
void updateByBox(Board &cur, int box){
  std::vector<std::vector<int> > posForEachBoxWithRowAndCol;
  std::vector<std::vector<int> > posForEachBox;
  posForEachBoxWithRowAndCol = possibleByBox(cur, box);
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
        updateRow(cur, rows[i], cols[i], newValue);
        updateCol(cur, rows[i], cols[i], newValue);
        updateBox(cur, rows[i], cols[i], newValue);
      }
    }
  }
}

void update(Board &cur){
  updateCur(cur);
  checkZeros(cur);
  while(cur.zeros > 0){
    //printCur(cur);
    for(int i = 0;i < 9;i++){
      updateByRow(cur, i);
    }
    for(int i = 0;i < 9;i++){
      updateByCol(cur, i);
    }
    for(int i = 0;i < 9;i++){
      updateByBox(cur, i);
    }
    updateCur(cur);
    checkZeros(cur);
  }
}

int main(){
  //int base[81] = {8, 0, 6, 0, 0, 3, 0, 9, 0, 0, 4, 0, 0, 1, 0, 0, 6, 8, 2, 0, 0, 8, 7, 0, 0, 0, 5, 1, 0, 8, 0, 0, 5, 0, 2, 0, 0, 3, 0,
  //  1, 0, 0, 0, 5, 0, 7, 0, 5, 0, 3, 0, 9, 0, 0, 0, 2, 1, 0, 0, 7, 0, 4, 0, 6, 0, 0, 0, 2, 0, 8, 0, 0, 0, 8, 7, 6, 0, 4, 0, 0, 3};

  int base[81] = {0, 0, 0, 0, 3, 0, 0, 0, 7, 0, 0, 1, 8, 0, 0, 0, 3, 5, 3, 0, 2, 0, 4, 5, 6, 9, 1, 0, 0, 0, 0, 0, 1, 7, 0, 0, 9, 5, 0,
   0, 8, 0, 0, 1, 2, 0, 0, 8, 4, 0, 0, 0, 0, 0, 2, 7, 3, 5, 1, 0, 9, 0, 6, 8, 9, 0, 0, 0, 3, 1, 0, 0, 4, 0, 0, 0, 9, 0, 0, 0, 0};

  
/*
//hard doesnt work
  int base3[81] = {0, 8, 9, 0, 0, 1, 0, 0, 0, 2, 0, 5, 9, 6, 0, 0, 0, 1, 0, 0, 0, 8, 0, 0, 5, 0, 3, 0, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0,
  0, 3, 0, 0, 2, 0, 0, 0, 6, 0, 0, 4, 0, 0, 7, 0, 0, 0, 0, 9, 0, 0, 0, 6, 0, 0, 3, 0, 0, 0, 0, 1, 0, 6, 0, 0, 0, 0, 0, 0, 0, 2};

  int base4[81] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 9, 5, 0, 0, 0, 2, 5, 0, 1, 0, 0, 0, 8, 0, 7, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0,
  4, 7, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 9, 0, 5, 8, 4, 1, 0, 5, 0, 7, 0, 0, 7, 0, 0, 0, 9, 0, 0, 6, 2, 0, 6, 0, 0, 0, 0, 0, 0, 0};
*/

  struct Board cur;

  init(base, cur);

  std::cout << "Input : " << std::endl;
  printCur(cur);
  update(cur);
  std::cout << "Solved : " << std::endl;
  printCur(cur);

  return 0;
}
