#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

char str[100005];
int Now;

int main()
{
	gets(str + 1);
	Now = 1;
	while (1)
	{
		if (str[Now] == 0)
			break;
		if (str[Now] == ' ')
		{
			Now++;
			continue;
		}
		
		if (str[Now] == '"')
		{
			printf("<");
			for(Now++; str[Now] != '"'; Now++)
				printf("%c", str[Now]);
			printf(">\n");
			Now++;
		}
		
		else
		{
			printf("<");
			for(; str[Now] != ' ' && str[Now] != '"' && str[Now] != 0; Now++)
				printf("%c", str[Now]);
			printf(">\n");
		}
	}
	
	return 0;
}