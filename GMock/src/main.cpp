#include "NameCalc.h"
#include "Student.h"
#include "NameCalcStatic.h"
#include "StudentStatic.h"

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


  StudentStatic<NameCalcStatic> Jerry("Jerry");
  Jerry.show();
  Jerry.bumpName();
  Jerry.show();

  StudentStatic<NameCalcStatic> Hanmeimei("Hanmeimei");
  Hanmeimei.show();
  Hanmeimei.rollBackName();
  Hanmeimei.show();


  return 0;
}
