#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::fstream file;
	file.open("input.txt");
	
	int input;
	int move = 0;
	
	std::vector<int> player_1;
	std::vector<int> player_2;
	
	for (int i = 0; i < 5; i++)
	{
		file >> input;
		player_1.push_back(input);
	}
	for (int i = 0; i < 5; i++)
	{
		file >> input;
		player_2.push_back(input);
	}
	
	
	while (!player_1.empty() && !player_2.empty())
	{
		if (player_1.front() == 9 && player_2.front() == 0)
		{
			player_2.push_back(player_1.front());
			player_2.push_back(player_2.front());
			player_2.erase(player_2.begin());
			player_1.erase(player_1.begin());
		}
		else if (player_1.front() == 0 && player_2.front() == 9)
		{
			player_1.push_back(player_1.front());
			player_1.push_back(player_2.front());
			player_1.erase(player_1.begin());
			player_2.erase(player_2.begin());
		}
		else if (player_1.front() > player_2.front())
		{
			player_1.push_back(player_1.front());
			player_1.push_back(player_2.front());
			player_1.erase(player_1.begin());
			player_2.erase(player_2.begin());
		}
		else
		{
			player_2.push_back(player_1.front());
			player_2.push_back(player_2.front());
			player_2.erase(player_2.begin());
			player_1.erase(player_1.begin());
		}
		if (move > 1000000)
			break;
		move++;
	}
	if (move > 1000000)
		std::cout << "botva\n";
	else if (player_1.empty())
		std::cout << "second " << move << '\n';
	else
		std::cout << "first " << move << '\n';
	
	file.close();
	
	return 0;
}
