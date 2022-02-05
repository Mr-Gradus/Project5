#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <deque>
#include <iterator>
#include <string>
#include <queue>



//##############################TASK_1##############################


template<typename W>
void printWords(W it, W end)
{
    std::unordered_set<std::string> countWords(it, end);
    std::copy(countWords.begin(), countWords.end(), std::ostream_iterator<std::string>(std::cout, "; "));
}


//##############################TASK_2##############################

std::string getSentence(std::string& s)
{
    std::string punctuationMarks{ ".?!" };                               // разделительные знаки пунктуации
    std::string temp;                                                     // найденное предложение из введенных данных

    for (const char& c : s)                                               // посимвольно перебираем поток данных
    {
        temp.push_back(c);                                                // добавляем каждый символ в потенциальное найденное предложение

        if (punctuationMarks.find(c) != std::string::npos)                // если найден разделительный знак пунктуации - заканчиваем поиск
        {
            s.erase(0, temp.size());                                      // удаляем найденное предложение из потока данных
            if (temp[0] == ' ') { temp.erase(0, 1); }                     // обрезаем пробел в начале предложения, если он есть
            return temp;                                                  // возвращаем найденное предложение
        }
    }

    return {};                                                            // иначе возвращаем пустой объект
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

   




    return 0;
}