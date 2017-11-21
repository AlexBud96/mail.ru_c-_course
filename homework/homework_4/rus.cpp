#include <regex>
#include <iostream>

using char_type=char;
using str_type = std::basic_string<char_type>;
auto& cout = std::cout;

int main (int argc, char** argv) {
    //std::setlocale(LC_ALL, NULL);
    //std::ios_base::sync_with_stdio(false);
    //cout.imbue( std::locale("ru_RU.UTF-8") );

    std::basic_regex<char_type> tmpl("[^\\s]+");
    str_type str="word work работа";
    std::vector<str_type> result;

    std::regex_iterator<str_type::const_iterator> rei(str.begin(),str.end(),tmpl);
    std::regex_iterator<str_type::const_iterator> end;

    while(rei!=end) {
        std::match_results<str_type::const_iterator> match=*rei;
        result.push_back(match.str());
        rei++;
    }

    for(auto r:result) cout << r << std::endl;

    return 0;
}
