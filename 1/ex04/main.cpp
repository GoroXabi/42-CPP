#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    
	if (from.empty())
        return str;

	while (start_pos != std::string::npos)
	{
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
		start_pos = str.find(from, start_pos);
    }

    return (str);
}

int main(int argc, char *argv[]) {

	if (argc != 4)
	{
		std::cout << "PLS ENTER AS ARGUMENTS \"FILENAME\" \"S1\" \"S2\"" << std::endl;
		return (1);
	}
	std::string outname(argv[1]);
	std::string	buffer;
	std::ifstream infile(argv[1]);
	std::ofstream outfile(outname.append(".replace").c_str());

	std::getline(infile, buffer);
	outfile << replaceAll(buffer, argv[2], argv[3]);

    return (0);
}
