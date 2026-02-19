#pragma once

#include "StudData.h"

#include <fstream>
#include <iostream>
#include <map>


class Utils {
public:
	static std::map<size_t, StudentData> readStudentsFromFile() {
		std::ifstream in("students.txt");
		if (!in.is_open()) {
			throw std::runtime_error("File can't be opened");
		}
		if (in.peek() == EOF) {
			throw std::runtime_error("File is empty");
		}

		std::string line;
		std::map<size_t, StudentData> info;
		while (std::getline(in, line)) {
			StudentData object = StudentData::constructFromLine(line);
			//object.constructFromLine(line);
			info[object.number_] = object;
		}
		return info;
	}

	static void CalculateAverage(const std::map<size_t, StudentData>& info) {
		for (const auto& [key, value] : info) { //std::pair<size_t, StudentData>
			std::cout << value.name_ << ' ' << value.calculateAverage() << '\n';
		}
	}
};