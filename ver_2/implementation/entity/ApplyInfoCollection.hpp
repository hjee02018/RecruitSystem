//
//  ApplyInfoCollection.hpp
//  homework3
//
//  Created by 김규철 on 2023/05/21.
//

#ifndef ApplyInfoCollection_hpp
#define ApplyInfoCollection_hpp

#include <stdio.h>
#include <vector>
#include "ApplyInfo.hpp"

using namespace std;

/**
 * Represents a ApplyInfo Collection <- "클래스의 역할"
 *
 */
class ApplyInfoCollection
{
private:
    vector<ApplyInfo> m_recruit_applys;
public:
    void addApplyInfo(ApplyInfo apply_info);
};
#endif /* ApplyInfoCollection_hpp */
