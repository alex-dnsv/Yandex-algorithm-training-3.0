#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::vector<int> tupik;
	std::vector<int> way_2;
	
	std::fstream file;
	file.open("input.txt");
	int input;
	int is_possible = 1;
	
	file >> input;
	
	while (file >> input)
	{
		if (tupik.empty())
			tupik.push_back(input);
		else if (tupik.back() > input)
			tupik.push_back(input);
		else
		{
			if (way_2.empty())
			{
				way_2.push_back(tupik.back());
				tupik.pop_back();
				if (way_2.back() != 1)
				{
					is_possible = 0;
					break;
				}
			}
			while (!tupik.empty() && (way_2.back() == (tupik.back() - 1)))
			{
				way_2.push_back(tupik.back());
				tupik.pop_back();
			}
			if (tupik.empty())
				tupik.push_back(input);
			else
			{
				if (tupik.back() > input)
					tupik.push_back(input);
				else
				{
					is_possible = 0;
					break;
				}
			}
		}
	}
	if (is_possible)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
	
	file.close();
	
	return 0;
}
