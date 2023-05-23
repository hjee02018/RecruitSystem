#ifndef ShowRecruitmentList_hpp
#define ShowRecruitmentList_hpp

#include <iostream>
#include <string>
#include <vector>
#include "RecruitInfo.hpp"
#include "CompMember.hpp"

using namespace std;

/**
 * Represents boundary <- "클래스의 역할"
 *
 */
class ShowRecruitmentList
{
public:

    void showRecruitmentList(CompMember CompMember, vector<RecruitInfo> recruitmentList);
};
#endif ShowRecruitmentList_hpp