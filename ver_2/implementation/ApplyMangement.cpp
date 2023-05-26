#include "ApplyManagement.h"

/**
 * ?¼ë°? ?šŒ?› ì§??› ì·¨ì†Œ ?¸?„°?˜?´?Š¤ ?‹œ?‘
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * ì·¨ì†Œ ?•  ì§??›?˜ ?‚¬?—…? ë²ˆí˜¸ ë°˜í™˜
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * ?¼ë°˜íšŒ?›?˜ ì§??› ?†µê³? ê¸°ëŠ¥ 
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * ?¼ë°˜íšŒ?›?˜ ?—…ë¬´ë³„ ì§??› ?šŸ?ˆ˜ ?†µê³?
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * ?šŒ?‚¬ ?šŒ?›?˜ ì±„ìš©? •ë³? ?†µê³? ê¸°ëŠ¥ ?¸?„°?˜?´?Š¤
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * ?šŒ?‚¬?šŒ?›?´ ?“±ë¡í•œ ì±„ìš©? •ë³´ì˜ ?—…ë¬´ë³„ ì§??›? ?†µê³? ? œê³?
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  Ã¬Â§????ºÂ? ?Â ??¢Ã«Â?? Ã¬Â¶Å“Ã«Â Â¥
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * ì§??› ? •ë³? ì¡°íšŒ ?¸?„°?˜?´?Š¤
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * ?¼ë°˜íšŒ?›?´ comp_no??? ?¼ì¹˜í•˜?Š” ì§??› ? •ë³´ë?? ì·¨ì†Œ
 * 
 * @ input ( params ) : ì·¨ì†Œ?•  ì§??› ? •ë³´ì˜ ?‚¬?—…?ë²ˆí˜¸
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * ?¼ë°˜íšŒ?›?˜ ì§??› ?†µê³? ê¸°ëŠ¥
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * ?šŒ?‚¬?šŒ?›?˜ ì±„ìš© ?†µê³? ? œê³?
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * ?¼ë°? ?šŒ?›?˜ ëª¨ë“  ì§??› ? •ë³? ì¡°íšŒ
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
