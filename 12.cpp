#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::vector<char> stack;
	
	std::fstream file;
	file.open("input.txt");
	std::string input;
	int n = 0;
	int true_seq = 1;
	
	file >> input;
	
	while (n < input.size())
	{
		if (input[n] == '(' || input[n] == '[' || input[n] == '{')
			stack.push_back(input[n]);
		else if (!stack.empty())
		{
			if ((input[n] == ')') && (stack.back() == '('))
				stack.pop_back();
			else if ((input[n] == ']') && (stack.back() == '['))
				stack.pop_back();
			else if ((input[n] == '}') && (stack.back() == '{'))
				stack.pop_back();
			else
			{
				true_seq = 0;
				break;
			}
		}
		else
		{
			true_seq = 0;
			break;
		}
		n++;
	}
	if (true_seq && stack.size() == 0)
		std::cout << "yes\n";
	else
		std::cout << "no\n";
	
	file.close();
	
	return 0;
}