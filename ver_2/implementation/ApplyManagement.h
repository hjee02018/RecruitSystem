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
	GenMember m_genMember;
public:
	void cancelApplcyInfo(string compName, int compNo, string departName);
};

class GetApplyCount
{
private:
	GenMember m_genMember;
public:
	void getApplyCount();
};

class GetRecruitStatus
{
private:
	CompMember m_compMember;
public:
	void getRecruitStatus();
};

class ShowApplyInfo
{
private:
	GenMember m_genMember;
public:
	void showApplyInfo();
};

class CancelApplyInfoUI
{
private:
	CancelApplyInfo m_cancelApplyInfo;
public:
	void startInterface();
	void cancelApplyInfo();
};

class GetApplyCountUI
{
private:
	GetApplyCount m_getApplyCount;
public:
	void startInterface();
	void getApplyCount();
};

class ShowApplyInfoUI
{
private:
	ShowApplyInfo m_showApplyInfo;
public:
	void showApplyInfo();
	void startInterface();
};


class GetRecruitStatusUI
{
private:
	GetRecruitStatus m_getRecruitStats;
public:
	void startInterface();
	void getRecruitStatus();
};


