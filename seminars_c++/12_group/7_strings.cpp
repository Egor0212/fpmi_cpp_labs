#include <iostream>
#include <string>
#include <vector>

// "abc cde efg"

std::vector<std::string> SplitWords(const std::string& s,
                                    const std::string& delimeters) {
    
    std::vector<std::string> words;
    //using size_type = unsigned long
    std::string::size_type beg_index = 0;
    std::string::size_type end_index = s.find_first_of(delimeters);
    
    while (beg_index != std::string::npos) {

        std::string word = s.substr(beg_index, end_index - beg_index);
        if (!word.empty()) {
            words.push_back(word);
        }
        
        beg_index = s.find_first_not_of(delimeters, end_index); 
        end_index = s.find_first_of(delimeters, beg_index);
    }

    return words;
}


int main() {
    
    //const char* str = "Hello";
    //std::cout << str;

    /*std::string str = "Hello";
    std::string str2(10, 'a');
    
    std::cout << str2;*/
    std::string str; // "C++ I love you"
    //std::cin >> str;
    std::getline(std::cin, str);
    //std::cout << str;
    const std::string delimeters = " ,.!?";
    std::vector<std::string> vs = SplitWords(str, delimeters);
    
    for (size_t i = 0; i < vs.size(); ++i) {
        std::cout << vs[i] << ' ';
    }

    return 0;
}
