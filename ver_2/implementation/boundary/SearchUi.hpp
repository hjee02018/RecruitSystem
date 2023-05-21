#ifndef SearchUi_hpp
#define SearchUi_hpp
#define MAX_STRING 32

#include <stdio.h>
#include <string>
#include "Search.hpp"

using namespace std;

/**
 * Represents a search boundary <- "클래스의 역할"
 *
 */
class SearchUi
{
private:
public:
    string startInterface(FILE* in_fp);
    void searchRecruitmentInfoByCompanyName(string company_name, FILE* out_fp);
};

#endif /* SearchUi_hpp */
