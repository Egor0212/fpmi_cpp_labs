#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <optional>
#include <vector>


double FindAvgBetweenZeros(const std::vector<int32_t>& v) {
    if (v.empty()) {
        throw "Error: array has no elements!!!";
    }
    
    std::optional<size_t> first_zero;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            first_zero = i;
            break;
        }
    }
    
    std::optional<size_t> last_zero;
    for (size_t i = v.size(); i > 0u; --i) {
        if (v[i - 1] == 0) {
            last_zero = i - 1;
            break;
        }
    }

    if (!first_zero.has_value() || !last_zero.has_value()) {
        throw "Error: array has no no zeros!!!";
    } else if (first_zero.value() == last_zero.value()) {
        throw "Error: array has only one zero!!!";
    } else if (*first_zero + 1 == *last_zero) {
        throw "Error: no elements between zeros";
    } else {
        int64_t sum = std::accumulate(v.begin() + *first_zero, v.begin() + *last_zero, int64_t{});
        return static_cast<double>(sum) / (*last_zero - *first_zero - 1);
    }
}


std::vector<int32_t> ReadSequeneFromFile(const std::string& filename) {
    std::ifstream fin{filename};

    if ( !fin.is_open() ) {
        throw "Error: Could not open file: " + filename;
    }

    if (fin.peek() == std::ifstream::traits_type::eof()) {
       throw "Error: File " + filename + " is empty"; 
    }

    std::vector<int32_t> numbers;
    
    // 0 1 2 3 4 0
    int32_t x;
    while (fin >> x) {
        numbers.push_back(x);
    }
    
    // fin.close();
    return numbers;
}


void WriteAvgToFile(const std::string& filename, double avg) {
    std::ofstream fout{filename};

    if (!fout.is_open() ) {
        throw "Error: Could not open file: " + filename; 
    }

    fout << avg;

    //fout.close();
}

// input.txt: 0 1 2 3 4 0
// output.txt: 2.5
int main() {
    
    const std::string input_file = "input.txt";
    const std::string output_file = "output.txt";
    
    try {
        std::vector<int32_t> numbers = ReadSequeneFromFile(input_file);
        for (int32_t x : numbers) {
             std::cout << x << ' ';
        }
        std::cout << std::endl;
        double avg = FindAvgBetweenZeros(numbers);
        std::cout << avg;
        WriteAvgToFile(output_file, avg);
        
        std::cout << "URa!!!!!! Result has been written to " 
                  << std::quoted(output_file); 

    } catch(const std::string& msg) {
        std::cout << msg << '\n';
    }
    
}



