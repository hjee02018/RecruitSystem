#include "recruitSystem.h"
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;



void doTask();

void program_exit();//6 1

int main()
{
	errno_t input = fopen_s(&in_fp, INPUT_FILE_NAME, "r");
	errno_t ouput = fopen_s(&out_fp, OUTPUT_FILE_NAME, "w");

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

		switch (menu_level_1)
		{
		case 1:
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
		}
		return;
	}
}

void program_exit()
{
	fprintf_s(out_fp, "6.1. 종료\n");
}

// 양현지_add
void CancelApplyInfoUI::startInterface()
{
	cout << "취소할 지원 정보를 선택하시오" << endl;
}


void CancelApplyInfoUI::cancelApplyInfo(int params)
{
	m_cancelApplyInfo.cancelApplcyInfo(params);
}

void GetApplyCountUI::startInterface()
{
	cout << "지원 횟수 정보 출쳑" << endl;
}


void GetApplyCountUI::getApplyCount()
{
	m_getApplyCount.getApplyCount();
}

void GetRecruitStatusUI::startInterface()
{
	cout << "지원자 통계 정보 출력" << endl;
}

void GetRecruitStatusUI::getRecruitStatus()
{
	m_getRecruitStats.getRecruitStatus();
}

void ShowApplyInfoUI::showApplyInfo()
{
	m_showApplyInfo.showApplyInfo();
}


void ShowApplyInfoUI::startInterface()
{
	cout << "지원 정보 조회" << endl;
}

void CancelApplyInfo::cancelApplcyInfo(int params)
{
	m_genMember.cancelApplyInfo(params);
}

// genMember가 자신의 업무별 지원 횟수 통계를 확인
void GetApplyCount::getApplyCount()
{
	m_genMember.getDepartApplyCount();
}

void GetRecruitStatus::getRecruitStatus()
{
	m_compMember.getRecruitDepartInfo();
}

// for all applyinfo's of genmember to call showinfo
void ShowApplyInfo::showApplyInfo()
{
	m_genMember.showApplyInfo();
}

/**
 * to show ApplyInfo
 */
void ApplyInfo::showInfo()
{
	cout << "[회사 이름 : " << m_companyName <<
		" 업무 : " << m_departName <<
		" 인원수 : " << m_headCount <<
		" 신청 마감일 : " << m_endDate << "]" << endl;
}



void CompMember::getRecruitDepartInfo()
{
	list<RecruitInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_recruitlist.begin(); it != m_recruitlist.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepartName())
				iter->second++;
			else
				applyMap[it->getDepartName()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		cout << "업무 : " << iter->first << " 지원자수 : " << iter->second << endl;
}


/**
 * m_applyList의 ApplyInfo를 모두 보여줌
 *
 */
void GenMember::showApplyInfo()
{
	list<ApplyInfo>::iterator it;
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		it->showInfo();
}

/**
 * m_applyList의 ApplyInfo 삭제(지원 취소 기능)
 *
 * @ input ( params ) : 삭제 할 지원 정보
 */
void GenMember::cancelApplyInfo(int params)
{
	list<ApplyInfo>::iterator it;
	int i = 0;
	for (it = m_applyList.begin(); i < params; it++, i++)
		it++;
	m_applyList.erase(it);
}
/**
 * m_applyList의 departName별 count 출력
 *
 */
void GenMember::getDepartApplyCount()
{
	list<ApplyInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepart())
				iter->second++;
			else
				applyMap[it->getDepart()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		cout << "업무 : " << iter->first << " 지원횟수 : " << iter->second << endl;
}


/**
 * to return num of apply
 *
 * @return m_numOfApply
 */
int RecruitInfo::getRecruitCount()
{
	return m_numOfApply;
}

string RecruitInfo::getDepartName()
{
	return m_departName;
}