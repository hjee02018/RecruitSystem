#include "ApplyCompany.hpp"


/**
 * control class, search for recuritment information that matches the business number and apply for it.
 *
 * @param business_number input_business_number. <- "매개변수1"
 * @return apply information of matching company<- "반환값"
 * @throws runtime_error If it can't find a matching company <- "예외 처리"
 */
ApplyInfo ApplyCompany::applyCompany(int business_number)
{
    
    vector<RecruitInfo> recruit_info_list;

    for(int i=0; i<numComp; i++){
        recruit_info_list.push_back(comp[i].getRecruitment());
    }

    for(int i=0; i< recruit_info_list.size(); i++)
    {
        if(recruit_info_list[i].getBusinessNumber() == business_number)
        {
            string company_name = recruit_info_list[i].getCompanyName();
            int business_number = recruit_info_list[i].getBusinessNumber();
            string task = recruit_info_list[i].getTask();
            
            ApplyInfo applyInfo(company_name, business_number, task);
            recruit_info_list[i].addNewApply(applyInfo);
            return applyInfo;
        }
    }
    throw runtime_error("지원하려는 회사 번호가 없습니다.");
}
