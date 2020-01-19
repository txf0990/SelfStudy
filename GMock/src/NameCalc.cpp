#include "NameCalc.h"
#include <string>
uint64_t NameCalc::CalcName(const std::string& iName) {
  uint64_t result = 0;
  for (int i = 0; i < iName.size(); i++) {
    if ('a' <= iName[i] && iName[i] <= 'z') {
      result += iName[i] - 'a';
    } else if ('A' <= iName[i] && iName[i] <= 'Z') {
      result += iName[i] - 'A';
    }
  }
  return result;
}
