#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <iterator>
#include <algorithm>

using HotelMap = std::map<std::string, std::vector<std::pair<std::string, int>>>;
HotelMap readFromFile(const std::string& filename) {
	std::ifstream in(filename);
	if (!in.is_open()) {
		throw std::runtime_error("Can't open file");
	}
	if (in.peek() == EOF) {
		throw std::runtime_error("File is empty");
	}
	HotelMap hotelmap;
	std::string line;
	while (std::getline(in, line)) {
		std::stringstream ss(line);
		std::string city;
		std::getline(ss, city, ';');
		std::string name;
		std::getline(ss, name, ';');
		std::string stars_str;
		std::getline(ss, stars_str, ';');
		try {
			int stars = std::stoi(stars_str);
			hotelmap[city].emplace_back(name, stars);
		}
		catch (...) {
			continue;
		}
	}
	return hotelmap;
}

void PrintHotelsAndStars(const HotelMap& map) {
	std::set<std::pair<std::string, int>> hotels;
	for (const auto& [city, vector] : map) {
		for (const auto& element : vector) {
			hotels.insert(element);
		}
	}

	for (const auto& element : hotels) {
		std::cout << element.first << " " << element.second << "\n";
	}
}

int main() {
	try {
		setlocale(LC_ALL, "Russian");
		HotelMap map = readFromFile("DATA.txt");

		/*for (const auto& [city, vector] : map) {
			std::cout << "Город:" << city << " Отели:";
			for (const auto& item : vector) {
				std::cout << item.first << " " << item.second << "\n";
			}
		}*/
		PrintHotelsAndStars(map);
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}

	// STL
	//std::vector<int> v{ 11, 2, 3, 432, 5 };
	//std::copy(v.begin() + 2, v.end(), std::ostream_iterator<int>(std::cout));
	//std::cout << std::endl;

	//int k = 3;
	//size_t n = std::count_if(v.begin(), v.end(),
	//			[k](int x) {
	//				return x % k == 0;
	//			});
	//std::cout << n << std::endl;
	//std::sort(v.begin(), v.end(), [](int x, int y) { return abs(x - 5) < abs(y - 5); });
	//std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

	return EXIT_SUCCESS;
}