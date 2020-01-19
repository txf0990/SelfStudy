#ifndef MOCKNAMECALC_H_
#define MOCKNAMECALC_H_

#include "NameCalc.h"
#include <gmock/gmock.h>
#include <string>

class MockNameCalc: public NameCalc {
  public:
    MOCK_METHOD1(CalcName, uint64_t(const std::string&));
};

#endif
