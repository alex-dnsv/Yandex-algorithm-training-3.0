#include <iostream>
#include <fstream>
#include <vector>

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
		if (input == 1)
		{
			std::cout << heap.front() << '\n';
			heap[0] = heap[heap.size() - 1];
			int pos = 0;
			while ((pos * 2 + 1) < (heap.size() - 1))
			{
				int max_son = pos * 2 + 1;
				if (heap[pos * 2 + 2] > heap[max_son])
					max_son = pos * 2 + 2;
				if (heap[pos] < heap[max_son])
				{
					int temp = heap[pos];
					heap[pos] = heap[max_son];
					heap[max_son] = temp;
					pos = max_son;
				}
				else
					break;
			}
			heap.pop_back();
		}
		else
		{
			file >> input;
			heap.push_back(input);
			int pos = heap.size() - 1;
			while (pos > 0 && (heap[pos] > heap[(pos - 1) / 2]))
			{
				int temp = heap[pos];
				heap[pos] = heap[(pos - 1) / 2];
				heap[(pos - 1) / 2] = temp;
				pos = (pos - 1) / 2;
			}
		}
	}
	
	file.close();
	
	return 0;
}