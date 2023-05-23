#include<iostream>
#include<fstream>
#include<string.h>
#include "hw3.h"
using namespace std;



void doTask();

void program_exit();//6 1

int main()
{
	errno_t input = fopen_s(&in_fp, INPUT_FILE_NAME, "r");
	errno_t ouput = fopen_s(&out_fp, OUTPUT_FILE_NAME, "w");

	doTask();

}

void doTask()
{
	int menu_level_1 = 0, menu_level_2 = 0;
	int former_menu_level_1 = 0, former_menu_level_2 = 0;
	int is_program_exit = 0;
	while (!is_program_exit)
	{
		former_menu_level_1 = menu_level_1;
		former_menu_level_2 = menu_level_2;

		fscanf_s(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				AddMember addmember;
				addmember.addMember();
				break;
			}
			case 2:
			{
				DeleteMember deletemember;
				deletemember.deleteMemberAuth();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				Login login;
				login.tryLogin();
				break;
			}
			case 2:
			{
				Logout logout;
				logout.tryLogout();
				break;
			}
			default:
				break;
			}
			break;
		}
		}
		return;
	}
}

void program_exit()
{
	fprintf_s(out_fp, "6.1. 종료\n");
}

void Member :: addNewGeneralMember(const char* name, const char* num, const char* id, const char* pw) {
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);
	isMember = 1;
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (gen[i].isGen == 0) {
			gen[i].createGeneralMember(name, num, id, pw);
			break;
		}
	}
}
void Member :: addNewCompanyMember(const char* name, const char* num, const char* id, const char* pw) {
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
bool Member :: checkValidation(const char* id, const char* pw) {
	if (strcmp(memId, id) == 0 && strcmp(memPw, pw) == 0) {
		return 1;
	}
	else return 0;
}
void Member :: toDeleteMemberAuth(char* id) {
	strcpy_s(id, MAX_STRING, memId);
}
void Member :: toLogout(char* id) {
	strcpy_s(id, MAX_STRING, memId);
}
Member mem[MAX_ACCOUNT];

void GenMember :: createGeneralMember(const char* name, const char* num, const char* id, const char* pw) {
	strcpy_s(genName, MAX_STRING + 1, name);
	strcpy_s(socialNum, MAX_STRING + 1, num);
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);

	isGen = 1;
}
GenMember gen[MAX_ACCOUNT];

void CompMember :: createCompanyMember(const char* name, const char* num, const char* id, const char* pw) {
	strcpy_s(companyName, MAX_STRING + 1, name);
	strcpy_s(businessNum, MAX_STRING + 1, num);
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);

	isComp = 1;
}
CompMember comp[MAX_ACCOUNT];

char User[MAX_STRING + 1] = ""; // 현재 사용하고 있는 user 저장
int now_idx; // 현재 사용하고 있는 user 가 저장된 index 저장

void AddMemberUI :: createNewMember() {
	fscanf_s(in_fp, "%d %s %s %s %s", inputType, sizeof(inputType), inputName, sizeof(inputName),
		inputNum, sizeof(inputNum), inputId, sizeof(inputId), inputPw, sizeof(inputPw));
}

void AddMemberUI :: startInterface() {
	fprintf_s(out_fp, "1.1. 회원가입\n");
	fprintf_s(out_fp, ">  %d %s %s %s %s\n", inputType, inputName, inputNum, inputId, inputPw);
}

void AddMember :: addMember() {
	AddMemberUI addmemberui;
	addmemberui.createNewMember();

	if (addmemberui.inputType == 1) {
		addNewCompanyMember(addmemberui.inputName, addmemberui.inputNum, addmemberui.inputId, addmemberui.inputPw);
	}
	else if (addmemberui.inputType == 2) {
		addNewGeneralMember(addmemberui.inputName, addmemberui.inputNum, addmemberui.inputId, addmemberui.inputPw);
	}
	addmemberui.startInterface();
}
void AddMember :: addNewGeneralMember(const char* name, const char* num, const char* id, const char* pw) {
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (mem[i].isMember == 0) {
			mem[i].addNewGeneralMember(name, num, id, pw);
			break;
		}
	}
}
void AddMember :: addNewCompanyMember(const char* name, const char* num, const char* id, const char* pw) {
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (mem[i].isMember == 0) {
			mem[i].addNewCompanyMember(name, num, id, pw);
			break;
		}
	}
}

void LoginUI :: tryLogin() {
	fscanf_s(in_fp, "%s %s", inputId, sizeof(inputId), inputPw, sizeof(inputPw));
}
void LoginUI :: startInterface() {
	fprintf_s(out_fp, "2.1. 로그인\n");
	fprintf_s(out_fp, "> %s %s\n", inputId, inputPw);
}

void Login:: tryLogin() {
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

void DeleteMemberUI :: tryDelete() {
	// 회원이,,, 뭐해,,?
}
void DeleteMemberUI :: startInterface(char* Id) {
	fprintf_s(out_fp, "1.2. 회원탈퇴\n");
	fprintf_s(out_fp, "> %s\n", Id);
}

void DeleteMember :: deleteMemberAuth() {
	DeleteMemberUI deletememberui;

	char id[MAX_ACCOUNT];
	mem[now_idx].toDeleteMemberAuth(id);
	mem[now_idx].isMember = 0;
	now_idx = -1;

	deletememberui.startInterface(id);
	deletememberui.tryDelete();
}

void LogoutUI :: tryLogout() {

}
void LogoutUI :: startInterface(char* Id) {
	fprintf_s(out_fp, "2.2. 로그아웃\n");
	fprintf_s(out_fp, "> %s \n", Id);
}

void Logout :: tryLogout() {
	char id[MAX_ACCOUNT];
	mem[now_idx].toLogout(id);
	strcpy_s(User, MAX_STRING + 1, "");
	now_idx = -1;
	LogoutUI logoutui;
	logoutui.startInterface(id);
	logoutui.tryLogout();
}