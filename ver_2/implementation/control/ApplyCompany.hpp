#ifndef ApplyCompany_hpp
#define ApplyCompany_hpp

#include <stdio.h>
#include <vector>
#include "ApplyInfo.hpp"
#include "RecruitInfo.hpp"

using namespace std;

/**
 * Represents a Apply control <- "클래스의 역할"
 *
 */
class ApplyCompany
{
public:
    ApplyInfo applyCompany(int business_number);
};
#endif /* ApplyCompany_hpp */
