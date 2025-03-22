#include <iostream>
#include <fstream>
#include <string>

void replaceAndWrite(const std::string& inputFile, const std::string& s1, const std::string& s2)
{
	std::ifstream inFile(inputFile.c_str());
 	if (!inFile) 
	{
 		std::cerr << "Error: Cannot open input file." << std::endl;
 		return;
	}

	std::string outputFile = inputFile + ".replace";
	std::ofstream outFile(outputFile.c_str());
	if (!outFile) 
	{
		std::cerr << "Error: Cannot create output file." << std::endl;
		return;
    }

 	std::string line;
	while (std::getline(inFile, line)) 
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) 
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFile << line << std::endl;
	}

 	inFile.close();
	outFile.close();
}

int main(int argc, char* argv[]) 
{
	if (argc != 4) 
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) 
	{
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return 1;
    }

	replaceAndWrite(filename, s1, s2);

	return 0;
}

