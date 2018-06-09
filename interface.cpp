#include "interface.hpp"
#include "puzzles.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

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
};

int* interface::genEasy(){
  int sz = easy.size();
  int pos = rand() % sz + 1;
  _current.setBase(easy[pos-1]);
  status = 1;
  return easy[pos-1];
};

int* interface::genHard(){
  int sz = hard.size();
  int pos = rand() % sz + 1;
  _current.setBase(hard[pos-1]);
  status = 2;
  return hard[pos-1];
};

void interface::print(){
  int* temp = _current.getBase();
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