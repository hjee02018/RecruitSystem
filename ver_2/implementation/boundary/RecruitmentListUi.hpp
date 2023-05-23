#ifndef RecruitmentListUi_hpp
#define RecruitmentListUi_hpp

#include <iostream>
#include <string>
#include <vector>
#include "CompMember.hpp"
#include "RecruitInfo.hpp"

using namespace std;

/**
 * Represents a search boundary <- "클래스의 역할"
 *
 */
class RecruitmentListUi
{
private:
public:
    void startInterface();
    void selectRecruitmentList(vector<RecruitInfo> recruitmentList, CompMember compMember, FILE* out_fp);
};

#endif RecruitmentListUi_hpp