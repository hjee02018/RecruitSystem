#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
#include "Member.h"
using namespace std;

FILE* in_fp, * out_fp;

#define MAX_STRING 32
#define MAX_ACCOUNT 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

class ApplyInfo
{

};

class RecruitInfo
{

};


//ȸ������
class AddMemberUI
{
public:
	string inputName[MAX_STRING];
	string inputNum[MAX_STRING];
	string inputId[MAX_STRING];
	string inputPw[MAX_STRING];
	int inputType;

	void createNewMember();
	void startInterface();
};

class AddMember
{
public:
	void addMember();
	void addNewGeneralMember(const string* name, const string* num, const string* id, const string* pw);
	void addNewCompanyMember(const string* name, const string* num, const string* id, const string* pw);
};

//�α���
class LoginUI {
public:
	string inputId[MAX_STRING];
	string inputPw[MAX_STRING];
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
	void startInterface(string* Id);
};

class DeleteMember {
public:
	void deleteMemberAuth();
};

//�α׾ƿ�
class LogoutUI {
public:
	void tryLogout();
	void startInterface(string* Id);
};

class Logout {
public:
	void tryLogout();
};