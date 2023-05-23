#include "AddRecruitmentUi.hpp"
#include "AddRecruitment.hpp"
#include <vector>
using namespace std;

/**
 * recruitment 객체를 생성 후 반환
 *
 * @param compMember <- 회사 회원의 ID 정보가 필요
 * @param task <- 업무
 * @param numPeople <- 인원 수
 * @param deadline <- 신청 마감일
 * @return  recruitment <- 객체
 */
RecruitInfo addNewRecruitment(CompMember compMember, string task, int numPeople, time_t deadline)
{
    string ID = compMember.getID();
    RecruitInfo recruitment(ID, task, numPeople, deadline);
    return recruitment;
}

