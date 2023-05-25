#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
#include <map>
#include "MemberManagement.h"

using namespace std;

#define MAX_STRING 32
#define MAX_ACCOUNT 100

/**
 * 지원 취소 인터페이스를 시작하고 일반회원의 지원 취소 기능을 수행
 */
class CancelApplyInfo
{
private:
	GenMember m_gen_member;
public:
	void cancelApplcyInfo( int comp_no);
};


/**
 * 일반회원의 지원 횟수 통계 제공
 */
class GetApplyCount
{
private:
	GenMember m_gen_member;
public:
	void getApplyCount();
};

/**
 * 회사 회원의 채용 통계 제공
 */
class GetRecruitStatus
{
private:
	CompMember m_comp_member;
public:
	void getRecruitStatus();
};

/**
 * 일반 회원의 지원 정보 조회
 */
class ShowApplyInfo
{
private:
	GenMember m_gen_member;
public:
	void showApplyInfo();
};

/**
 * 지원 취소 인터페이스
 */
class CancelApplyInfoUI
{
private:
	CancelApplyInfo m_cancel_apply_info;
public:
	void startInterface();
	int cancelApplyInfo();
};

/**
 * 지원 횟수 통계 인터페이스
 */
class GetApplyCountUI
{
private:
	GetApplyCount m_get_apply_count;
public:
	void startInterface();
	void getApplyCount();
};

/**
 * 지원 조회 인터페이스
 */
class ShowApplyInfoUI
{
private:
	ShowApplyInfo m_show_apply_info;
public:
	void showApplyInfo();
	void startInterface();
};

/**
 * 채용 통계 인터페이스
 */
class GetRecruitStatusUI
{
private:
	GetRecruitStatus m_get_recruit_stats;
public:
	void startInterface();
	void getRecruitStatus();
};


