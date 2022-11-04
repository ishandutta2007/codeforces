#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define mo 1000000007

using namespace std;

int FASTBUFFER;

int n, i, ans, f[1000005][5];
char str[1000005];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	n = strlen(str + 1);
	if (str[1] == '*')
		f[1][2] = 1;
	else if (str[1] == '1')
		f[1][1] = 1;
	else if (str[1] == '2')
	{
		printf("0\n");
		return 0;
	}
	
	else if (str[1] == '0')
		f[1][0] = 1;
	else
		f[1][1] = f[1][0] = f[1][2] = 1;
	for (i = 2; i <= n; i++)
	{
		if (str[i] == '*')
			f[i][2] = (f[i - 1][1] + f[i - 1][2]) % mo;
		else if (str[i] == '0')
			f[i][0] = f[i - 1][0];
		else if (str[i] == '1')
		{
			f[i][1] = f[i - 1][0];
			f[i][0] = f[i - 1][2];
		}
		
		else if (str[i] == '2')
			f[i][1] = f[i - 1][2];
		else
		{
			f[i][2] = (f[i - 1][1] + f[i - 1][2]) % mo;
			f[i][0] = (f[i - 1][0] + f[i - 1][2]) % mo;
			f[i][1] = (f[i - 1][0] + f[i - 1][2]) % mo;
		}
	}
	
	ans = (f[n][0] + f[n][2]) % mo;
	printf("%d\n", ans);
	return 0;
}