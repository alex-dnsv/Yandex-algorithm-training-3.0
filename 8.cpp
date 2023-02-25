#include <iostream>
#include <fstream>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	int input;
	
	int x_min, x_max;
	int y_min, y_max;
	
	int temp;
	
	int k;
	
	file >> input;
	k = temp = input;
	while (k--)
	{
		if (k == temp-1)
		{
			file >> input;
			x_min = x_max = input;
			file >> input;
			y_min = y_max = input;
		}
		else
		{
			file >> input;
			if (input < x_min)
				x_min = input;
			if (input > x_max)
				x_max = input;
			file >> input;
			if (input < y_min)
				y_min = input;
			if (input > y_max)
				y_max = input;
		}
	}
	std::cout << x_min << " " << y_min << " " << x_max << " " << y_max << '\n';
	
	file.close();
	
	return 0;
}
