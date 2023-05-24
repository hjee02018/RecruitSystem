#include "MemberManagement.h"
#include "ApplyMangement.h"
#include "Member.h"

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

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
bool Member::checkValidation(const string* id, const string* pw) {
	if (strcmp(memId, id) == 0 && strcmp(memPw, pw) == 0) {
		return 1;
	}
	else return 0;
}
void Member::toDeleteMemberAuth(string* id) {
	strcpy_s(id, MAX_STRING, memId);
}
void Member::toLogout(string* id) {
	strcpy_s(id, MAX_STRING, memId);
}


void GenMember::createGeneralMember(const string* name, const string* num, const string* id, const string* pw) {
	strcpy_s(genName, MAX_STRING + 1, name);
	strcpy_s(socialNum, MAX_STRING + 1, num);
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);

	isGen = 1;
}


void CompMember::createCompanyMember(const string* name, const string* num, const string* id, const string* pw) {
	strcpy_s(companyName, MAX_STRING + 1, name);
	strcpy_s(businessNum, MAX_STRING + 1, num);
	strcpy_s(memId, MAX_STRING + 1, id);
	strcpy_s(memPw, MAX_STRING + 1, pw);

	isComp = 1;
}