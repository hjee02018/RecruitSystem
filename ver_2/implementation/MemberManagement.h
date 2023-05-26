#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
#include "./entity/Member.h"
using namespace std;


#define MAX_STRING 32
#define MAX_ACCOUNT 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
extern Member mem[MAX_ACCOUNT];
extern CompMember comp[MAX_ACCOUNT];
extern int num_comp;
extern GenMember gen[MAX_ACCOUNT];
extern int num_gen;
extern string user[MAX_STRING + 1];
extern int now_idx; 

/**
 * 회원가입 관련 boundary class
*/
class AddMemberUI
{
public:
	string input_name;
	string input_num;
	string input_id;
	string input_pw;
	int input_type;

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
	void addNewGeneralMember(const string name, const string num, const string id, const string pw);
	void addNewCompanyMember(const string name, const string num, const string id, const string pw);
};

/**
 * 로그인 관련 boundary class
*/
class LoginUI {
public:
	string input_id;
	string input_pw;
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
	void startInterface(string id);
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
	void startInterface(string id);
};

/**
 * 로그아웃 관련 control class
*/
class Logout {
public:
	void tryLogout();
};