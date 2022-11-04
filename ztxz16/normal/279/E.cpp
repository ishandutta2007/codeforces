#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int f[1000005][3], i, len;
char str[1000005];

int main()
{
	scanf("%s", str + 1);
	len = strlen(str + 1);
	if (str[len] == '1')
		f[len][0] = 1, f[len][1] = 1;
	else
		f[len][0] = 0, f[len][1] = 16161616;
	for (i = len - 1; i >= 1; i--)
	{
		if (str[i] == '1')
		{
			f[i][0] = min(f[i + 1][0] + 1, f[i + 1][1] + 1);
			f[i][1] = min(f[i + 1][0] + 1, f[i + 1][1]);
		}
		
		else
		{
			f[i][0] = f[i + 1][0];
			f[i][1] = f[i + 1][1] + 1;
		}
	}
	
	printf("%d\n", f[1][0]);
	return 0;
}