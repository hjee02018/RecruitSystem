#include "RecruitInfo.h"



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
 * to return m_business_number <- "�Լ��� �����ϴ� �۾�"
 *
 * @return m_business_number- "��ȯ��"
 */
int RecruitInfo::getBusinessNumber()
{
    return m_business_number;
}

/**
 * to return m_task <- "�Լ��� �����ϴ� �۾�"
 *
 * @return m_task- "��ȯ��"
 */
string RecruitInfo::getTask()
{
    return m_task;
}

/**
 * to return m_num_of_people <- "�Լ��� �����ϴ� �۾�"
 *
 * @return m_num_of_people- "��ȯ��"
 */
int RecruitInfo::getNumOfPeople()
{
    return m_num_of_people;
}

/**
 * to return m_deadline<- "�Լ��� �����ϴ� �۾�"
 *
 * @return m_deadline- "��ȯ��"
 */
time_t RecruitInfo::getDeadline()
{
    return m_deadline;
}

/**
 * add apply info to apply_info_collectionsk <- "�Լ��� �����ϴ� �۾�"
 *
 * @param apply applying information. <- "�Ű�����1"
 * @return void <- "��ȯ��"
 */
void RecruitInfo::addNewApply(ApplyInfo apply) {
    m_apply_info_collection.addApplyInfo(apply);
}
void RecruitInfo::setRecruitment(string task, int num_of_people, time_t deadline) {
    this->m_task = task;
    this->m_num_of_people = num_of_people;
    this->m_deadline = deadline;
}


/**
 * to return num of apply
 *
 * @return m_num_of_apply
 */
int RecruitInfo::getRecruitCount()
{
	return m_num_of_apply;
}

/**
 * to return name of department
 *
 * @return m_departName
 */
string RecruitInfo::getDepartName()
{
	return m_depart_name;
}