#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	
	int N;
	
	file >> N;
	
	std::vector<int> ans(N+1, 0);
	
	ans[0] = 2;
	ans[1] = 4;
	ans[2] = 7;
	for (int i = 3; i < N; i++)
		ans[i] = (ans[i-1] + ans[i-2] + ans[i-3]);
	
	std::cout << ans[N-1] << '\n';
	
	file.close();
	
	return 0;
}