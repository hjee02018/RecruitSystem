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
	return m_recruitment;
}

/**
 * 회원가입을 위한 정보 입력받기
 * 
 * @return nothing
 * @throws nothing
*/
void AddMemberUI::createNewMember() {
	fscanf_s(in_fp, "%d %s %s %s %s", input_type, sizeof(input_type), input_name, sizeof(input_name),
		input_num, sizeof(input_num), input_id, sizeof(input_id), input_pw, sizeof(input_pw));
}

/**
 * 입력받은 정보 출력
 * 
 * @return nothing
 * @throws nothing
*/
void AddMemberUI::startInterface() {
	fprintf_s(out_fp, "1.1. 회원가입\n");
	fprintf_s(out_fp, ">  %d %s %s %s %s\n", input_type, input_name, input_num, input_id, input_pw);
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

	if (addmemberui.input_type == 1) {
		addNewCompanyMember(addmemberui.input_name, addmemberui.input_num, addmemberui.input_id, addmemberui.input_pw);
	}
	else if (addmemberui.input_type == 2) {
		addNewGeneralMember(addmemberui.input_name, addmemberui.input_num, addmemberui.input_id, addmemberui.input_pw);
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
		if (mem[i].is_member == 0) {
			mem[i].addNewGeneralMember(name, num, id, pw);
			num_gen++;
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
		if (mem[i].is_member == 0) {
			mem[i].addNewCompanyMember(name, num, id, pw);
			num_comp++;
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
	fscanf_s(in_fp, "%s %s", input_id, sizeof(input_id), input_pw, sizeof(input_pw));
}

/**
 * 로그인 정보 출력
 * 
 * @return nothing
 * @throws nothing
*/
void LoginUI::startInterface() {
	fprintf_s(out_fp, "2.1. 로그인\n");
	fprintf_s(out_fp, "> %s %s\n", input_id, input_pw);
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
		if (mem[i].checkValidation(loginui.input_id, loginui.input_pw) == 1) {
			strcpy_s(User, MAX_STRING + 1, loginui.input_id);
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
	mem[now_idx].is_member = 0;
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
 * 회사회원이 등록한 채용 정보의 업무별 지원자수 출력
 */
void CompMember::getRecruitDepartInfo()
{
	list<RecruitInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_recruit_list.begin(); it != m_recruit_list.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepartName())
				iter->second++;
			else
				applyMap[it->getDepartName()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		fprintf(out_fp, "%s %d \n", iter->first.c_str(),iter->second);

}


/**
 * 일반 회원의 모든 지원 정보 출력
 *
 */
void GenMember::showApplyInfo()
{
	list<ApplyInfo>::iterator it;
	for (it = m_apply_list.begin(); it != m_apply_list.end(); it++)
		it->showInfo();
}

/**
 *일반회원이 지원을 취소
 *
 * @ input ( params ) : 취소할 지원 정보
 */
void GenMember::cancelApplyInfo(string compName, int compNo, string departName)
{
	list<ApplyInfo>::iterator it;
	int i = 0;
	for (it = m_apply_list.begin(); it != m_apply_list.end(); it++)
		if (it->getDepart() == departName)
			it->~ApplyInfo();

	m_applyList.erase(it);
}

/**
 * 일반 회원이 지원한 지원 정보의 업무별 지원횟수 출력
 *
 */
void GenMember::getDepartApplyCount()
{
	list<ApplyInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_apply_list.begin(); it != m_apply_list.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepart())
				iter->second++;
			else
				applyMap[it->getDepart()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		fprintf(out_fp, "%s %d \n", iter->first.c_str(),iter->second);
}
