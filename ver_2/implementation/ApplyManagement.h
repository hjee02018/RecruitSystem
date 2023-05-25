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


class CancelApplyInfo
{
private:
	GenMember m_gen_member;
public:
	void cancelApplcyInfo(string compName, int compNo, string departName);
};

class GetApplyCount
{
private:
	GenMember m_gen_member;
public:
	void getApplyCount();
};

class GetRecruitStatus
{
private:
	CompMember m_comp_member;
public:
	void getRecruitStatus();
};

class ShowApplyInfo
{
private:
	GenMember m_gen_member;
public:
	void showApplyInfo();
};

class CancelApplyInfoUI
{
private:
	CancelApplyInfo m_cancel_apply_info;
public:
	void startInterface();
	void cancelApplyInfo();
};

class GetApplyCountUI
{
private:
	GetApplyCount m_get_apply_count;
public:
	void startInterface();
	void getApplyCount();
};

class ShowApplyInfoUI
{
private:
	ShowApplyInfo m_show_apply_info;
public:
	void showApplyInfo();
	void startInterface();
};


class GetRecruitStatusUI
{
private:
	GetRecruitStatus m_get_recruit_stats;
public:
	void startInterface();
	void getRecruitStatus();
};


