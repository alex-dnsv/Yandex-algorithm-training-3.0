#include <iostream>
#include <fstream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void hSort(std::vector<int>& arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	std::vector<int> heap;
	
	std::fstream file;
	file.open("input.txt");
	
	int N;
	int input;
	
	file >> N;
	
	while (N--)
	{
		file >> input;
		heap.push_back(input);
	}
	
	hSort(heap, heap.size());
	
	for (auto c : heap)
		std::cout << c << " ";
	
	file.close();
	
	return 0;
}