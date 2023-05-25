#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
#include "./entity/Member.h"
using namespace std;

FILE* in_fp, * out_fp;

#define MAX_STRING 32
#define MAX_ACCOUNT 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
Member mem[MAX_ACCOUNT];
CompMember comp[MAX_ACCOUNT];
int numComp = 0;
GenMember gen[MAX_ACCOUNT];
int numGen = 0;
string User[MAX_STRING + 1] = "";
int now_idx; 

/**
 * 회원가입 관련 boundary class
*/
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

/**
 * 회원가입 관련 control class
*/
class AddMember
{
public:
	void addMember();
	void addNewGeneralMember(const string* name, const string* num, const string* id, const string* pw);
	void addNewCompanyMember(const string* name, const string* num, const string* id, const string* pw);
};

/**
 * 로그인 관련 boundary class
*/
class LoginUI {
public:
	string inputId[MAX_STRING];
	string inputPw[MAX_STRING];
	void tryLogin();
	void startInterface();
};

/**
 * 로그인 관련 control class
*/
class Login {
public:
	void tryLogin();
};

/**
 * 회원탈퇴 관련 boundary class
*/
class DeleteMemberUI {
public:
	void tryDelete();
	void startInterface(string* Id);
};

/**
 * 회원탈퇴 관련 control class
*/
class DeleteMember {
public:
	void deleteMemberAuth();
};

/**
 * 로그아웃 관련 boundary class
*/
class LogoutUI {
public:
	void tryLogout();
	void startInterface(string* Id);
};

/**
 * 로그아웃 관련 control class
*/
class Logout {
public:
	void tryLogout();
};