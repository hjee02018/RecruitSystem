// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "MemberManagement.h"
#include "RecruitManagement.h"
#include "ApplyManagement.h"
#include "./entity/ApplyInfo.h"
#include "./entity/RecruitInfo.h"
#include "./entity/Member.h"
#include "./entity/ApplyInfoCollection.h"

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

  doTask();

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
                        AddMember addmember;
                        addmember.addMember();
                        break;
                    }
                    case 2: // 1.2. 회원 탈퇴
                    {
                        DeleteMember deletemember;
				        deletemember.deleteMemberAuth();
                        break;
                    }
                } // 1 -
            }
            case 2:
            {
                switch(menu_level_2)
                {
                    case 1: // 2.1. 로그인
                    {
                        Login login;
				        login.tryLogin();
                        break;
                    }
                    case 2: // 2.2. 로그아웃
                    {
                        Logout logout;
				        logout.tryLogout();
                        break;
                    }
                }
            }
            case 3:
            {
                switch(menu_level_2){
                    case 1:
                    {
                        AddRecruitmentUi addRecruitmentUi;
                        string task;
                        int num_of_people;
                        time_t deadline;
                        addRecruitmentUi.startInterface(task,num_of_people,deadline,in_fp);
                        addRecruitmentUi.createNewRecruitment(comp[now_idx],task,num_of_people,deadline,out_fp);
                        break;
                    }
                    case 2:
                    {
                    RecruitmentListUi recruitmentListUi;
                    recruitmentListUi.selectRecruitmentList(comp[now_idx],out_fp);
                    }
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


void program_exit()
{
}
