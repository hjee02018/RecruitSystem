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

class Member {
private:
	bool memType; // MemberType ( True : GeneralMem, False : CompanyMem )

protected:
	char memId[MAX_STRING + 1]; //ID
	char memPw[MAX_STRING + 1]; //password

public:
	bool isMember = 0;
	void addNewGeneralMember(const char* name, const char* num, const char* id, const char* pw) {
		strcpy_s(memId, MAX_STRING + 1, id);
		strcpy_s(memPw, MAX_STRING + 1, pw);
		isMember = 1;
		for (int i = 0; i < MAX_ACCOUNT; i++) {
			if (gen[i].isGen== 0) {
				gen[i].createGeneralMember(name, num, id, pw);
				break;
			}
		}
	}
	void addNewCompanyMember(const char* name, const char* num, const char* id, const char* pw) {
		strcpy_s(memId, MAX_STRING + 1, id);
		strcpy_s(memPw, MAX_STRING + 1, pw);
		isMember = 1;
		for (int i = 0; i < MAX_ACCOUNT; i++) {
			if (comp[i].isComp == 0) {
				comp[i].createCompanyMember(name, num, id, pw);
				break;
			}
		}
	}
	bool checkValidation(const char* id, const char* pw) {
		if (strcmp(memId, id) == 0 && strcmp(memPw, pw) == 0) {
			return 1;
		}
		else return 0;
	}
	void toDeleteMemberAuth(char* id) {
		strcpy_s(id, MAX_STRING, memId);
	}
	void toLogout(char* id) {
		strcpy_s(id, MAX_STRING, memId);
	}
};
Member mem[MAX_ACCOUNT];

class GenMember : public Member
{
private:
	char genName[MAX_STRING + 1];
	char socialNum[MAX_STRING + 1];
	ApplyInfo apply;
public:
	bool isGen = 0; // 하다가 필요해서 생성 -> public
	void createGeneralMember(const char* name,const char* num,const char* id,const char* pw) {
		strcpy_s(genName, MAX_STRING+1, name);
		strcpy_s(socialNum, MAX_STRING + 1, num);
		strcpy_s(memId, MAX_STRING + 1, id);
		strcpy_s(memPw, MAX_STRING + 1, pw);

		isGen = 1;
	}
};
GenMember gen[MAX_ACCOUNT];

class CompMember : public Member
{
private:
	char companyName[MAX_STRING + 1];
	char businessNum[MAX_STRING + 1];
	RecruitInfo recruitment;
public:
	bool isComp = 0; // 하다가 필요해서 생성 -> public
	void createCompanyMember(const char* name, const char* num, const char* id, const char* pw) {
		strcpy_s(companyName, MAX_STRING + 1, name);
		strcpy_s(businessNum, MAX_STRING + 1, num);
		strcpy_s(memId, MAX_STRING + 1, id);
		strcpy_s(memPw, MAX_STRING + 1, pw);

		isComp = 1;
	}
};
CompMember comp[MAX_ACCOUNT];

char User[MAX_STRING + 1] = ""; // 현재 사용하고 있는 user 저장
int now_idx; // 현재 사용하고 있는 user 가 저장된 index 저장

//회원가입
class AddMemberUI
{
public:
	char inputName[MAX_STRING];
	char inputNum[MAX_STRING];
	char inputId[MAX_STRING];
	char inputPw[MAX_STRING];
	int inputType;

	void createNewMember() {
		fscanf_s(in_fp, "%d %s %s %s %s", inputType, sizeof(inputType), inputName, sizeof(inputName), 
			inputNum, sizeof(inputNum), inputId, sizeof(inputId), inputPw, sizeof(inputPw));
	}
	void startInterface() {
		fprintf_s(out_fp, "1.1. 회원가입\n");
		fprintf_s(out_fp, ">  %d %s %s %s %s\n", inputType, inputName, inputNum,inputId, inputPw);
	}
};

class AddMember
{
public:
	void addMember() {
		AddMemberUI addmemberui;
		addmemberui.createNewMember();
		
		if (addmemberui.inputType == 1) {
			addNewCompanyMember(addmemberui.inputName,addmemberui.inputNum, addmemberui.inputId, addmemberui.inputPw);
		}
		else if (addmemberui.inputType == 2) {
			addNewGeneralMember(addmemberui.inputName, addmemberui.inputNum, addmemberui.inputId, addmemberui.inputPw);
		}
		addmemberui.startInterface();
	}
	void addNewGeneralMember(const char* name,const char* num,const char* id,const char* pw) {
		for (int i = 0; i < MAX_ACCOUNT; i++) {
			if (mem[i].isMember == 0) {
				mem[i].addNewGeneralMember(name, num, id, pw);
				break;
			}
		}
	}
	void addNewCompanyMember(const char* name, const char* num, const char* id, const char* pw) {
		for (int i = 0; i < MAX_ACCOUNT; i++) {
			if (mem[i].isMember == 0) {
				mem[i].addNewCompanyMember(name, num, id, pw);
				break;
			}
		}
	}
};

//로그인
class LoginUI {
public:
	char inputId[MAX_STRING];
	char inputPw[MAX_STRING];
	void tryLogin() {
		fscanf_s(in_fp, "%s %s", inputId, sizeof(inputId), inputPw, sizeof(inputPw));
	}
	void startInterface() {
		fprintf_s(out_fp, "2.1. 로그인\n");
		fprintf_s(out_fp, "> %s %s\n", inputId, inputPw);
	}
};

class Login {
public:
	void tryLogin() {
		LoginUI loginui;
		loginui.tryLogin();
		for (int i = 0; i < MAX_ACCOUNT; i++) {
			if (mem[i].checkValidation(loginui.inputId, loginui.inputPw) == 1) {
				strcpy_s(User, MAX_STRING + 1, loginui.inputId);
				now_idx = i;
				loginui.startInterface();
				break;
			}
		}
	}
};

//회원탈퇴
class DeleteMemberUI {
public:
	void tryDelete() {
		// 회원이,,, 뭐해,,?
	}
	void startInterface(char* Id) {
		fprintf_s(out_fp, "1.2. 회원탈퇴\n");
		fprintf_s(out_fp, "> %s\n", Id);
	}
};

class DeleteMember {
public:
	void deleteMemberAuth() {
		DeleteMemberUI deletememberui;

		char id[MAX_ACCOUNT];
		mem[now_idx].toDeleteMemberAuth(id);
		mem[now_idx].isMember = 0;
		now_idx = -1;

		deletememberui.startInterface(id);
		deletememberui.tryDelete();
	}
};
//로그아웃
class LogoutUI {
public:
	void tryLogout() {

	}
	void startInterface(char* Id) {
		fprintf_s(out_fp, "2.2. 로그아웃\n");
		fprintf_s(out_fp, "> %s \n", Id);
	}
};

class Logout {
public:
	void tryLogout() {
		char id[MAX_ACCOUNT];
		mem[now_idx].toLogout(id);
		strcpy_s(User, MAX_STRING+1, "");
		now_idx = -1;
		LogoutUI logoutui;
		logoutui.startInterface(id);
		logoutui.tryLogout();
	}
};