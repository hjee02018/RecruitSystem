#include "ApplyManagement.h"

/**
 * ���� ��� ��� ���
 */
void CancelApplyInfoUI::startInterface()
{
	cout << "4.4 ���� ���" << endl;

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
	cout << "���� Ƚ�� ���� ��r" << endl;
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
	cout << "������ ��� ���� ���" << endl;
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
	cout << "4.3 ���� ���� ��ȸ" << endl;
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
	m_genMember.showApplyInfo();
}

/**
 * ���� ���� ���(ȸ���̸�, ����, �ο���, ��û ������)
 */
void ApplyInfo::showInfo()
{
	cout << "[ȸ�� �̸� : " << m_companyName <<
		" ���� : " << m_departName <<
		" �ο��� : " << m_headCount <<
		" ��û ������ : " << m_endDate << "]" << endl;
}


/**
 * ȸ��ȸ���� ������ ������ Ƚ�� ���� ���
 */
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
		cout << "���� : " << iter->first << " �����ڼ� : " << iter->second << endl;
}


/**
 * m_applyList�� ApplyInfo�� ��� ������
 *
 */
void GenMember::showApplyInfo()
{
	list<ApplyInfo>::iterator it;
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		it->showInfo();
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
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		if (it->getDepart() == departName)
			it->~ApplyInfo();
	
	m_applyList.erase(it);
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
	for (it = m_applyList.begin(); it != m_applyList.end(); it++)
		for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
			if (iter->first == it->getDepart())
				iter->second++;
			else
				applyMap[it->getDepart()] = 1;

	for (iter = applyMap.begin(); iter != applyMap.end(); iter++)
		cout << "���� : " << iter->first << " ����Ƚ�� : " << iter->second << endl;
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

/**
 * to return name of department
 *
 * @return m_departName
 */
string RecruitInfo::getDepartName()
{
	return m_departName;
}