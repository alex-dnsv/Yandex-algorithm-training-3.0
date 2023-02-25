#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

int main()
{
	
	std::fstream file;
	file.open("input.txt");
	std::string input;
	
	struct tm time_A;
	struct tm time_B;
	struct tm time_C;
	float seconds;
	int temp_A;
	int temp_C;
	int temp;
	
	file >> input;
	strptime(input.c_str(), "%T", &time_A);
	file >> input;
	strptime(input.c_str(), "%T", &time_B);
	file >> input;
	strptime(input.c_str(), "%T", &time_C);
	
	temp_A = time_A.tm_hour*60*60 + time_A.tm_min*60 + time_A.tm_sec;
	temp_C = time_C.tm_hour*60*60 + time_C.tm_min*60 + time_C.tm_sec;
	if (temp_C < temp_A)
		seconds = temp_C + (24*60*60-temp_A);
	else
		seconds = temp_C - temp_A;
	seconds = seconds / 2;
	if (seconds - static_cast<int>(seconds) >= 0.5)
		temp = static_cast<int>(seconds) + 1;
	else
		temp = static_cast<int>(seconds);
	
	time_B.tm_sec += temp;
	
	if (time_B.tm_sec >= 60)
	{
		temp = time_B.tm_sec;
		time_B.tm_sec -= (temp / 60) * 60;
		time_B.tm_min += (temp / 60);
	}
	if (time_B.tm_min >= 60)
	{
		temp = time_B.tm_min;
		time_B.tm_min -= (temp / 60 ) * 60 ;
		time_B.tm_hour += (temp / 60 ) ;
	}
	if (time_B.tm_hour >= 24)
	{
		temp = time_B.tm_hour;
		time_B.tm_hour -= (temp / 24) * 24;
	}
	
	std::cout << std::setfill('0') << std::setw(2) << time_B.tm_hour << ":" <<
			  std::setfill('0') << std::setw(2) << time_B.tm_min << ":" <<
			  std::setfill('0') << std::setw(2) << time_B.tm_sec << '\n';
	
	file.close();
	
	return 0;
}
