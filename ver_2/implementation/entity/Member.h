#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
#include "RecruitInfo.h"
#include "ApplyInfo.h"
using namespace std;

#define MAX_STRING 32
#define MAX_ACCOUNT 100

/**
 * Represents a car object. <- "클래스의 역할"
 * 
 * This class provides methods for starting the car, stopping the car,
 * and changing its speed. <- "클래스의 목적" (과제에서는 생략해도 무방할 듯)
 */


/**
 * CompMember 와 GenMember 의 부모클래스로, 회원에 대한 변수와 회원 관리를 위한 함수 선언
*/
class Member {
private:
	bool m_mem_type; // MemberType ( True : GeneralMem, False : CompanyMem )

protected:
	string mem_id; //ID
	string mem_pw; //password

public:
	bool is_member = 0;
	void addNewGeneralMember(const string name, const string num, const string id, const string pw);
	void addNewCompanyMember(const string name, const string num, const string id, const string pw);
	bool checkValidation(const string id, const string pw);
	void toDeleteMemberAuth(string id);
	void toLogout(string id);
};

/**
 * 일반 회원에 대한 변수와 일반 회원 관리를 위한 함수 선언
*/
class GenMember : public Member
{
private:
	string m_gen_name;
	string m_social_num;
	list< ApplyInfo > m_apply_list; // ApplyInfo include

public:
	bool is_gen = 0; // �ϴٰ� �ʿ��ؼ� ���� -> public
	void createGeneralMember(const string name, const string num, const string id, const string pw);

	void showApplyInfo();
	void cancelApplyInfo(string comp_name, int comp_no, string depart_name);
	void getDepartApplyCount();
	void addApply(ApplyInfo apply);
};

/**
 * 회사 회원에 대한 변수와 회사 회원 관리를 위한 함수 선언
*/
class CompMember : public Member
{
private:
	string m_company_name;
	string m_business_num;
	list< RecruitInfo > m_recruit_list; // RecruitInfo include

public:
	bool is_comp = 0; // �ϴٰ� �ʿ��ؼ� ���� -> public
	void createCompanyMember(const string name, const string num, const string id, const string pw);
	RecruitInfo getRecruitment();
	void getRecruitDepartInfo();
	void setRecruitment(string task, int num_of_people, time_t deadline);
};