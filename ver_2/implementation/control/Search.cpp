#include "Search.hpp"

/**
 * Show recriutment listings that match the company name order by company name asc
 *
 * @param company_name search for company_name. <- "매개변수1"
 * @return matching company
 * @throws runtime_error If it can't find a matching company <- "예외 처리"
 */
RecruitInfo Search::showRecruitmentInfoByCompanyName(string company_name)
{
    /**
     어떻게 얻어올지....?
     */
    vector<RecruitInfo> recruit_info_dao; // 저장된 채용 정보 리스트 ? 모든 회사직원들중 반복하면서 찾아야하나?
    
    
    for(int i =0; i<recruit_info_dao.size(); i++){
        if(recruit_info_dao[i].getCompanyName() == company_name)
        {
            return recruit_info_dao[i];
        }
    }
    throw runtime_error("회사 이름과 일치하는 결과가 없습니다.");
}
