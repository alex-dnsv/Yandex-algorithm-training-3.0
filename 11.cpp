#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::vector<int> stack;
	
	std::fstream file;
	file.open("input.txt");
	std::string input;
	int n;
	
	while (file)
	{
		file >> input;
		if (input == "push")
		{
			file >> n;
			stack.push_back(n);
			std::cout << "ok\n";
		}
		else if (input == "pop")
		{
			if (stack.empty())
				std::cout << "error\n";
			else
			{
				std::cout << stack.back() << '\n';
				stack.pop_back();
			}
		}
		else if (input == "back")
		{
			if (stack.empty())
				std::cout << "error\n";
			else
			{
				std::cout << stack.back() << '\n';
			}
		}
		else if (input == "size")
		{
			std::cout << stack.size() << '\n';
		}
		else if (input == "clear")
		{
			stack.clear();
			std::cout << "ok\n";
		}
		else if (input == "exit")
		{
			std::cout << "bye\n";
			break;
		}
	}
	
	file.close();
	
	return 0;
}