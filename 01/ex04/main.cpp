#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// filename, s1, s2

int strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return len;
}

std::string FindAndReplace(const char *s1, const char* s2, std::string& text)
{
	std::string newText = "";
	int s1_length = strlen(s1);
	int pos;

	for (int i = 0; i < text.length(); i++)
	{
		pos = text.find(s1, i);
		if (pos == -1 || pos - i != 0)
			newText += text[i];
		else
		{
			newText += s2;
			i += s1_length - 1;
		}
	}
	return newText;
}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::ofstream newFile;
	std::string text = "";
	std::string newText;
	char temp;

	if (argc != 4)
	{
		std::cout << "Wrong amount of arguments passed to the programm.\n";
		return 0;
	}

	file.open(argv[1]);
	if (!file.good())
	{
		std::cout << "Wrong filename or file doesn't exist.\n";
		return 0;
	}

	while (file >> std::noskipws >> temp)
		text += temp;

	newText = FindAndReplace(argv[2], argv[3], text);
	std::string newFileName = argv[1];
	newFileName += ".replace";
	newFile.open(newFileName);
	if (!newFile.good())
	{
		std::cout << "Couldn't create or write to new file " << newFileName << std::endl;
		return 0;
	}
	newFile << newText;
}