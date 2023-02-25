#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	int N;
	
	file >> N;
	
	std::vector<int> map(N + 1, 0);
	std::vector<int> ans(N + 1, 1);
	std::vector<int> answer;
	
	for (int i = 2; i <= N; i++)
	{
		auto minimun = map[i - 1] + 1;
		auto previous = i - 1;
		if (i % 2 == 0)
		{
			minimun = std::min(minimun, map[i / 2] + 1);
			previous = (minimun < map[i / 2] + 1) ? previous : i / 2;
		}
		if (i % 3 == 0)
		{
			minimun = std::min(minimun, map[i / 3] + 1);
			previous = (minimun < map[i / 3] + 1) ? previous : i / 3;
		}
		map[i] = minimun;
		ans[i] = previous;
	}
	
	while (N>1)
	{
		answer.push_back(N);
		N = ans[N];
	}
	answer.push_back(N);
	std::reverse(answer.begin(), answer.end());
	std::cout << map.back() << '\n';
	for (auto c : answer)
		std::cout << c << " ";
	
	file.close();
	
	return 0;
}