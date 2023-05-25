#include "RecruitManagement.h"

/**
 * 파일에서 업무, 인원 수, 신청 마감일 입력받아 채용 정보 등록
 *
 * @param compMember <- 회사 회원의 ID 정보가 필요
 * @param in_fp file input. <- "매개변수2"
 * @return void <- "반환값"
 */
void AddRecruitmentUi::startInterface(string& task, int& num_of_people, time_t& deadline, FILE *in_fp)
{
    // 입력 형식 : 업무, 인원 수, 신청 마감
    fscanf(in_fp, "%s %d %lld", task, num_of_people, deadline);
}
/**
 *  업무, 인원 수, 신청 마감일 출력
 *
 * @param recruitment <- 앞서 생성한 recruitment객체 
 * @param num2 FILE* out_fp <- "매개변수2"
 *
 */ 
void AddRecruitmentUi::createNewRecruitment(CompMember compMember,string task, int num_of_people, time_t deadline,FILE* out_fp)
{
    AddRecruitment addRecruitment;
    RecruitInfo recruitment = addRecruitment.addNewRecruitment(compMember, task, num_of_people, deadline);                                                
    fprintf(out_fp, "3.1. 채용 정보 등록\n");
    //업무, 인원 수, 신청 마감일 출력
    fprintf(out_fp, "%s %d %lld \n", recruitment.getTask(), recruitment.getNumOfPeople(), recruitment.getDeadline());
}

/**
 * 회사 회원 ID를 이용해 회원이 등록한 채용 정보 리스트 출력
 *
 * @param company_name to find input company_name <- "매개변수1"
 * @return void <- "반환값"
 */
void RecruitmentListUi::selectRecruitmentList(CompMember compMember, FILE* out_fp) // 접속자의 ID가 필요
{
    ShowRecruitmentList recruitment_list;
    list<RecruitInfo> recruitment = recruitment_list.showRecruitmentList(compMember);
    fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
    //업무, 인원 수, 신청 마감일 출력
    for(auto it = recruitment.begin(); it != recruitment.end(); it++){
        fprintf(out_fp, "%s %d %lld \n", (*it).getTask(), (*it).getNumOfPeople(), (*it).getDeadline());
    }
    
}

/**
 * shows the start screen and receives input from the user.<- "함수가 수행하는 작업"
 *
 * @param num1 The file input <- "매개변수1"
 * @return input(= company_name). <- "반환값"
 */
int ApplyUi::startInterface(FILE *in_fp)
{
    int business_number;
    // 입력 형식 : 회사 이름을 파일로부터 읽음
    fscanf(in_fp, "%d", &business_number);
    
    return business_number;
}

/**
 * enter the company number to apply for that company.
 *
 * @param business_number to find input business_number  <- "매개변수1"
 * @param out_fp file output. <- "매개변수2"
 * @return void <- "반환값"
 */
void ApplyUi::apply(int business_number, FILE* out_fp)
{
    
    ApplyCompany apply_company;
    ApplyInfo applyInfo = apply_company.applyCompany(business_number);
    
    // [회사이름] [사업자번호] [업무]
    string company_name = applyInfo.getCompanyName();
    string task = applyInfo.getTask();
                                                      
    fprintf(out_fp, "4.2. 채용 지원\n");
    fprintf(out_fp, "%s %d %s \n", company_name.c_str(), business_number, task.c_str());
    
}


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
    vector<RecruitInfo> recruit_infos;
    recruit_infos.push_back(search.showRecruitmentInfoByCompanyName(company_name));
    
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

/**
 * control
 * recruitment 객체를 생성 후 반환
 *
 * @param compMember <- 회사 회원의 ID 정보가 필요
 * @param task <- 업무
 * @param num_of_people <- 인원 수
 * @param deadline <- 신청 마감일
 * @return  recruitment <- 객체
 */
RecruitInfo AddRecruitment::addNewRecruitment(CompMember compMember, string task, int num_of_people, time_t deadline)
{
    RecruitInfo recruitment;
    recruitment.setRecruitment(task, num_of_people, deadline);
    compMember.setRecruitment(task, num_of_people, deadline);
    return recruitment;
}

list<RecruitInfo> ShowRecruitmentList::showRecruitmentList(CompMember comp_member) {
    return comp_member.getRecruitment();
}


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

    for(int i=0; i<num_comp; i++){
        list<RecruitInfo> recruit_infos = comp[i].getRecruitment();
        recruit_info_list.insert(recruit_info_list.end(), recruit_infos.begin(), recruit_infos.end());
    }
    
    for(int i=0; i< recruit_info_list.size(); i++)
    {
        if(recruit_info_list[i].getBusinessNumber() == business_number)
        {
            string company_name = recruit_info_list[i].getCompanyName();
            int business_number = recruit_info_list[i].getBusinessNumber();
            string task = recruit_info_list[i].getTask();
            
            ApplyInfo applyInfo(company_name, business_number, task);
            gen[now_idx].addApply(applyInfo);
            recruit_info_list[i].addNewApply(applyInfo);
            return applyInfo;
        }
    }
    throw runtime_error("지원하려는 회사 번호가 없습니다.");
}

/**
 * Show recriutment listings that match the company name order by company name asc
 *
 * @param company_name search for company_name. <- "매개변수1"
 * @return matching company
 * @throws runtime_error If it can't find a matching company <- "예외 처리"
 */

RecruitInfo Search::showRecruitmentInfoByCompanyName(string company_name)
{
    
    vector<RecruitInfo> recruit_info_list;
    
    for(int i=0; i<num_comp; i++){
        list<RecruitInfo> recruit_infos = comp[i].getRecruitment();
        recruit_info_list.insert(recruit_info_list.end(), recruit_infos.begin(), recruit_infos.end());
    }
        
    for(int i =0; i<recruit_info_list.size(); i++){
        if(recruit_info_list[i].getCompanyName() == company_name)
        {
            return recruit_info_list[i];
        }
    }
    throw runtime_error("회사 이름과 일치하는 결과가 없습니다.");
}
