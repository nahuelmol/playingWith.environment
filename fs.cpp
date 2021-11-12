#include <filesystem.hpp>
#include <iostream>
#include <experimental/algorithm>

namespace fs = ghc::filesystem;

int main(){

	std::cout << "new attempt\n";
	std::cout << "Current path is " << fs::current_path() << '\n';

	return 0;
}