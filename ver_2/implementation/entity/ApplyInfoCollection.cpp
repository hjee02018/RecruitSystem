#include "ApplyInfoCollection.h"

/**
 * add apply_info to Apply list 
 *
 * @param apply_info applying information. <- "매개변수1"
 * @return void
 */
void ApplyInfoCollection::addApplyInfo(ApplyInfo apply_info)
{
    m_recruit_applys.push_back(apply_info);
}
