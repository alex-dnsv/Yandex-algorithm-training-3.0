#include <iostream>
#include <fstream>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	int students, tests, row, seat;
	
	file >> students >> tests >> row >> seat;
	
	row--;
	seat--;
	
	int seat_Petua = row * 2 + seat;
	int after_Petua = seat_Petua + tests;
	int before_Petua = seat_Petua - tests;
	
	if (after_Petua < students && before_Petua >= 0 && after_Petua / 2 - row <= row - before_Petua / 2)
		std::cout << (after_Petua / 2 + 1) << " " << (after_Petua % 2 + 1) << '\n';
	else if (before_Petua >= 0)
		std::cout << (before_Petua / 2 + 1) << " " << (before_Petua % 2 + 1) << '\n';
	else if (after_Petua < students)
		std::cout << (after_Petua / 2 + 1) << " " << (after_Petua %2 + 1) << '\n';
	else
		std::cout << -1 << '\n';
	
	file.close();
	return 0;
}
