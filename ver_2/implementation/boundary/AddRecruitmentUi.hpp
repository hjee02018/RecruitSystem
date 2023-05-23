#ifndef AddRecruitmentUi_hpp
#define AddRecruitmentUi_hpp

#include <iostream>
#include <string>
#include "RecruitInfo.hpp"
#include "CompMember.hpp"

using namespace std;

/**
 * 채용 정보 등록
 * 업무, 인원 수, 신청 마감일 정보를 입력받아 recruitment객체를 생성
 */
class AddRecruitmentUi
{
public:
    void createNewRecruitment(RecruitInfo recruitment,FILE* out_fp);
    RecruitInfo startInterface(CompMember compMember, FILE* in_fp);
};
#endif AddRecruitmentUi_hpp