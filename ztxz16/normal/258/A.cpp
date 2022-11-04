#include <stdio.h>
#include <stdlib.h>

char str[100005];
int i, j, len;

int main()
{
	gets(str + 1);
	for (i = 1; str[i] != 0; i++);
	len = i - 1;
	for (i = 2; i <= len; i++)
		if (str[i] == '0')
			break;
	for (j = 1; j <= len; j++)
	{
		if (j == i || (i > len && j == 1))
		{}
		else printf("%c", str[j]);
	}
	
	printf("\n");
	return 0;
}