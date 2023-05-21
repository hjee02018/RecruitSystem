#include "ApplyInfo.hpp"

/**
 * to return company_name. <- "함수가 수행하는 작업"
 *
 * @return company_name- "반환값"
 */
string ApplyInfo::getCompanyName()
{
    return m_company_name;
}

/**
 * to return task. <- "함수가 수행하는 작업"
 *
 * @return task- "반환값"
 */
string ApplyInfo::getTask()
{
    return m_task;
}

/**
 * All arguments constructor. <- "함수가 수행하는 작업"

 * @param business_name to create constructor. <- "매개변수1"
 * @param company_name to create constructor. <- "매개변수2"
 * @param task to create constructor. <- "매개변수3"
 *
 * @return this- "반환값"
 */
ApplyInfo::ApplyInfo(string company_name, int business_number, string task)
{
    this->m_company_name = company_name;
    this->m_business_number = business_number;
    this->m_task = task;
    
}
