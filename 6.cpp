#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::vector<std::pair<long long, long long>> stack;
	std::vector<std::pair<long long, long long>> temp_stack;
	
	std::fstream file;
	file.open("input.txt");
	int input;
	int chr;
	long long a, b;
	
	file >> input;
	
	file >> input;
	chr = input;
	while (chr)
	{
		file >> a;
		file >> b;
		
		if (stack.empty())
			stack.push_back({a,b});
		else
		{
			while (!stack.empty() && (stack.back().first > b))
			{
				temp_stack.push_back(stack.back());
				stack.pop_back();
			}
			while (!stack.empty() && \
					(((stack.back().first >= a) && (stack.back().first <= b)) || \
					((stack.back().first <= a) && (stack.back().second >= b)) || \
					((stack.back().second >= a) && (stack.back().second <= b))))
			{
				stack.pop_back();
			}
			stack.push_back({a,b});
			while (!temp_stack.empty())
			{
				stack.push_back(temp_stack.back());
				temp_stack.pop_back();
			}
		}
		chr--;
	}
	
	std::cout << stack.size() << '\n';
	
	file.close();
	
	return 0;
}
