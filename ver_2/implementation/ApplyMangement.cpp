#include "ApplyManagement.h"

/**
 * ���� ��� ��� ���
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * �Ϲ� ȸ���� ����� ���� ������ �����Ͽ� ��� ��û
 * 
 * @ input ( params ) : ��� �� ���� ����
 */
void CancelApplyInfoUI::cancelApplyInfo()
{
	string compName;
	int compNo;
	string departName;
	cin >> compName >> compNo >> departName;
	m_cancelApplyInfo.cancelApplcyInfo(compName, compNo, departName);
}

/**
 * ������ ���� Ƚ�� ���� ��� ��� ���
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * ���� ���� ��� ��� ����
 */
void GetApplyCountUI::getApplyCount()
{
	m_getApplyCount.getApplyCount();
}


/**
 * ä�� ���� ��� ��� ����
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * ä�� ���� ��� ��� ����
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_getRecruitStats.getRecruitStatus();
}


/**
 * �Ϲ� ȸ���� ���� ���� ���� ��ȸ ����� ����ϰ�����
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_showApplyInfo.showApplyInfo();
}


/**
 * ���� ���� ���� ��ȸ ��� ���
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * �Ϲ� ȸ���� �����ϰ��� �ϴ� ���� ������ ������ ���� ��û�� ����
 * 
 * @ input ( params ) : ���� �� ���� ����
 */
void CancelApplyInfo::cancelApplcyInfo(string compName, int compNo, string departName)
{
	m_genMember.cancelApplyInfo(compName, compNo, departName);
}

/**
 * �Ϲ� ȸ���� ������ ���� ������ ������ ���� Ƚ�� ��� Ȯ��
 */
void GetApplyCount::getApplyCount()
{
	m_genMember.getDepartApplyCount();
}

/**
 * ȸ�� ȸ���� ����� ä�� ���� ��û
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_compMember.getRecruitDepartInfo();
}

/**
 * �Ϲ� ȸ���� ��� ���� ���� ���
 */
void ShowApplyInfo::showApplyInfo()
{
	m_genMember.showApplyInfo(out_fp);
}



/**
 * ȸ��ȸ���� ������ ������ Ƚ�� ���� ���
 */
void CompMember::getRecruitDepartInfo()
{
	list<RecruitInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_recruit_list.begin(); it != m_recruit_list.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepartName())
				iter->second++;
			else
				applyMap[it->getDepartName()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		fprintf(out_fp, "%s %d\n", iter->first.c_str(), iter->second);
}


/**
 * m_applyList�� ApplyInfo�� ��� ������
 *
 */
void GenMember::showApplyInfo(FILE *out_fp)
{
	list<ApplyInfo>::iterator it;
	for (it = m_apply_list.begin(); it != m_apply_list.end(); it++)
		it->showInfo(out_fp);
}

/**
 * m_applyList�� ApplyInfo ����(���� ��� ���)
 *
 * @ input ( params ) : ���� �� ���� ����
 */
void GenMember::cancelApplyInfo(string compName, int compNo, string departName)
{
	list<ApplyInfo>::iterator it;
	int i = 0;
	for (it = m_apply_list.begin(); it != m_apply_list.end(); it++)
		if (it->getDepart() == departName)
			it->~ApplyInfo();
	
	m_apply_list.erase(it);
}

/**
 * m_applyList�� departName�� count ���
 *
 */
void GenMember::getDepartApplyCount()
{
	list<ApplyInfo>::iterator it;
	map<string, int> applyMap;
	map<string, int>::iterator iter;
	for (it = m_apply_list.begin(); it != m_apply_list.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepart())
				iter->second++;
			else
				applyMap[it->getDepart()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		fprintf(out_fp, "%s %d\n", iter->first.c_str(), iter->second);
}


