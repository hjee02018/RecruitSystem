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
 * to show ApplyInfo
 */
void ApplyInfo::showInfo()
{
	cout << "[ȸ�� �̸� : " << m_company_name <<
		" ���� : " << m_task <<
		" �ο��� : " << m_headCount <<
		" ��û ������ : " << m_deadline << "]" << endl;
}

/**
 * to return company_name. <- "�Լ��� �����ϴ� �۾�"
 *
 * @return company_name- "��ȯ��"
 */
string ApplyInfo::getCompanyName()
{
    return m_company_name;
}

/**
 * to return task. <- "�Լ��� �����ϴ� �۾�"
 *
 * @return task- "��ȯ��"
 */
string ApplyInfo::getTask()
{
    return m_task;
}

/**
 * All arguments constructor. <- "�Լ��� �����ϴ� �۾�"

 * @param business_name to create constructor. <- "�Ű�����1"
 * @param company_name to create constructor. <- "�Ű�����2"
 * @param task to create constructor. <- "�Ű�����3"
 *
 * @return this- "��ȯ��"
 */
ApplyInfo::ApplyInfo(string company_name, int business_number, string task)
{
    this->m_company_name = company_name;
    this->m_business_number = business_number;
    this->m_task = task;
    
}
