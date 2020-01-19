#include "Student.h"
#include "NameCalc.h"
#include <iostream>
#include <string>

Student::Student(const std::string& iName, const std::shared_ptr<NameCalc> iNameCalc) : _name(iName), _nameCalc(iNameCalc) {
  std::cout << "Student " << _name << " constructed..." << std::endl;
}
Student::~Student() {
  std::cout << "Student " << _name << " destructed..." << std::endl;
}

uint64_t Student::getID() {
  return _nameCalc->CalcName(_name);
}

const std::string Student::getName() {
  return _name;
}

void Student::bumpName() {
  for (int i = 0; i < _name.size(); i++) {
    _name[i]++;
  }
}

void Student::rollBackName() {
  for (int i = 0; i < _name.size(); i++) {
    _name[i]--;
  }
}

void Student::show() {
  std::cout << "Current Student Name: " << _name << ", ID: " << getID() << std::endl;
}

