#include "NameCalc.h"
#include "Student.h"

int main() {
  std::shared_ptr<NameCalc> aNameCalc(new NameCalc);

  Student abcd("abcd", aNameCalc);
  abcd.show();
  Student ABCD("ABCD", aNameCalc);
  ABCD.show();

  Student Xiaoming("Xiaoming", aNameCalc);
  Xiaoming.show();
  Xiaoming.bumpName();
  Xiaoming.show();
  
  Student Lisa("Lisa", aNameCalc);
  Lisa.show();
  Lisa.rollBackName();
  Lisa.show();
  return 0;
}
