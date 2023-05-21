#include "RecruitInfo.hpp"

/**
 * to return m_company_name
 *
 * @return m_company_name
 */
string RecruitInfo::getCompanyName()
{
    return m_company_name;
}

/**
 * to return m_business_number <- "함수가 수행하는 작업"
 *
 * @return m_business_number- "반환값"
 */
int RecruitInfo::getBusinessNumber()
{
    return m_business_number;
}

/**
 * to return m_task <- "함수가 수행하는 작업"
 *
 * @return m_task- "반환값"
 */
string RecruitInfo::getTask()
{
    return m_task;
}

/**
 * to return m_num_of_people <- "함수가 수행하는 작업"
 *
 * @return m_num_of_people- "반환값"
 */
int RecruitInfo::getNumOfPeople()
{
    return m_num_of_people;
}

/**
 * to return m_deadline<- "함수가 수행하는 작업"
 *
 * @return m_deadline- "반환값"
 */
time_t RecruitInfo::getDeadline()
{
    return m_deadline;
}

/**
 * add apply info to apply_info_collectionsk <- "함수가 수행하는 작업"
 *
 * @param apply applying information. <- "매개변수1"
 * @return void <- "반환값"
 */
void RecruitInfo::addNewApply(ApplyInfo apply) {
    m_apply_info_collection.addApplyInfo(apply);
}
