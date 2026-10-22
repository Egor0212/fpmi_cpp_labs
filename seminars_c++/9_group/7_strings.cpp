#include <iostream>
#include <string>
#include <vector>

// "C++, I love you!" -> c++ I love you

std::vector<std::string> SplitString(const std::string& text,
                                     const std::string& delimeters) {
    
    std::vector<std::string> words;
    
    std::string::size_type beg_index = 0;
    std::string::size_type end_index = text.find_first_of(delimeters, beg_index);
    
    // std::string::npos
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

// gr3g3/.t4./t.,24,.g2r,gr2,. ,2,. 24., t23.,r./e2./g
int main() {

    //const char* c = "Hello";
    //std::cout << c;

    std::string s = "Hello";
    std::cout << s;

    std::string s1(40, 'a'); 
    std::cout << s1.size() << ' ' << s1.capacity() << '\n';

    s1.erase(2, 2);
    std::cout << s1.size() << ' ' << s1.capacity() << '\n';
    std::cout << s1.length();
    
    std::string input;
    //std::cin >> input;
    std::getline(std::cin, input);
    std::cout << input;
    
    const std::string delimeters = " ,.!?";
    std::vector<std::string> words = SplitString(input ,delimeters);
    std::cout << "\nWords:\n";
    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << words[i] << ' ';
    }

    return 0;
}
