#include "ApplyManagement.h"

/**
 * 일반 회원 지원 취소 인터페이스 시작
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * 취소 할 지원의 사업자 번호 반환
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * 일반회원의 지원 통계 기능 
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * 일반회원의 업무별 지원 횟수 통계
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * 회사 회원의 채용정보 통계 기능 인터페이스
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * 회사회원이 등록한 채용정보의 업무별 지원자 통계 제공
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  ì§??› ? •ë³? ì¶œë ¥
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * 지원 정보 조회 인터페이스
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * 일반회원이 comp_no와 일치하는 지원 정보를 취소
 * 
 * @ input ( params ) : 취소할 지원 정보의 사업자번호
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * 일반회원의 지원 통계 기능
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * 회사회원의 채용 통계 제공
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * 일반 회원의 모든 지원 정보 조회
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
