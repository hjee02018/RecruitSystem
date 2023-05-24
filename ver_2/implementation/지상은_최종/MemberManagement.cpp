#include "MemberManagement.h"
#include "ApplyMangement.h"

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

Member mem[MAX_ACCOUNT];
CompMember comp[MAX_ACCOUNT];
int numComp = 0;
GenMember gen[MAX_ACCOUNT];
int numGen = 0;
string User[MAX_STRING + 1] = ""; // ? ??? ??? user ?
int now_idx; // ? ??? ??? user ? ? index ?

RecruitInfo CompMember::getRecruitment()
{
	return recruitment;
}






void AddMemberUI::createNewMember() {
	fscanf_s(in_fp, "%d %s %s %s %s", inputType, sizeof(inputType), inputName, sizeof(inputName),
		inputNum, sizeof(inputNum), inputId, sizeof(inputId), inputPw, sizeof(inputPw));
}

void AddMemberUI::startInterface() {
	fprintf_s(out_fp, "1.1. ??\n");
	fprintf_s(out_fp, ">  %d %s %s %s %s\n", inputType, inputName, inputNum, inputId, inputPw);
}

void AddMember::addMember() {
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
void AddMember::addNewGeneralMember(const string* name, const string* num, const string* id, const string* pw) {
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (mem[i].isMember == 0) {
			mem[i].addNewGeneralMember(name, num, id, pw);
			numGen++;
			break;
		}
	}
}
void AddMember::addNewCompanyMember(const string* name, const string* num, const string* id, const string* pw) {
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (mem[i].isMember == 0) {
			mem[i].addNewCompanyMember(name, num, id, pw);
			numComp++;
			break;
		}
	}
}

void LoginUI::tryLogin() {
	fscanf_s(in_fp, "%s %s", inputId, sizeof(inputId), inputPw, sizeof(inputPw));
}
void LoginUI::startInterface() {
	fprintf_s(out_fp, "2.1. ?��?\n");
	fprintf_s(out_fp, "> %s %s\n", inputId, inputPw);
}

void Login::tryLogin() {
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

void DeleteMemberUI::tryDelete() {
	// ??,,, ?,,?
}
void DeleteMemberUI::startInterface(string* Id) {
	fprintf_s(out_fp, "1.2. ????\n");
	fprintf_s(out_fp, "> %s\n", Id);
}

void DeleteMember::deleteMemberAuth() {
	DeleteMemberUI deletememberui;

	string id[MAX_ACCOUNT];
	mem[now_idx].toDeleteMemberAuth(id);
	mem[now_idx].isMember = 0;
	now_idx = -1;

	deletememberui.startInterface(id);
	deletememberui.tryDelete();
}

void LogoutUI::tryLogout() {

}
void LogoutUI::startInterface(string* Id) {
	fprintf_s(out_fp, "2.2. ?��???\n");
	fprintf_s(out_fp, "> %s \n", Id);
}

void Logout::tryLogout() {
	string id[MAX_ACCOUNT];
	mem[now_idx].toLogout(id);
	strcpy_s(User, MAX_STRING + 1, "");
	now_idx = -1;
	LogoutUI logoutui;
	logoutui.startInterface(id);
	logoutui.tryLogout();
}

/**
 * ȸ��ȸ���� ������ ������ Ƚ�� ���� ���
 */
void CompMember::getRecruitDepartInfo()
{
	list<RecruitInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_recruitlist.begin(); it != m_recruitlist.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepartName())
				iter->second++;
			else
				applyMap[it->getDepartName()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		cout << "���� : " << iter->first << " �����ڼ� : " << iter->second << endl;
}


/**
 * m_applyList�� ApplyInfo�� ��� ������
 *
 */
void GenMember::showApplyInfo()
{
	list<ApplyInfo>::iterator it;
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		it->showInfo();
}

/**
 * m_applyList�� ApplyInfo ����(���� ��� ���)
 *
 * @ input ( params ) : ���� �� ���� ����
 */
void GenMember::cancelApplyInfo(string compName, int compNo, string departName)
{
	list<ApplyInfo>::iterator it;
	int i = 0;
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		if (it->getDepart() == departName)
			it->~ApplyInfo();

	m_applyList.erase(it);
}

/**
 * m_applyList�� departName�� count ���
 *
 */
void GenMember::getDepartApplyCount()
{
	list<ApplyInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepart())
				iter->second++;
			else
				applyMap[it->getDepart()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		cout << "���� : " << iter->first << " ����Ƚ�� : " << iter->second << endl;
}
