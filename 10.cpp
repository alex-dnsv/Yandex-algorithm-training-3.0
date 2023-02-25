#include <iostream>
#include <fstream>
#include <map>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	std::map<char, long long> answer;
	std::string	input;
	long long   size;
	
	file >> input;
	size = input.size();
	
	for (long long i = 0; i < size; i++)
		answer[input[i]] += (size - i) * (i + 1);
	for (auto c : answer)
		std::cout << c.first << ": " << c.second << '\n';
	file.close();
	return 0;
}
