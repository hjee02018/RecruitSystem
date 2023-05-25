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
void Member::addNewGeneralMember(const string* name, const string* num, const string* id, const string* pw) {
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

/**
 * 회사 회원 저장
 * @param name : 회원 이름
 * @param num : 사업자 번호
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return nothing
 * @throws nothing
*/
void Member::addNewCompanyMember(const string* name, const string* num, const string* id, const string* pw) {
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

/**
 * 로그인 시 id 와 pw 가 일치하는지 확인
 * 
 * @param id : 회원 id
 * @param pw : 회원 pw
 * @return boolean : 일치하면 1, 불일치하면 0
 * @throws 불일치할 경우 로그인 불가
*/
bool Member::checkValidation(const string* id, const string* pw) {
	if (strcmp(memId, id) == 0 && strcmp(memPw, pw) == 0) {
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
void Member::toDeleteMemberAuth(string* id) {
	strcpy_s(id, MAX_STRING, memId);
}

/**
 * 로그아웃을 위해 id 확인
 * 
 * @param id : 회원 id
 * @return nothing
 * @throws nothing
*/
void Member::toLogout(string* id) {
	strcpy_s(id, MAX_STRING, memId);
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
void GenMember::createGeneralMember(const string* name, const string* num, const string* id, const string* pw) {
	strcpy_s(genName, MAX_STRING + 1, name);
	strcpy_s(socialNum, MAX_STRING + 1, num);
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);

	isGen = 1;
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
void CompMember::createCompanyMember(const string* name, const string* num, const string* id, const string* pw) {
	strcpy_s(companyName, MAX_STRING + 1, name);
	strcpy_s(businessNum, MAX_STRING + 1, num);
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);

	isComp = 1;
}
void CompMember::setRecruitment(string task, int num_of_people, time_t deadline) {
	recruitment.setRecruitment(task, num_of_people, deadline);
}