#include "ApplyUi.hpp"

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
