#include "ApplyManagement.h"

/**
 * ?Όλ°ν??΄ μ§??μ·¨μ κΈ°λ₯? ? ?
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * μ§?? μ·¨μ κΈ°λ₯? ??
 * 
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * μ§?? ?΅κ³? κΈ°λ₯? ? κ³?
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * μ§?? ?΅κ³? κΈ°λ₯ ?€?
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * μ±μ© ? λ³? ?΅κ³? κΈ°λ₯? ? κ³?
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * μ±μ© ?΅κ³? κΈ°λ₯ κ΅¬ν
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  μ§?? ? λ³? μΆλ ₯
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * μ§?? ? λ³? μΆλ ₯ κΈ°λ₯ ? ?
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * ?Όλ°ν??΄ μ§?? ? λ³΄λ?? μ·¨μ
 * 
 * @ input ( params ) : μ·¨μ?  μ§?? ? λ³?
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * ?Όλ°? ??? ?λ¬΄λ³ μ§?? ?? μΆλ ₯
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * ??¬ ??? ?λ¬΄λ³ μ§???? μΆλ ₯
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * ?Όλ°ν?? μ§?? ? λ³? μΆλ ₯
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
