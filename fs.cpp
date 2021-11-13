#include <filesystem.hpp>
#include <iostream>
#include <experimental/algorithm>
#include <typeinfo>

namespace fs = ghc::filesystem;

void format_viewer(const fs::path& s){
	if(s.has_extension()){
		std::cout << "Text file\n";
		std::cout << "File type: " << s.extension() << "\n";
	}
}

int main(){
	fs::path entire;

	fs::path PROJECT_PATH = fs::current_path();
	fs::path text_file = "\\out\\new_file.txt";

	entire += PROJECT_PATH;
	entire += text_file;

	std::cout << "Project path is " << PROJECT_PATH << '\n';
	std::cout << "Entire path to text file: " << entire << '\n';

	format_viewer(entire);

	return 0;
}