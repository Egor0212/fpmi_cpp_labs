#include <iostream>
#include <string>
#include <vector>

// strlen
// strcopy
// strcat

std::vector<std::string> SplitString(const std::string& text,
                                     const std::string& delimeters) {
    
    std::vector<std::string> words;

    std::string::size_type beg_index = 0;
    std::string::size_type end_index = text.find_first_of(delimeters, beg_index);
    
    // std::string::npos = static_cast<size_type>(-1)
    while (beg_index != std::string::npos) {
        std::string word = text.substr(beg_index, end_index - beg_index);
        if (!word.empty()) {
            words.push_back(word);
        }

        beg_index = text.find_first_not_of(delimeters, end_index);
        end_index = text.find_first_of(delimeters, beg_index);
    }

    return words;
}


int main() {

    //const char* str = "Hello";
    //std::cout << str;

    std::string s1 = "Hello";
    std::cout << s1 << '\n';
    std::cout << s1.size() << '\n';

    std::string s2(40, 'a');
    std::cout << s2 << '\n';
    std::cout << s2.size() << ' ' << s2.capacity() << '\n';
    s2.erase(2, 2);
    std::cout << s2.size() << ' ' << s2.capacity() << '\n';
   
    std::string input;
    //std::cin >> input;
    std::getline(std::cin, input);

    const std::string delimeters = " ,.!?";
    std::vector<std::string> words = SplitString(input, delimeters); 
    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << words[i] << '|';
    }

    return 0;
}
