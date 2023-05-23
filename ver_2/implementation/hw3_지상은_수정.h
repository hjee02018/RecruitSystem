#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

FILE* in_fp, * out_fp;

#define MAX_STRING 32
#define MAX_ACCOUNT 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

class State
{
private:
	int menu_level_1;
	int menu_level_2;
public:
	void set_current_state(int a, int b)
	{
		menu_level_1 = a;
		menu_level_2 = b;
	}
	int get_level1()
	{
		return menu_level_1;
	}
	int get_level2()
	{
		return menu_level_2;
	}
};

class ApplyInfo
{

};

class RecruitInfo
{

};

// ȸ��
class Member {
private:
	bool memType; // MemberType ( True : GeneralMem, False : CompanyMem )

protected:
	char memId[MAX_STRING + 1]; //ID
	char memPw[MAX_STRING + 1]; //password

public:
	bool isMember = 0;
	void addNewGeneralMember(const char* name, const char* num, const char* id, const char* pw);
	void addNewCompanyMember(const char* name, const char* num, const char* id, const char* pw);
	bool checkValidation(const char* id, const char* pw);
	void toDeleteMemberAuth(char* id);
	void toLogout(char* id);
};

// �Ϲ�ȸ��
class GenMember : public Member
{
private:
	char genName[MAX_STRING + 1];
	char socialNum[MAX_STRING + 1];
	ApplyInfo apply;
public:
	bool isGen = 0; // �ϴٰ� �ʿ��ؼ� ���� -> public
	void createGeneralMember(const char* name, const char* num, const char* id, const char* pw);
};

// ȸ��ȸ��
class CompMember : public Member
{
private:
	char companyName[MAX_STRING + 1];
	char businessNum[MAX_STRING + 1];
	RecruitInfo recruitment;
public:
	bool isComp = 0; // �ϴٰ� �ʿ��ؼ� ���� -> public
	void createCompanyMember(const char* name, const char* num, const char* id, const char* pw);
	RecruitInfo getRecruitment() {
		return recruitment;
	}



//ȸ������
class AddMemberUI
{
public:
	char inputName[MAX_STRING];
	char inputNum[MAX_STRING];
	char inputId[MAX_STRING];
	char inputPw[MAX_STRING];
	int inputType;

	void createNewMember();
	void startInterface();
};

class AddMember
{
public:
	void addMember();
	void addNewGeneralMember(const char* name, const char* num, const char* id, const char* pw);
	void addNewCompanyMember(const char* name, const char* num, const char* id, const char* pw);
};

//�α���
class LoginUI {
public:
	char inputId[MAX_STRING];
	char inputPw[MAX_STRING];
	void tryLogin();
	void startInterface();
};

class Login {
public:
	void tryLogin();
};

//ȸ��Ż��
class DeleteMemberUI {
public:
	void tryDelete();
	void startInterface(char* Id);
};

class DeleteMember {
public:
	void deleteMemberAuth();
};

//�α׾ƿ�
class LogoutUI {
public:
	void tryLogout();
	void startInterface(char* Id);
};

class Logout {
public:
	void tryLogout();
};