#ifndef NAMECALC_H_
#define NAMECALC_H_

#include <string>

class NameCalc {
  public:
    virtual uint64_t CalcName(const std::string& iName);
  private:
};

#endif
