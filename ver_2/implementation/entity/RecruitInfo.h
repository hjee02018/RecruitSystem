#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include "ApplyInfoCollection.h"

using namespace std;

/**
 * CompMember가 등록한 채용 정보를 관리하는 클래스로, 채용 정보(회사명,사업자번호, 지원자 수, 모집인원, 마감일, 업무)와  채용 정보 관리 함수 선언
*/
class RecruitInfo
{
private:
    string m_company_name;
    int m_business_number;
    int m_num_of_apply;
    int m_num_of_people;
    time_t m_deadline;
    string m_task;
    ApplyInfoCollection m_apply_info_collection;
public:
    int getRecruitCount();
    string getDepartName();
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
    void setRecruitment(string task, int num_of_people, time_t deadline);
};
