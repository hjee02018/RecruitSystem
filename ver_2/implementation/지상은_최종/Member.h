#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
using namespace std;

#define MAX_STRING 32
#define MAX_ACCOUNT 100

// ȸ��
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

// �Ϲ�ȸ��
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

// ȸ��ȸ��
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
};