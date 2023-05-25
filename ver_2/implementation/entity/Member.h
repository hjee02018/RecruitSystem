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
	bool memType; // MemberType ( True : GeneralMem, False : CompanyMem )

protected:
	string memId[MAX_STRING + 1]; //ID
	string memPw[MAX_STRING + 1]; //password

public:
	bool isMember = 0;
	void addNewGeneralMember(const string* name, const string* num, const string* id, const string* pw);
	void addNewCompanyMember(const string* name, const string* num, const string* id, const string* pw);
	bool checkValidation(const string* id, const string* pw);
	void toDeleteMemberAuth(string* id);
	void toLogout(string* id);
};

/**
 * 일반 회원에 대한 변수와 일반 회원 관리를 위한 함수 선언
*/
class GenMember : public Member
{
private:
	string genName[MAX_STRING + 1];
	string socialNum[MAX_STRING + 1];
	ApplyInfo apply;

	list< ApplyInfo > m_applyList; // ApplyInfo include

public:
	bool isGen = 0; // �ϴٰ� �ʿ��ؼ� ���� -> public
	void createGeneralMember(const string* name, const string* num, const string* id, const string* pw);

	void showApplyInfo();
	void cancelApplyInfo(string compName, int compNo, string departName);
	void getDepartApplyCount();
};

/**
 * 회사 회원에 대한 변수와 회사 회원 관리를 위한 함수 선언
*/
class CompMember : public Member
{
private:
	string companyName[MAX_STRING + 1];
	string businessNum[MAX_STRING + 1];
	RecruitInfo recruitment;
	list< RecruitInfo > m_recruitlist; // RecruitInfo include

public:
	bool isComp = 0; // �ϴٰ� �ʿ��ؼ� ���� -> public
	void createCompanyMember(const string* name, const string* num, const string* id, const string* pw);
	RecruitInfo getRecruitment();
	void getRecruitDepartInfo();
	void setRecruitment(string task, int num_of_people, time_t deadline);
};