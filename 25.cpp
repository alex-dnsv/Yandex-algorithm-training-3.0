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
	std::vector<int> arr(N , 0);
	std::vector<int> ans(N, 0);
	
	
	for (int i = 0; i < N; i++)
		file >> arr[i];
	
	sort(arr.begin(), arr.end());
	
	ans[1] = arr[1] - arr[0];
	ans[2] = arr[2] - arr[0];
	for (int i = 3; i < N; i++)
	{
		ans[i] = (ans[i-2] < ans[i-1]) ? ans[i-2] : ans[i-1];
		ans[i] += arr[i] - arr[i-1];
	}
	
	std::cout << ans[N-1] << '\n';
	
	file.close();
	
	return 0;
}