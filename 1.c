#include <stdio.h>

int main()
{
	int count[256] = {0};
	int max = 0;
	int k;
	
	FILE *fp = fopen("input.txt", "r");
	
	int c;
	
	while ((c = fgetc(fp)))
	{
		if (c == EOF)
			break;
		count[c]++;
	}
	for (k = 0; k < 256; k++)
	{
		if (k == ' ' || k == '\n')
			count[k] = 0;
		if (count[k] > max)
			max = count[k];
	}
	while (max)
	{
		for(k = 0; k < 256; k++)
		{
			if (count[k] >= max)
				printf("#");
			else if (count[k] > 0)
				printf(" ");
		}
		printf("\n");
		max--;
	}
	for (k = 0; k < 256; k++)
	{
		if (count[k] > 0)
			printf("%c", k);
	}
	printf("\n");
	fclose(fp);
	return 0;
}