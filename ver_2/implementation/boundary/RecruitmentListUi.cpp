#include "RecruitmentListUi.hpp"

/**
 * 
 */
void RecruitmentListUi::startInterface()
{
    //입력 내용 없음
}

/**
 * 회사 회원 ID를 이용해 회원이 등록한 채용 정보 리스트 출력
 *
 * @param company_name to find input company_name <- "매개변수1"
 * @return void <- "반환값"
 */
void RecruitmentListUi::selectRecruitmentList(vector<RecruitInfo> recruitmentList, CompMember compMember, FILE* out_fp) // 접속자의 ID가 필요
{
    fprintf(out_fp, "3.2. 등록된 채용 정보 조회 \n");
    for (int i=0; i<recruitmentList.size(); i++) { // recruitmentList 배열 반복
        if (recruitmentList[i].getID()==compMember.getID()) { //등록된 채용 정보의 ID와 로그인한 회원의 ID가 같다면
            fprintf(out_fp, "%s %d %lld \n", recruitmentList[i].getTask(), recruitmentList[i].getNumPeople(), recruitmentList[i].getDeadline());
        }// 그 채용 정보의 내용 출력       
    }
}