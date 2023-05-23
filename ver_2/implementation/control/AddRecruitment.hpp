#ifndef AddRecruitment_hpp
#define AddRecruitment_hpp

#include <iostream>
#include <vector>
#include "CompMember.hpp"
#include "RecruitInfo.hpp"

using namespace std;

/**
 * control class, 로그인 한 회사회원이 채용 등록, RecruitInfo 객체를 생성하여 반환
 * 로그인 되어있는 CompMember의 ID필요
 *
 */
class AddRecruitment
{
public:
    RecruitInfo addNewRecruitment(CompMember c, string task, int numPeople, time_t deadline);
};
#endif AddRecruitment_hpp