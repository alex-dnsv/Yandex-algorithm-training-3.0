#include <iostream>
#include <set>
#include <fstream>
#include <map>
#include <vector>

int main()
{
	std::set<int> stickers;
	std::vector<int> collectors;
	std::map<int, int> ans;
	
	std::fstream file;
	file.open("input.txt");
	int num, input;
	
	file >> num;
	while (num-- > 0)
	{
		file >> input;
		stickers.insert(input);
	}
	file >> num;
	while (num-- > 0)
	{
		file >> input;
		collectors.push_back(input);
		ans[input] = 0;
	}
	
	int i = 0;
	auto iterator = stickers.begin();
	for (auto [num, stick] : ans)
	{
		while (*iterator < num)
		{
			if (iterator == stickers.end())
			{
				ans[num] = i;
				break;
			}
			iterator++;
			i++;
		}
		if (*iterator >= num)
			ans[num] = i;
	}
	
	for (auto num : collectors)
	{
		std::cout << ans[num] << '\n';
	}
	
	file.close();
	
	return 0;
}