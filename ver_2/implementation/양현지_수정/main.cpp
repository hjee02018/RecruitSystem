#include "ApplyMangement.h"
#include "MemberManagement.h"

#include<iostream>
#include<fstream>
#include<string.h>
#include <list>
using namespace std;

list <GenMember> g_genMemberlist;
list <CompMember> g_compMemberlist;

void doTask();

void program_exit();//6 1

int main()
{
	errno_t input = fopen_s(&in_fp, INPUT_FILE_NAME, "r");
	errno_t ouput = fopen_s(&out_fp, OUTPUT_FILE_NAME, "w");

	list<CompMember> m_compMemberlist;


	doTask();

}

void doTask()
{
	int menu_level_1 = 0, menu_level_2 = 0;
	int former_menu_level_1 = 0, former_menu_level_2 = 0;
	int is_program_exit = 0;
	while (!is_program_exit)
	{
		former_menu_level_1 = menu_level_1;
		former_menu_level_2 = menu_level_2;

		fscanf_s(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		int memberID;

		switch (menu_level_1)
		{
			// 2.1 �α����� �԰� ���ÿ� ID�� ����
		case 4:
			switch (menu_level_2)
			{
			case 3:
				// memberID�� ������ g_genMemberlist���� �ش� member�� showApplyInfo�Լ� ȣ��
				fprintf_s(out_fp, "4.3. ���� ���� ��ȸ\n");
				break;
			case 4:
				fprintf_s(out_fp, "4.4. ���� ���\n");
				break;
			default:
				break;
			}
		case 5:
			switch (menu_level_2)
			{
			case 1:
				fprintf_s(out_fp, "5.1. ���� ���� ���\n");
				break;
			default:
				break;
			}
		}
		/*case 1:
		{
			switch (menu_level_2)
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
			default:
				break;
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
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
			default:
				break;
			}
			break;
		}
		}*/
		return;
	}
}

void program_exit()
{
	fprintf_s(out_fp, "6.1. ����\n");
}
