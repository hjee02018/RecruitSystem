#include "MemberManagement.h"
#include "ApplyManagement.h"

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;



/**
 * 회사 회원이 등록한 채용 정보 목록 반환
 * 
 * @return recruitment
 * @throws nothing
*/
RecruitInfo CompMember::getRecruitment()
{
	return recruitment;
}

/**
 * 회원가입을 위한 정보 입력받기
 * 
 * @return nothing
 * @throws nothing
*/
void AddMemberUI::createNewMember() {
	fscanf_s(in_fp, "%d %s %s %s %s", inputType, sizeof(inputType), inputName, sizeof(inputName),
		inputNum, sizeof(inputNum), inputId, sizeof(inputId), inputPw, sizeof(inputPw));
}

/**
 * 입력받은 정보 출력
 * 
 * @return nothing
 * @throws nothing
*/
void AddMemberUI::startInterface() {
	fprintf_s(out_fp, "1.1. 회원가입\n");
	fprintf_s(out_fp, ">  %d %s %s %s %s\n", inputType, inputName, inputNum, inputId, inputPw);
}

/**
 * 회원 정보 입력받은 후, 저장하고 화면 출력
 * 
 * @return nothing
 * @throws nothing
*/
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

/**
 * 전체 회원 배열에 일반 회원 저장
 * 
 * @param name : 회원 이름
 * @param num : 회원 주민등록번호
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return nothing
 * @throws nothing
*/
void AddMember::addNewGeneralMember(const string* name, const string* num, const string* id, const string* pw) {
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (mem[i].isMember == 0) {
			mem[i].addNewGeneralMember(name, num, id, pw);
			numGen++;
			break;
		}
	}
}

/**
 * 전체 회원 배열에 회사 회원 저장
 * 
 * @param name : 회사 이름
 * @param num : 사업자번호
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return nothing
 * @return nothing
*/
void AddMember::addNewCompanyMember(const string* name, const string* num, const string* id, const string* pw) {
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (mem[i].isMember == 0) {
			mem[i].addNewCompanyMember(name, num, id, pw);
			numComp++;
			break;
		}
	}
}

/**
 * 로그인 정보 입력
 * 
 * @return nothing
 * @throws nothing
*/
void LoginUI::tryLogin() {
	fscanf_s(in_fp, "%s %s", inputId, sizeof(inputId), inputPw, sizeof(inputPw));
}

/**
 * 로그인 정보 출력
 * 
 * @return nothing
 * @throws nothing
*/
void LoginUI::startInterface() {
	fprintf_s(out_fp, "2.1. 로그인\n");
	fprintf_s(out_fp, "> %s %s\n", inputId, inputPw);
}

/**
 * 로그인 가능 유무 확인
 * 
 * @return nothing
 * @throws nothing
*/
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

/**
 * 회원의 delete 버튼 클릭
*/
void DeleteMemberUI::tryDelete() {
	
}

/**
 * 회원 탈퇴 정보 출력
 * 
 * @param Id : 회원 Id
 * @return nothing
 * @throws nothing
 */ 
void DeleteMemberUI::startInterface(string* Id) {
	fprintf_s(out_fp, "1.2. 회원탈퇴\n");
	fprintf_s(out_fp, "> %s\n", Id);
}

/**
 * 회원 정보 삭제
 * 
 * @return nothing
 * @throws nothing
*/
void DeleteMember::deleteMemberAuth() {
	DeleteMemberUI deletememberui;

	string id[MAX_ACCOUNT];
	mem[now_idx].toDeleteMemberAuth(id);
	mem[now_idx].isMember = 0;
	now_idx = -1;

	deletememberui.startInterface(id);
	deletememberui.tryDelete();
}

/**
 * 회원이 로그아웃 버튼 클릭
*/
void LogoutUI::tryLogout() {

}

/**
 * 로그아웃 정보 출력
*/
void LogoutUI::startInterface(string* Id) {
	fprintf_s(out_fp, "2.2. 로그아웃\n");
	fprintf_s(out_fp, "> %s \n", Id);
}

/**
 * 로그아웃
*/
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
