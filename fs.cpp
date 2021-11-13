#include <filesystem.hpp>
#include <iostream>
#include <experimental/algorithm>
#include <typeinfo>
#include <fstream>

namespace fs = ghc::filesystem;

void get_size_file(const fs::path& s){

	using std::fstream;
	using std::string;
	using std::cout;

	cout << "File size: " << fs::file_size(s) << "\n";

	fstream myfile;
	string spath = s.u8string();

	myfile.open(spath, fstream::in | fstream::out | fstream::app);

	if(!myfile){
		cout << "file unidentified";
	}else{
		cout << "file identified";
		myfile << "\nreading from fs.cpp script\n";
	}

	myfile.close();
}

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

	std::cout << "\n\n";
	format_viewer(entire);
	get_size_file(entire);

	return 0;
}