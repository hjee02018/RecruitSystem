#ifndef ApplyUi_hpp
#define ApplyUi_hpp

#include <stdio.h>
#include <string>
#include "ApplyCompany.hpp"
#include "ApplyInfo.hpp"

using namespace std;

/**
 * Represents a apply boundary <- "클래스의 역할"
 *
 */
class ApplyUi
{
public:
    void apply(int business_number, FILE* out_fp);
    int startInterface(FILE* in_fp);
};
#endif /* ApplyUi_hpp */
