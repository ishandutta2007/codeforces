#include <stdio.h>
#include <stdlib.h>

char s[105], t[105], i, Now;

int main()
{
	gets(s + 1);
	gets(t + 1);
	Now = 1;
	for (i = 1; t[i] != 0; i++)
		if (s[Now] == t[i])
			Now++;
	printf("%d\n", Now);
	return 0;
}