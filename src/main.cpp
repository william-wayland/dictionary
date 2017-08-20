#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_set>
#include <vector>
#include <string>
#include <chrono>

auto read_file(const std::string& path) {
	auto file = std::fstream();
	file.open(path);

	auto file_data = std::vector<std::string>();
	if (!file.is_open()) {
		std::cerr << "Couldn't Read File at:" << path << std::endl;
		std::exit(-1);
	}

	std::string s;
	while (!file.eof()) {
		std::getline(file, s);
		file_data.push_back(s);
	}

	return std::make_unique<std::vector<std::string>>(std::move(file_data));
}


int main() {

	if (auto dictionary = read_file("words.txt")) {

		auto start = std::chrono::high_resolution_clock::now();

		for (const auto& s : *dictionary) {
			std::cout << s << std::endl;
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	}
	else {

	}
}
