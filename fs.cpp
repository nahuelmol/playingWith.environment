#include <filesystem.hpp>
#include <iostream>
#include <experimental/algorithm>

namespace fs = ghc::filesystem;

int main(){

	std::cout << "new attempt\n";
	std::cout << "Current path is " << fs::current_path() << '\n';
	std::cout << "Temp directory is " << fs::temp_directory_path();

	return 0;
}