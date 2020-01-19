#ifndef STUDENTSTATIC_H_
#define STUDENTSTATIC_H_

#include <iostream>
#include <string>

template<typename T>
class StudentStatic {
  public:
  StudentStatic(const std::string& iName);
  ~StudentStatic();

  const std::string getName();
  uint64_t getID();
  void bumpName();
  void rollBackName();
  void show();
  
  protected:
  std::string _name;
};

template<typename T>
StudentStatic<T>::StudentStatic(const std::string& iName) : _name(iName) {
  std::cout << "StudentStatic " << _name << " constructed..." << std::endl;
}
template<typename T>
StudentStatic<T>::~StudentStatic() {
  std::cout << "StudentStatic " << _name << " destructed..." << std::endl;
}

template<typename T>
uint64_t StudentStatic<T>::getID() {
  return T::CalcName(_name);
}

template<typename T>
const std::string StudentStatic<T>::getName() {
  return _name;
}

template<typename T>
void StudentStatic<T>::bumpName() {
  for (int i = 0; i < _name.size(); i++) {
    _name[i]++;
  }
}

template<typename T>
void StudentStatic<T>::rollBackName() {
  for (int i = 0; i < _name.size(); i++) {
    _name[i]--;
  }
}

template<typename T>
void StudentStatic<T>::show() {
  std::cout << "Current StudentStatic Name: " << _name << ", ID: " << getID() << std::endl;
}


#endif
