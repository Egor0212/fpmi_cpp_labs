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


bool IsEmptyFile(std::ifstream& fin) {
    // return fin.peek() == EOF;
    return fin.peek() == std::ifstream::traits_type::eof(); 
}


std::vector<int32_t> ReadSequenceFromFile(const std::string& filename) {

    std::ifstream fin{filename};
    // fin.open(filename);

    if ( !fin.is_open() ) {
        throw "Error: could no open file \"" + filename + "\"";
    }

    if (IsEmptyFile(fin)) {
        throw "Error: file \"" + filename + "\" is empty";
    }

    std::vector<int32_t> sequence;

    //while (!fin.eof()) { // BAD!!!!!
    //    int32_t x;
    //    fin >> x;
    //    sequence.push_back(x);
    //}
    
    int32_t x;
    while (fin >> x) {
        sequence.push_back(x);
    }

    return sequence;
}


void WriteAvgToFile(const std::string& filename, double avg) {
    std::ofstream fout{filename};

    if ( !fout.is_open() ) {
        throw "Error: could no open file \"" + filename + "\""; 
    }

    fout << avg;
    // fout.close();
}


// input.txt: 1 2 0 1 2 3 4 0 5
// output.txt: 2.5

int main() {

    const std::string input_filename = "input.txt";
    const std::string output_filename = "output.txt";
    const std::string empty_filename = "empty.txt";

    try {

        std::vector<int32_t> v = ReadSequenceFromFile(empty_filename);
        for (int32_t x : v) {
            std::cout << x << ' ';
        }
        std::cout << std::endl;
        double avg = FindAvgBetweenZeros(v);
        std::cout << avg;
        WriteAvgToFile(output_filename, avg);
        std::cout << "URAAAAAAAAA! Result has been written to "
                  << std::quoted(output_filename);

    } catch(const std::string& msg) {
        std::cout << msg << '\n';
    }

}



