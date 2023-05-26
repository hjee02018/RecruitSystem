#pragma once
#include <iostream>
using namespace std;

/**
 * 일반 회원의 지원 정보를 관리하는 클래스로 지원 정보(회사명,업무명,사업자번호,인원수,마감일)와 함수를 제공
*/
class ApplyInfo
{
private:
	string m_company_name;
	string m_task;
	int m_business_number;
	int m_head_count;
	time_t m_deadline;
public:
	ApplyInfo(string company_name, int business_number, string task);
	string getDepart();
	string getCompanyName();
	string getTask();
	string getCompany();
	int getNumber();
	time_t getDeadline();
	int getCount();
};
