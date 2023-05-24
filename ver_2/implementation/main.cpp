// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "MemberManagement.h"
#include "RecruitManagement.h"
#include "ApplyManagement.h"


// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// 변수 선언
FILE* in_fp, *out_fp;

int main()
{
  // 파일 입출력을 위한 초기화
  FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
  FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

  ...

  doTask();

  ...

  return 0;
}


void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    while(!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        
        
        // 메뉴 구분 및 해당 연산 수행
        switch(menu_level_1)
        {
            case 1:
            {
                switch(menu_level_2)
                {
                    case 1:   // "1.1. 회원가입“ 메뉴 부분
                    {
                        // join() 함수에서 해당 기능 수행
                        join();
                        
                        break;
                    }
                    case 2:
                    {
                        break;
                    }
                } // 1 -
            }
            case 3:
            {
                switch(menu_level_2)
                case 1:
                {
                    AddRecruitmentUi addRecruitmentUi;
                    string task;
                    int num_of_people;
                    time_t deadline;
                    addRecruitmentUi.startInterface(task,num_of_people,deadline,in_fp);
                    addRecruitmentUi.createNewRecruitment(compMember,task,num_of_people,deadline);
                    break;
                }
                case 2:
                {
                    RecruitmentListUi recruitmentListUi;
                    recruitmentListUi.selectRecruitmentList(compMember,out_fp);
                }
            }
            case 4:
            {
                switch (menu_level_2) {
                    case 1: // 4.1 채용 정보 검색
                    {
                        SearchUi search_ui;
                        string company_name = search_ui.startInterface(in_fp);
                        search_ui.searchRecruitmentInfoByCompanyName(company_name, out_fp);
                        
                        break;
                    }
                    case 2: // 4.2 채용 지원
                    {
                        ApplyUi apply_ui;
                        int business_number = apply_ui.startInterface(in_fp);
                        apply_ui.apply(business_number, out_fp);
                        break;
                    }
                }
            }
            case 6:
            {
                switch(menu_level_2)
                {
                    case 1:   // "6.1. 종료“ 메뉴 부분
                    {
                        program_exit();
                        is_program_exit = 1;
                        break;
                    }
                }
            } // 6 -
        }
    }
    return;
}


void join()
{
  /*            !!!!!!!       중요        !!!!!!!!!
   * 단순히 파일을 통해 입출력하는 방법을 보이기 위한 코드이므로 이 함수에서 그대로 사용하면 안됨.
   * control 및 boundary class를 이용해서 해당 기능이 구현되도록 해야 함.
   */

   char user_type[MAX_STRING], name[MAX_STRING], SSN[[MAX_STRING],
        address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

   // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
   fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

  
  // 해당 기능 수행
   ...

   // 출력 형식
   fprintf(out_fp, "1.1. 회원가입\n");
   fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}


void program_exit()
{
   ....
}
