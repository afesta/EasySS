#include "interface.hpp"
#include "puzzles.hpp"
#include "solverApi.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

void interface::start(){
  _loop = true;
  while(_loop){
    input();
    
  }
};

void interface::input(){
  std::string in;
  std::cin >> in;
  if(in == "exit"){
    std::cout<<"exitting"<<std::endl;
    _loop=false;
  }
  else if(in == "ge"){
    genEasy();
  }
  else if(in == "gh"){
    genHard();
  }
  else if(in == "print"){
    print();
  }
  else if(in == "solve"){
    solve();
  }
};

int* interface::genEasy(){
  int sz = easy.size();
  int pos = rand() % sz + 1;
  _current.clear();
  _current.setBase(easy[pos-1]);
  _current.init();
  status = 1;
  return easy[pos-1];
};

int* interface::genHard(){
  int sz = hard.size();
  int pos = rand() % sz + 1;
  _current.clear();
  _current.setBase(hard[pos-1]);
  _current.init();
  status = 2;
  return hard[pos-1];
};

void interface::print(){
  if(status == 0){
    std::cout << "no puzzle currently" << std::endl;
  }
  else{
    std::vector<int> temp = _current.getCur();
    for(int i = 0;i < 81;i=i+9){
      std::cout << temp[i] << ' ';
      std::cout << temp[i+1] << ' ';
      std::cout << temp[i+2] << ' ';
      std::cout << temp[i+3] << ' ';
      std::cout << temp[i+4] << ' ';
      std::cout << temp[i+5] << ' ';
      std::cout << temp[i+6] << ' ';
      std::cout << temp[i+7] << ' ';
      std::cout << temp[i+8] << ' ';
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

void interface::solve(){
  if(status == 0){
    std::cout << "no puzzle currently" << std::endl;
  }
  else if(status == 1){
    eSolver esolver(_current);
    puzzle ret = esolver.update();
    _current = ret;
  }
  else if(status == 2){
    std::cout << "hard puzzle not up yet" << std::endl;
  }
}
