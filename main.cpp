#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <deque>
#include <iterator>
#include <string>
#include <queue>
#include <set>
#include <string>


//##############################TASK_1##############################


template<typename W>
void printWords(W it, W end)
{
    std::unordered_set<std::string> countWords(it, end);
    std::copy(countWords.begin(), countWords.end(), std::ostream_iterator<std::string>(std::cout, "; "));
}



int main()
{
    std::cout << "##############################TASK_1##############################\n\n";

    std::vector<std::string> v{ "hell", "heaven", "live", "big", "hell", "jump", "Hell", "live", "butt", "what", "why" };
    std::cout << "Result vector:" << std::endl;
    printWords(v.begin(), v.end());

    std::deque<std::string> d(v.begin(), v.end());
    std::cout << "\nResult deque:" << std::endl;
    printWords(d.begin(), d.end());
   
    std::list<std::string> l(v.begin(), v.end());
    std::cout << "\nResult list:" << std::endl;
    printWords(l.begin(), l.end());
 
    std::cout << "\n\n##############################TASK_2##############################\n\n";

    const auto my_string_compare = [](const std::string& lhs, const std::string& rhs) {
        return lhs.size() < rhs.size();
    };

    std::set<std::string, decltype(my_string_compare) > sentences(my_string_compare);
    std::string sent("not empty");
    while (getline(std::cin, sent) && !sent.empty()) {
        std::cout << std::endl;
        typename std::string::size_type pos_start{}, pos_end{};
        while (pos_start != sent.npos && pos_end != sent.npos) {
            pos_end = sent.find_first_of(".!?", pos_start);
            sentences.insert(sent.substr(pos_start, pos_end - pos_start));
            pos_start = sent.find_first_not_of(" .!?", pos_end);
        }
    }
    sentences.erase(std::string());
    for (auto& str : sentences) {
        std::cout << str << ";\n" << std::endl;
    }




    return 0;
}