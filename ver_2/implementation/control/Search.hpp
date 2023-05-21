//
//  Search.hpp
//  homework3
//
//  Created by 김규철 on 2023/05/21.
//

#ifndef Search_hpp
#define Search_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "RecruitInfo.hpp"

using namespace std;

/**
 * Represents a Search control <- "클래스의 역할"
 *
 */
class Search
{
public:
    RecruitInfo showRecruitmentInfoByCompanyName(string company_name);
    
};
#endif /* Search_hpp */
