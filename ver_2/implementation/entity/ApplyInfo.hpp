//
//  ApplyInfo.hpp
//  homework3
//
//  Created by 김규철 on 2023/05/21.
//

#ifndef ApplyInfo_hpp
#define ApplyInfo_hpp

#include <stdio.h>
#include <string>

using namespace std;

/**
 * Represents a ApplyInfo object <- "클래스의 역할"
 *
 */
class ApplyInfo
{
private:
    string m_company_name;
    int m_business_number;
    string m_task;
public:
    ApplyInfo(string company_name, int business_number, string task);
    string getCompanyName();
    string getTask();

};
#endif /* ApplyInfo_hpp */
