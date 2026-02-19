#pragma once

#include <string>
#include <sstream>
#include <vector>

struct Mark {
	std::string subject_;
	size_t mark_;
};

struct StudentData {
	std::string name_;
	size_t number_;
	std::vector<Mark> marks_;

	// Ivan;213;Math:4,Physics:3
	static StudentData constructFromLine(const std::string& str) {
		StudentData result;

		std::istringstream ss(str);

		std::string tmp;
		std::getline(ss, result.name_, ';'); // name

		std::getline(ss, tmp, ';'); // id
		result.number_ = std::stoull(tmp);

		while (std::getline(ss, tmp, ',')) {
			std::string::size_type pos = tmp.find(":");
			std::string sub = tmp.substr(0, pos); // subject
			size_t m = std::stoull(tmp.substr(pos + 1)); // mark
			result.marks_.push_back({ sub, m });
		}

		return result;
	}
	double calculateAverage() const {
		size_t sum = 0;
		for (const Mark& mark : marks_) {
			sum += mark.mark_;
		}
		return static_cast<double>(sum) / marks_.size();
	}


};
