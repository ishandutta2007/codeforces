#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, i, tag1, tag2, len;
char str[105];

int main()
{
	scanf("%d", &n);
	gets(str + 1);
	for (i = 1; i <= n; i++)
	{
		gets(str + 1);
		len = strlen(str + 1);
		if (str[1] == 'm' && str[2] == 'i' && str[3] == 'a' && str[4] == 'o' && str[5] == '.')
			tag1 = 1;
		else
			tag1 = 0;
		if (str[len - 4] == 'l' && str[len - 3] == 'a' && str[len - 2] == 'l' && str[len - 1] == 'a' && str[len] == '.')
			tag2 = 1;
		else
			tag2 = 0;
		if (tag1 + tag2 == 0 || tag1 + tag2 == 2)
			printf("OMG>.< I don't know!\n");
		else
		{
			if (tag1 == 1)
				printf("Rainbow's\n");
			else
				printf("Freda's\n");
		}
	}
	
	return 0;
}