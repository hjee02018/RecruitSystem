#pragma once
#include<iostream>
#include<string.h>
#include<fstream>
#include <list>
#include <map>
#include "MemberManagement.h"

using namespace std;

FILE* in_fp, * out_fp;

#define MAX_STRING 32
#define MAX_ACCOUNT 100
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


class ApplyInfo
{
private:
	string m_companyName;
	string m_departName;
	int m_headCount;
	time_t m_endDate;
public:
	string getDepart();
	void showInfo();
	~ApplyInfo();
};

class RecruitInfo
{
private:
	string m_companyName;
	string m_departName;
	int m_numOfApply;
	time_t m_endDate;
public:
	int getRecruitCount();
	string getDepartName();
};


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


