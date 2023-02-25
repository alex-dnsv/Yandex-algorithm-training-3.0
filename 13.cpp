#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::vector<int> stack;
	
	std::fstream file;
	file.open("input.txt");
	char input;
	
	while (file >> input)
	{
		if (input >= '0' && input <= '9')
			stack.push_back(input - '0');
		else if (input == '-')
		{
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			stack.push_back(b - a);
		}
		else if (input == '+')
		{
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			stack.push_back(a + b);
		}
		else if (input == '*')
		{
			int a = stack.back();
			stack.pop_back();
			int b = stack.back();
			stack.pop_back();
			stack.push_back(a * b);
		}
	}
	std::cout << stack.back() << '\n';
	
	file.close();
	
	return 0;
}
