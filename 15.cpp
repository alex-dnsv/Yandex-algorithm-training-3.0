#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main()
{
	std::vector<std::pair<int, int>> input;
	std::vector<std::pair<int, int>> stack;
	std::map<int, int> ans;
	
	std::fstream file;
	file.open("input.txt");
	int n;
	int cities;
	int inp;
	
	file >> inp;
	cities = inp;
	
	n = 0;
	while ((file >> inp) && (cities--))
	{
		input.push_back({inp, n});
		ans[n] = 0;
		n++;
	}
	
	
	for (auto city : input)
	{
		if (stack.empty())
			stack.push_back(city);
		else if (stack.back().first <= city.first)
			stack.push_back(city);
		else
		{
			while (!stack.empty() && (stack.back().first > city.first))
			{
				ans[stack.back().second] = city.second;
				stack.pop_back();
			}
			stack.push_back(city);
		}
	}
	while (!stack.empty())
	{
		ans[stack.back().second] = -1;
		stack.pop_back();
	}
	
	for (auto &prnt : ans)
	{
		std::cout << prnt.second << " ";
	}
	
	file.close();
	
	return 0;
}
