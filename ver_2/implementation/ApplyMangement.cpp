#include "ApplyManagement.h"

/**
 * ?Όλ°? ?? μ§?? μ·¨μ ?Έ?°??΄?€ ??
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * μ·¨μ ?  μ§??? ?¬?? λ²νΈ λ°ν
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * ?Όλ°ν?? μ§?? ?΅κ³? κΈ°λ₯ 
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * ?Όλ°ν?? ?λ¬΄λ³ μ§?? ?? ?΅κ³?
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * ??¬ ??? μ±μ©? λ³? ?΅κ³? κΈ°λ₯ ?Έ?°??΄?€
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * ??¬???΄ ?±λ‘ν μ±μ©? λ³΄μ ?λ¬΄λ³ μ§??? ?΅κ³? ? κ³?
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  Γ¬Β§????ΊΒ? ?Β ??’Γ«Β?? Γ¬ΒΆΕΓ«Β Β₯
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * μ§?? ? λ³? μ‘°ν ?Έ?°??΄?€
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * ?Όλ°ν??΄ comp_no??? ?ΌμΉν? μ§?? ? λ³΄λ?? μ·¨μ
 * 
 * @ input ( params ) : μ·¨μ?  μ§?? ? λ³΄μ ?¬??λ²νΈ
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * ?Όλ°ν?? μ§?? ?΅κ³? κΈ°λ₯
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * ??¬??? μ±μ© ?΅κ³? ? κ³?
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * ?Όλ°? ??? λͺ¨λ  μ§?? ? λ³? μ‘°ν
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
