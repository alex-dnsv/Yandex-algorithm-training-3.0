#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	int inp;
	int sum;
	int N;
	int M;
	int Z;
	int x1, x2, y1, y2;
	std::vector<int> input;
	
	file >> inp;
	N = inp;
	file >> inp;
	M = inp;
	file >> inp;
	Z = inp;
	sum = 0;
	for (int i = 0; i < N * M; i++)
	{
		file >> inp;
		sum += inp;
		input.push_back(sum);
	}
	
	while (Z--)
	{
		file >> inp;
		x1 = inp - 1;
		file >> inp;
		y1 = inp - 1;
		file >> inp;
		x2 = inp - 1;
		file >> inp;
		y2 = inp - 1;
		int ans = 0;
		for (int i = x1; i <= x2; i++)
		{
			ans += input[i * M + y2] - input[i * M + y1-1];
		}
		
		std::cout << ans << '\n';
	}
	
	file.close();
	
	return 0;
}
