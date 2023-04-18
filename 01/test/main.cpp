#include <iostream>
#include <string>

class Test
{
	private:
		void privPrint1()
		{
			std::cout << "privPrint1\n";
		}

		void privPrint2()
		{
			std::cout << "privPrint2\n";
		}
	public:
		void pubPrint1()
		{
			std::cout << "pubPrint1\n";
		}
		
		void pubPrint2()
		{
			std::cout << "pubPrint1\n";
		}

		void printClass(std::string str);
};


void Print1(std::string str)
{
	std::cout << str << std::endl;
}

void Print2(std::string str)
{
	std::cout << str << str << std::endl;
}

void pubPrint1(std::string str)
{
	std::cout << str << std::endl;
}

void pubPrint2(std::string str)
{
	std::cout << str << str << std::endl;
}

void Test::printClass(std::string str)
{
	std::string funcNames[2] = {"Print1", "Print2"};
	void (*funcPtrs[2])(std::string) = {Print1, Print2};

	for (int i = 0; i < 2; i++)
	{
		if (str == funcNames[i])
			funcPtrs[i]("test");
	}

	std::string privClassNames[2] = {"privPrint1", "privPrint2"};
	void (Test::*privPtrs[2])() = {Test::privPrint1, Test::privPrint2};

	for (int i = 0; i < 2; i++)
	{
		if (str == privClassNames[i])
			(this->*privPtrs[i])();
	}

	std::string pubClassNames[2] = {"pubPrint1", "pubPrint2"};
	void (*pubPtrs[2])(std::string) = {pubPrint1, pubPrint2};

	for (int i = 0; i < 2; i++)
	{
		if (str == pubClassNames[i])
			(pubPtrs[i])();
	}
}

int main()
{
	Test test;

	test.printClass("test");
}