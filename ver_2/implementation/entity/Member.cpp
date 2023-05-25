#include "MemberManagement.h"
#include "ApplyManagement.h"
#include "Member.h"

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


/**
* 일반 회원 저장
* 
* @param name : 회원 이름
* @param num : 회원 주민등록번호
* @param id : 회원 id
* @param pw : 회원 pw
* @return nothing
* @throws nothing
*/
void Member::addNewGeneralMember(const string name, const string num, const string id, const string pw) {
	this->mem_id=id;
	this->mem_pw=pw;
	this->is_member = 1;
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (gen[i].is_gen == 0) {
			gen[i].createGeneralMember(name, num, id, pw);
			break;
		}
	}
}

/**
 * 회사 회원 저장
 * @param name : 회원 이름
 * @param num : 사업자 번호
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return nothing
 * @throws nothing
*/
void Member::addNewCompanyMember(const string name, const string num, const string id, const string pw) {
	this->mem_id=id;
	this->mem_pw=pw;
	this->is_member = 1;
	for (int i = 0; i < MAX_ACCOUNT; i++) {
		if (comp[i].is_comp == 0) {
			comp[i].createCompanyMember(name, num, id, pw);
			break;
		}
	}
}

/**
 * 로그인 시 id 와 pw 가 일치하는지 확인
 * 
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return boolean : 일치하면 1, 불일치하면 0
 * @throws 불일치할 경우 로그인 불가
*/
bool Member::checkValidation(const string id, const string pw) {
	if (mem_id==id && mem_pw==pw) {
		return 1;
	}
	else return 0;
}

/**
 * 회원 정보를 삭제하기 위해 id 확인
 * 
 * @param id : 회원 id
 * @return nothing
 * @throws nothing
*/
void Member::toDeleteMemberAuth() {
	is_member = 0;
}

/**
 * 로그아웃을 위해 id 확인
 * 
 * @param id : 회원 id
 * @return nothing
 * @throws nothing
*/
void Member::toLogout() {
	mem_id = "";
}

/**
 * 일반 회원의 회원가입을 위한 입력받은 정보 저장
 * 
 * @param name : 회원 이름
 * @param num : 회원 주민등록번호
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return nothing
 * @throws nothing
*/
void GenMember::createGeneralMember(const string name, const string num, const string id, const string pw) {
	this->m_gen_name=name;
	this->m_social_num=num;
	this->mem_id=id;
	this->mem_pw=pw;
	this->is_gen = 1;
}

/**
 * 회사 회원의 회원가입을 위한 입력받은 정보 저장
 * 
 * @param name : 회사 이름
 * @param num : 사업자 번호
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return nothing
 * @return nothing
*/
void CompMember::createCompanyMember(const string name, const string num, const string id, const string pw) {
	this->m_company_name=name;
	this->m_business_num=num;
	this->mem_id=id;
	this->mem_pw=pw;
	this->is_comp = 1;
}
void CompMember::setRecruitment(string task, int num_of_people, time_t deadline) {
	RecruitInfo recruit;
	recruit.setRecruitment(task, num_of_people, deadline);
	m_recruit_list.push_back(recruit);
}

void GenMember::addApply(ApplyInfo apply)
{
	m_apply_list.push_back(apply);
}
