#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file;
	file.open("input.txt");
	
	std::string input;
	int num;
	
	std::vector<int> queue;
	
	while (file >> input)
	{
		if (input == "push")
		{
			file >> num;
			queue.push_back(num);
			std::cout << "ok\n";
		}
		else if (input == "pop")
		{
			if (queue.empty())
				std::cout << "error\n";
			else
			{
				std::cout << queue.front() << '\n';
				queue.erase(queue.begin());
			}
		}
		else if (input == "front")
		{
			if (queue.empty())
				std::cout << "error\n";
			else
				std::cout << queue.front() << '\n';
		}
		else if (input == "size")
		{
			std::cout << queue.size() << '\n';
		}
		else if (input == "clear")
		{
			queue.clear();
			std::cout << "ok\n";
		}
		else if (input == "exit")
		{
			std::cout << "bye\n";
			break;
		}
	}
	
	file.close();
	
	return 0;
}
