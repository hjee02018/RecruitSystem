// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "ApplyManagement.h"
#include "MemberManagement.h"
#include "RecruitManagement.h"

#include "./entity/ApplyInfo.h"
#include "./entity/RecruitInfo.h"
#include "./entity/Member.h"
#include "./entity/ApplyInfoCollection.h"


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


void doTask();
void program_exit();

int main()
{

    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    doTask();

    return 0;
}


void doTask()
{

    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    
    while(!is_program_exit)
    {

        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        
        

        switch(menu_level_1)
        {
            case 1:
            {
                switch(menu_level_2)
                {
                    case 1:  
                    {
                        AddMember addmember;
                        addmember.addMember();
                        break;
                    }
                    case 2: 
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
                    case 1: 
                    {
                        Login login;
                    login.tryLogin();
                        break;
                    }
                    case 2: 
                    {
                        Logout logout;
                    logout.tryLogout();
                        break;
                    }
                }
            }
            case 3:
            {
                switch(menu_level_2)
                {
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
                        break;
                    }
                }
            }
            case 4:
            {
                switch (menu_level_2) 
                {
                    case 1: 
                    {
                        SearchUi search_ui;
                        string company_name = search_ui.startInterface(in_fp);
                        search_ui.searchRecruitmentInfoByCompanyName(company_name, out_fp);
                        
                        break;
                    }
                    case 2: 
                    {
                        ApplyUi apply_ui;
                        int business_number = apply_ui.startInterface(in_fp);
                        apply_ui.apply(business_number, out_fp);
                        break;
                    }
                    case 3:
                    {
                        fprintf(out_fp, "4.3 지원 정보 조회\n");
                        ShowApplyInfoUI show_ui;
                        show_ui.startInterface();
                        show_ui.showApplyInfo();
                        gen[now_idx].showApplyInfo();
                        break;
                    }
                    case 4: 
                    {
                        fprintf(out_fp, "4.4 지원 취소\n");
                        CancelApplyInfoUI cancel_ui;
                        cancel_ui.startInterface();
                        int ret = cancel_ui.cancelApplyInfo();
                        ApplyInfo apply = gen[now_idx].cancelApplyInfo(ret);
                        fprintf(out_fp, "> %s %d %s \n",apply.getCompanyName().c_str(), apply.getNumber(), apply.getTask().c_str());
                        break;
                    }
                }
            }
            case 5:
            {
                fprintf(out_fp, "5.1 지원 정보 통계\n");
                switch (menu_level_2)
                {
                    case 1: 
                    {
                        
                        GetApplyCountUI count_ui;
                        count_ui.startInterface();
                        count_ui.getApplyCount();
                        gen[now_idx].getDepartApplyCount();

                        GetRecruitStatusUI status_ui;
                        status_ui.startInterface();
                        status_ui.getRecruitStatus();
                        comp[now_idx].getRecruitDepartInfo();
                        break;
                    }
                    default:
                        break;
                }
            }
            case 6:
            {
                switch(menu_level_2)
                {
                    case 1:   
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
    fprintf( out_fp,"6.1. 종료\n");
}