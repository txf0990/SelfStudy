#include "StudentStatic.h"
#include "NameCalcStatic.h"
#include <iostream>
#include <string>

StudentStatic::StudentStatic(const std::string& iName) : _name(iName) {
  std::cout << "StudentStatic " << _name << " constructed..." << std::endl;
}
StudentStatic::~StudentStatic() {
  std::cout << "StudentStatic " << _name << " destructed..." << std::endl;
}

uint64_t StudentStatic::getID() {
  return NameCalcStatic::CalcName(_name);
}

const std::string StudentStatic::getName() {
  return _name;
}

void StudentStatic::bumpName() {
  for (int i = 0; i < _name.size(); i++) {
    _name[i]++;
  }
}

void StudentStatic::rollBackName() {
  for (int i = 0; i < _name.size(); i++) {
    _name[i]--;
  }
}

void StudentStatic::show() {
  std::cout << "Current StudentStatic Name: " << _name << ", ID: " << getID() << std::endl;
}

