#include "ApplyInfo.h"

/**
 * to return departName
 *
 * @return m_task
 */
string ApplyInfo::getDepart()
{
	return m_task;
}

/**
 * to return m_company_name
 *
 * @return m_company_name
 */
string ApplyInfo::getCompany()
{
    return m_company_name;
}

/**
 * to return m_business_number
 *
 * @return m_business_number
 */
int ApplyInfo::getNumber()
{
    return m_business_number;
}

/**
 * to return m_deadline
 *
 * @return m_deadline
 */
time_t ApplyInfo::getDeadline()
{
    return m_deadline;
}


/**
 * to return m_head_count
 *
 * @return m_head_count
 */
int ApplyInfo::getCount(){
    return m_head_count;
}

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
 * to return m_task
 *
 * @return m_task
 */
string ApplyInfo::getTask()
{
    return m_task;
}

/**
 * All arguments constructor. 
 * @param business_name to create constructor. 
 * @param company_name to create constructor.
 * @param task to create constructor. 
 *
 * @return this instance
 */
ApplyInfo::ApplyInfo(string company_name, int business_number, string task)
{
    this->m_company_name = company_name;
    this->m_business_number = business_number;
    this->m_task = task;
    
}
