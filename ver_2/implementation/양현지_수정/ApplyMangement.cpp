#include "ApplyMangement.h"

/**
 * 지원 취소 기능 출력
 */
void CancelApplyInfoUI::startInterface()
{
	cout << "4.4 지원 취소" << endl;

}

/**
 * 일반 회원이 취소할 지원 정보를 선택하여 취소 요청
 * 
 * @ input ( params ) : 취소 할 지원 정보
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
 * 업무별 지원 횟수 정보 통계 기능 출력
 */
void GetApplyCountUI::startInterface()
{
	cout << "지원 횟수 정보 출쳑" << endl;
}

/**
 * 지원 정보 통계 기능 선택
 */
void GetApplyCountUI::getApplyCount()
{
	m_getApplyCount.getApplyCount();
}


/**
 * 채용 정보 통계 기능 선택
 */
void GetRecruitStatusUI::startInterface()
{
	cout << "지원자 통계 정보 출력" << endl;
}


/**
 * 채용 정보 통계 기능 선택
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_getRecruitStats.getRecruitStatus();
}


/**
 * 일반 회원이 지원 정보 내역 조회 기능을 사용하고자함
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_showApplyInfo.showApplyInfo();
}


/**
 * 지원 정보 내역 조회 기능 출력
 */
void ShowApplyInfoUI::startInterface()
{
	cout << "4.3 지원 정보 조회" << endl;
}


/**
 * 일반 회원이 삭제하고자 하는 지원 정보를 가지고 삭제 요청을 수행
 * 
 * @ input ( params ) : 삭제 할 지원 정보
 */
void CancelApplyInfo::cancelApplcyInfo(string compName, int compNo, string departName)
{
	m_genMember.cancelApplyInfo(compName, compNo, departName);
}

/**
 * 일반 회원이 지원한 지원 정보의 업무별 지원 횟수 통계 확인
 */
void GetApplyCount::getApplyCount()
{
	m_genMember.getDepartApplyCount();
}

/**
 * 회사 회원이 등록한 채용 정보 요청
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_compMember.getRecruitDepartInfo();
}

/**
 * 일반 회원의 모든 지원 정보 출력
 */
void ShowApplyInfo::showApplyInfo()
{
	m_genMember.showApplyInfo();
}

/**
 * 지원 정보 출력(회사이름, 업무, 인원수, 신청 마감일)
 */
void ApplyInfo::showInfo()
{
	cout << "[회사 이름 : " << m_companyName <<
		" 업무 : " << m_departName <<
		" 인원수 : " << m_headCount <<
		" 신청 마감일 : " << m_endDate << "]" << endl;
}


/**
 * 회사회원의 업무별 지원자 횟수 정보 출력
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

/**
 * to return name of department
 *
 * @return m_departName
 */
string RecruitInfo::getDepartName()
{
	return m_departName;
}