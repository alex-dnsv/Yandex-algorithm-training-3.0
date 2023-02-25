#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_st = 1;
	int num;
	int max = 0;
	int local_max;
	int temp_max;
	int temp_num;
	int frst, lst;
	
	fp = fopen("input.txt", "r");
	
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line_st == 1)
		{
			num = atoi(line);
			line_st++;
		}
		else
			break;
	}
	read--;
	for(int i = 'a'; i <= 'z'; i++)
	{
		local_max = 0;
		temp_max = 0;
		temp_num = num;
		frst = 0;
		lst = 0;
		while (lst < read)
		{
			if (line[lst] == i)
			{
				temp_max++;
				if (local_max < temp_max)
					local_max = temp_max;
			}
			else
			{
				if (temp_num > 0)
				{
					temp_num--;
					temp_max++;
					if (local_max < temp_max)
						local_max = temp_max;
					
				}
				else
				{
					if (local_max < temp_max)
						local_max = temp_max;
					if (temp_max > 0)
						temp_max--;
					
					if ((line[frst] != i) && (temp_num < num))
					{
						temp_num++;
						lst--;
					}
					else
						lst--;
					frst++;
					
				}
			}
			lst++;
		}
		if (max < local_max)
			max = local_max;
	}
	
	printf("%d\n", max);
	
	fclose(fp);
	
	return 0;
}