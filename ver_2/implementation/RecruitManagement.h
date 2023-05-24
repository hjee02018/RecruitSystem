#ifndef RecruitManagement.h
#define RecruitManagement.h

#include <iostream>
#include <string>
#include "RecruitInfo.h"
#include "CompMember.h"
#include "ApplyInfo.h"
#include "ApplyInfoCollection.h"
using namespace std;

/**
 * 채용 정보 등록
 * 업무, 인원 수, 신청 마감일 정보를 입력받아 recruitment객체를 생성
 */
class AddRecruitmentUi
{
public:
    void createNewRecruitment(CompMember compMember, string task, int num_of_people, time_t deadline,FILE* out_fp);
    void startInterface(string& task, int& num_of_people, time_t& deadline, FILE *in_fp);
};
/**
 * Represents a search boundary <- "클래스의 역할"
 *
 */
class RecruitmentListUi
{
public:
    void selectRecruitmentList(CompMember compMember, FILE* out_fp);
};
/**
 * Represents a apply boundary <- "클래스의 역할"
 *
 */
class ApplyUi
{
public:
    void apply(int business_number, FILE* out_fp);
    int startInterface(FILE* in_fp);
};

/**
 * Represents a search boundary <- "클래스의 역할"
 *
 */
class SearchUi
{
public:
    string startInterface(FILE* in_fp);
    void searchRecruitmentInfoByCompanyName(string company_name, FILE* out_fp);
};
/**
 * control class, 로그인 한 회사회원이 채용 등록, RecruitInfo 객체를 생성하여 반환
 * 로그인 되어있는 CompMember의 ID필요
 *
 */
class AddRecruitment
{
public:
    RecruitInfo addNewRecruitment(CompMember compmember, string task, int numPeople, time_t deadline);
};
/**
 * Represents boundary <- "클래스의 역할"
 *
 */

class ShowRecruitmentList
{
public:
    void showRecruitmentList(CompMember CompMember);
};

/**
 * Represents a Apply control <- "클래스의 역할"
 *
 */
class ApplyCompany
{
public:
    ApplyInfo applyCompany(int business_number);
};

/**
 * Represents a Search control <- "클래스의 역할"
 *
 */
class Search
{
public:
    RecruitInfo showRecruitmentInfoByCompanyName(string company_name);
};
#endif RecruitManagement.h