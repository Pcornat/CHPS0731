//
// Created by Florent on 25/01/2019.
//

#include "configuration.h"

Configuration::Configuration(const std::string& fileName) : fileName(fileName) {
	size_t pos = this->fileName.find(".json");
	if (pos == std::string::npos)
		throw std::invalid_argument("No file extension found.");


	std::string test(this->fileName.substr(pos, this->fileName.size() - 1));
	if (test != ".json")
		throw std::invalid_argument("Not a .json file.");
}

Configuration::Configuration(std::string&& fileName) : fileName(fileName) {
	size_t pos = this->fileName.find(".json");
	if (pos == std::string::npos)
		throw std::invalid_argument("No file extension found.");


	std::string test(this->fileName.substr(pos, this->fileName.size() - 1));
	if (test != ".json")
		throw std::invalid_argument("Not a .json file.");
}

std::ostream& operator<<(std::ostream& os, const Configuration& configuration) {
	os << configuration.file.dump(4, '\t') << std::endl;
	return os;
}