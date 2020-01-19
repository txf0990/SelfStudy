#ifndef STUDENT_H_
#define STUDENT_H_

#include "NameCalc.h"
#include <string>
class Student {
  public:
  Student(const std::string& iName, const std::shared_ptr<NameCalc> iNameCalc);
  ~Student();

  const std::string getName();
  uint64_t getID();
  void bumpName();
  void rollBackName();
  void show();
  
  protected:
  std::string _name;
  std::shared_ptr<NameCalc> _nameCalc;
};

#endif
