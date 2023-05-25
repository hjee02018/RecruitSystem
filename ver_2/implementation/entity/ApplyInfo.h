#pragma once
#include <iostream>
using namespace std;


class ApplyInfo
{
private:
	string m_company_name;
	string m_task;
	int m_business_number;
	int m_headCount;
	time_t m_deadline;
public:
	ApplyInfo(string company_name, int business_number, string task);
	string getDepart();
	void showInfo();
	string getCompanyName();
	string getTask();
};
