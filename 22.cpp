#include <iostream>
#include <fstream>


int main()
{
	
	std::fstream file;
	file.open("input.txt");
	
	int N, K;
	int ans[31] = {0};
	
	file >> N >> K;
	
	ans[0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= std::min(i, K); j++)
			ans[i] += ans[i-j];
	}
	
	std::cout << ans[N-1] << '\n';
	
	file.close();
	
	return 0;
}