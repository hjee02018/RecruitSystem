#include "SearchUi.hpp"

/**
 * shows the start screen and receives input from the user.<- "함수가 수행하는 작업"
 *
 * @param in_fp The file input <- "매개변수1"
 * @return input(= company_name). <- "반환값"
 */
string SearchUi::startInterface(FILE* in_fp)
{
    
    char company_name[MAX_STRING];
    // 입력 형식 : 회사 이름을 파일로부터 읽음
    fscanf(in_fp, "%s", company_name);
    
    return company_name;
}

/**
 * A function that returns the appropriate result based on the company name entered by the user.<- "함수가 수행하는 작업"
 *
 * @param company_name to find input company_name <- "매개변수1"
 * @param out_fp file output. <- "매개변수2"
 * @return void <- "반환값"
 */
void SearchUi::searchRecruitmentInfoByCompanyName(string company_name, FILE* out_fp)
{
    
    Search search;
    vector<RecruitInfo> recruit_infos = search.showRecruitmentInfoByCompanyName(company_name);
    
    fprintf(out_fp, "4.1. 채용 정보 검색\n");
    for(int i=0; i< recruit_infos.size(); i++)
    {
        string company_name = recruit_infos[i].getCompanyName();
        int business_number = recruit_infos[i].getBusinessNumber();
        string task = recruit_infos[i].getTask();
        int num_of_people = recruit_infos[i].getNumOfPeople();
        time_t deadline = recruit_infos[i].getDeadline();
        
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y/%m/%d", localtime(&deadline));
        fprintf(out_fp, "%s %d %s %d %s \n", company_name.c_str(), business_number, task.c_str(), num_of_people, buffer);
    }
    return ;
}
