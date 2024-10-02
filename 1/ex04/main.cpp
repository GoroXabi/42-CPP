#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {

	size_t start_pos = 0;
	size_t end_pos = str.find(from, 0);
	std::string new_str;

	if (from.empty())
		return str;
	
	while (end_pos != std::string::npos)
	{
		new_str += str.substr(start_pos, end_pos - start_pos) + to;
		start_pos = end_pos + from.length();
		end_pos = str.find(from, start_pos);
	}

	new_str += str.c_str() + start_pos;

	return (new_str);
}

int main(int argc, char *argv[]) {

	if (argc != 4)
	{
		std::cout << "PLS ENTER AS ARGUMENTS \"FILENAME\" \"S1\" \"S2\"" << std::endl;
		return (1);
	}

	std::ifstream	infile(argv[1]);
	std::string		outname(argv[1]);
	std::ofstream	outfile(outname.append(".replace").c_str());

	if (!infile.is_open() || !outfile.is_open())
	{

		if (infile.is_open())
			infile.close();

		if (outfile.is_open())
			outfile.close();

		std::cout << "SOMETHING WENT WRONG OPENING THE FILES" << std::endl;
		
		return(1);

	}
	
	int lines;

	for (std::string buffer; std::getline(infile, buffer);)
		lines++;

	infile.close();
	infile.open(argv[1]);
		
	if(!infile.is_open()) {
		outfile.close();
		return(1);
	}

	for (std::string buffer; std::getline(infile, buffer);) {
		outfile << replaceAll(buffer, argv[2], argv[3]);
		if (--lines > 0)
			outfile << std::endl;
	}

	infile.close();
	outfile.close();
	return (0);
}
