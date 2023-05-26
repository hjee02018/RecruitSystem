#include "ApplyManagement.h"

/**
 * ?���? ?��?�� �??�� 취소 ?��?��?��?��?�� ?��?��
 */
void CancelApplyInfoUI::startInterface()
{
}

/**
 * 취소 ?�� �??��?�� ?��?��?�� 번호 반환
 */
int CancelApplyInfoUI::cancelApplyInfo()
{
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	int ret;
	fscanf(in_fp, "%d", ret);
	return ret;
}

/**
 * ?��반회?��?�� �??�� ?���? 기능 
 */
void GetApplyCountUI::startInterface()
{
}

/**
 * ?��반회?��?�� ?��무별 �??�� ?��?�� ?���?
 */
void GetApplyCountUI::getApplyCount()
{
	m_get_apply_count.getApplyCount();
}


/**
 * ?��?�� ?��?��?�� 채용?���? ?���? 기능 ?��?��?��?��?��
 */
void GetRecruitStatusUI::startInterface()
{
}


/**
 * ?��?��?��?��?�� ?��록한 채용?��보의 ?��무별 �??��?�� ?���? ?���?
 */
void GetRecruitStatusUI::getRecruitStatus()
{
	m_get_recruit_stats.getRecruitStatus();
}


/**
 *  ì§????��? ? ??�ë�?? ì¶œë ¥
 */
void ShowApplyInfoUI::showApplyInfo()
{
	m_show_apply_info.showApplyInfo();
}


/**
 * �??�� ?���? 조회 ?��?��?��?��?��
 */
void ShowApplyInfoUI::startInterface()
{
}


/**
 * ?��반회?��?�� comp_no??? ?��치하?�� �??�� ?��보�?? 취소
 * 
 * @ input ( params ) : 취소?�� �??�� ?��보의 ?��?��?��번호
 */
void CancelApplyInfo::cancelApplcyInfo(int comp_no)
{
	m_gen_member.cancelApplyInfo(comp_no);
}

/**
 * ?��반회?��?�� �??�� ?���? 기능
 */
void GetApplyCount::getApplyCount()
{
	m_gen_member.getDepartApplyCount();
}

/**
 * ?��?��?��?��?�� 채용 ?���? ?���?
 */
void GetRecruitStatus::getRecruitStatus()
{
	m_comp_member.getRecruitDepartInfo();
}

/**
 * ?���? ?��?��?�� 모든 �??�� ?���? 조회
 */
void ShowApplyInfo::showApplyInfo()
{
	m_gen_member.showApplyInfo();
}
