#include "ApplyManagement.h"

/**
 * ?��반회?��?�� �??��취소 기능?�� ?��?��
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * �??�� 취소 기능?�� ?��?��
 * 
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * �??�� ?���? 기능?�� ?���?
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * �??�� ?���? 기능 ?��?��
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * 채용 ?���? ?���? 기능?�� ?���?
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * 채용 ?���? 기능 구현
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  �??�� ?���? 출력
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * �??�� ?���? 출력 기능 ?��?��
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * ?��반회?��?�� �??�� ?��보�?? 취소
 * 
 * @ input ( params ) : 취소?�� �??�� ?���?
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * ?���? ?��?��?�� ?��무별 �??�� ?��?�� 출력
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * ?��?�� ?��?��?�� ?��무별 �??��?��?�� 출력
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * ?��반회?��?�� �??�� ?���? 출력
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
