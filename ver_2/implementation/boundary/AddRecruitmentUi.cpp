#include "AddRecruitmentUi.hpp"
#include "AddRecruitment.hpp"
#include "AddRecruitment.hpp"
#include <vector>
using namespace std;

/**
 * 파일에서 업무, 인원 수, 신청 마감일 입력받아 채용 정보 등록
 *
 * @param compMember <- 회사 회원의 ID 정보가 필요
 * @param in_fp file input. <- "매개변수2"
 * @return void <- "반환값"
 */
RecruitInfo AddRecruitmentUi::startInterface(CompMember compMember,FILE *in_fp)
{
    string ID = compMember.getID(); // 회사 회원 ID
    string task;
    int numPeople;
    time_t deadline;
    // 입력 형식 : 업무, 인원 수, 신청 마감
    fscanf(in_fp, "%s %d %lld", task, numPeople, deadline);
    RecruitInfo recruitment(ID, task, numPeople, deadline); //Recruitment 객체 생성
    return recruitment; 
}
/**
 *  업무, 인원 수, 신청 마감일 출력
 *
 * @param recruitment <- 앞서 생성한 recruitment객체 
 * @param num2 FILE* out_fp <- "매개변수2"
 *
 */ 
void AddRecruitmentUi::createNewRecruitment(RecruitInfo recruitment,FILE* out_fp)
{
                                                    
    fprintf(out_fp, "3.1. 채용 정보 등록\n");
    //업무, 인원 수, 신청 마감일 출력
    fprintf(out_fp, "%s %d %lld \n", recruitment.getTask(), recruitment.getNumPeople(), recruitment.getDeadline());
    
}