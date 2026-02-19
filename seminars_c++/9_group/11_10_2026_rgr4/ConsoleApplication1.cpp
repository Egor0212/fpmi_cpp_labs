#include "Header.h"
#include "StudData.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>



int main()
{
	std::map<size_t,StudentData> studmap = Utils::readStudentsFromFile();
	//std::map<size_t, StudentData>::iterator it;
	//std::vector<Mark>::iterator v_it;
	//for (it = studmap.begin(); it != studmap.end();++it) {
	//	std::cout << it->second.name_ << " ";
	//	std::cout << it->first << " ";
	//	for (v_it = it->second.marks_.begin(); v_it != it->second.marks_.end(); ++v_it) {
	//		std::cout << v_it->subject_ << " ";
	//		std::cout << v_it->mark_ << " ";
	//	}
	//	std::cout << std::endl;
	//}
	
	//for (const auto& stud : studmap) { //std::pair<size_t, StudentData>
	//	std::cout << stud.first << " " << stud.second.name_ << " ";
	//	for (const Mark& mark : stud.second.marks_) {
	//		std::cout << mark.subject_ << " " << mark.mark_ << " ";
	//	}
	//	std::cout << "\n";
	//}

	//for (const auto& [key, value] : studmap) { //std::pair<size_t, StudentData>
	//	std::cout << key << " " << value.name_ << " ";
	//	for (const Mark& mark : value.marks_) {
	//		std::cout << mark.subject_ << " " << mark.mark_ << " ";
	//	}
	//	std::cout << "\n";
	//}
	Utils::CalculateAverage(studmap);
}
