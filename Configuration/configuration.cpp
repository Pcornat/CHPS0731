//
// Created by Florent on 25/01/2019.
//

#include "configuration.h"
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <mutex>

bool Configuration::alreadyCreated = false;

void Configuration::init() {
	if (alreadyCreated)
		throw std::logic_error("It is a singleton class, only one instance of it can exist.");

#pragma omp critical
	Configuration::alreadyCreated = true;
}

Configuration::Configuration() {
	this->init();
}

Configuration::~Configuration() noexcept {
	std::mutex mut;
	mut.lock();
	Configuration::alreadyCreated = false;
	mut.unlock();
}

Configuration::Configuration(const std::string& fileName) : fileName(fileName) {
	this->init();

	size_t pos = this->fileName.find(".json");

	if (pos == std::string::npos)
		throw std::invalid_argument("No file extension found or wrong extension");

	if (!std::filesystem::exists(this->fileName))
		throw std::invalid_argument("File does not exist.");


}

Configuration::Configuration(std::string&& fileName) : fileName(fileName) {
	this->init();

	size_t pos = this->fileName.find(".json");

	if (pos == std::string::npos)
		throw std::invalid_argument("No file extension found or wrong extension.");

	if (!std::filesystem::exists(this->fileName))
		throw std::invalid_argument("File does not exist.");


}

std::ostream& operator<<(std::ostream& os, const Configuration& configuration) {
	os << std::setw(4) << configuration.file << std::endl;
	return os;
}

Configuration& operator>>(const Objet& obj, Configuration& conf) {
	obj.toJson() >> conf.file;
	return *this;
}