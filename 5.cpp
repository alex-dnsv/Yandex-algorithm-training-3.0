#include <iostream>
#include <fstream>
#include <map>

int main()
{
	std::map<int, long long> stack;
	
	std::fstream file;
	file.open("input.txt");
	int input;
	int chr;
	long long ans = 0;
	int id = 0;
	
	file >> input;
	chr = input;
	
	while (file >> input)
		stack[id++] = input;
	
	for (id = 0; id < chr-1; id++)
	{
		if (stack[id] < stack[id+1])
			ans += stack[id];
		else
			ans += stack[id+1];
	}
	
	std::cout << ans << '\n';
	
	file.close();
	
	return 0;
}
