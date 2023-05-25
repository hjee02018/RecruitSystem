#include "ApplyManagement.h"

/**
 * 일반회원이 지원취소 기능을 선택
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * 지원 취소 기능을 수행
 * 
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	int ret;
	fscanf_s(in_fp, "%d", ret);
	return ret;
}

/**
 * 지원 통계 기능을 제공
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * 지원 통계 기능 실행
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * 채용 정보 통계 기능을 제공
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * 채용 통계 기능 구현
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  지원 정보 출력
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * 지원 정보 출력 기능 선택
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * 일반회원이 지원 정보를 취소
 * 
 * @ input ( params ) : 취소할 지원 정보
 */
void CancelApplyInfo::cancelApplcyInfo(int compNo)
{
	m_gen_member.cancelApplyInfo(compNo);
}

/**
 * 일반 회원의 업무별 지원 횟수 출력
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * 회사 회원의 업무별 지원자수 출력
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * 일반회원의 지원 정보 출력
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo(out_fp);
}
