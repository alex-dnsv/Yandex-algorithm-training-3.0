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
	std::vector<int> arr(N + 1, 0);
	std::vector<int> A(N + 1, 0);
	std::vector<int> B(N + 1, 0);
	std::vector<int> C(N + 1, 0);
	
	
	for (int i = 0; i < N; i++)
	{
		file >> A[i] >> B[i] >> C[i];
	}
	
	arr[0] = A[0];
	arr[1] = (B[0] < arr[0] + A[1]) ? B[0] : arr[0] + A[1];
	arr[2] = A[0] + A[1] + A[2];
	arr[2] = (arr[2] < A[0] + B[1]) ? arr[2] : A[0] + B[1];
	arr[2] = (arr[2] < B[0] + A[2]) ? arr[2] : B[0] + A[2];
	arr[2] = (arr[2] < C[0]) ? arr[2] : C[0];
	for (int i = 3; i < N; i++)
	{
		arr[i] = arr[i-1] + A[i];
		arr[i] = (arr[i] < arr[i-2] + B[i-1]) ? arr[i] : arr[i-2] + B[i-1];
		arr[i] = (arr[i] < arr[i-3] + C[i-2]) ? arr[i] : arr[i-3] + C[i-2];
		
	}
	
	std::cout << arr[N-1] << '\n';
	
	file.close();
	
	return 0;
}