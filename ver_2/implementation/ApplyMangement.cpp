#include "ApplyManagement.h"

/**
 * ?¼ë°˜íšŒ?›?´ ì§??›ì·¨ì†Œ ê¸°ëŠ¥?„ ?„ ?ƒ
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * ì§??› ì·¨ì†Œ ê¸°ëŠ¥?„ ?ˆ˜?–‰
 * 
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * ì§??› ?†µê³? ê¸°ëŠ¥?„ ? œê³?
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * ì§??› ?†µê³? ê¸°ëŠ¥ ?‹¤?–‰
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * ì±„ìš© ? •ë³? ?†µê³? ê¸°ëŠ¥?„ ? œê³?
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * ì±„ìš© ?†µê³? ê¸°ëŠ¥ êµ¬í˜„
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
 * ì§??› ? •ë³? ì¶œë ¥ ê¸°ëŠ¥ ?„ ?ƒ
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * ?¼ë°˜íšŒ?›?´ ì§??› ? •ë³´ë?? ì·¨ì†Œ
 * 
 * @ input ( params ) : ì·¨ì†Œ?•  ì§??› ? •ë³?
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * ?¼ë°? ?šŒ?›?˜ ?—…ë¬´ë³„ ì§??› ?šŸ?ˆ˜ ì¶œë ¥
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * ?šŒ?‚¬ ?šŒ?›?˜ ?—…ë¬´ë³„ ì§??›??ˆ˜ ì¶œë ¥
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * ?¼ë°˜íšŒ?›?˜ ì§??› ? •ë³? ì¶œë ¥
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
