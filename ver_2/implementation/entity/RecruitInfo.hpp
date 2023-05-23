#ifndef RecruitInfo_hpp
#define RecruitInfo_hpp

#include <stdio.h>
#include <string>
#include "ApplyInfoCollection.hpp"

using namespace std;

/**
 * Represents a recruit info  object. <- "클래스의 역할"
 *
 */
class RecruitInfo
{
private:
    string m_company_name;
    string m_depart_name;
    int m_business_number;
    int m_num_of_apply;
    int m_num_of_people;
    time_t m_deadline;
    string m_task;
    ApplyInfoCollection m_apply_info_collection;
    
public:
    string getCompanyName();
    int getBusinessNumber();
    string getTask();
    int getNumOfPeople();
    time_t getDeadline();
    void addNewApply(ApplyInfo apply_info);
    
    // 비교 연산자 오버로딩
    bool operator<(const RecruitInfo& other) const {
        return this->m_company_name < m_company_name;
    }
    void setRecruitment(string task, int numPeople, time_t deadline);
};

#endif /* RecruitInfo_hpp */
