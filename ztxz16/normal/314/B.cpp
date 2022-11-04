#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long b, d, l1, l2, i, j, tot, st, del1, del2, Max, next[1005][1005];
long long hash[1005], Now, Now2, x1[10005], x2[10005];
char a[105], bb[105];

int main()
{
	scanf("%d %d\n", &b, &d);
	gets(a + 1);
	gets(bb + 1);
	l1 = strlen(a + 1);
	l2 = strlen(bb + 1);
	for (i = l1 - 1; i >= 0; i--)
	{
		for (j = 'a'; j <= 'z'; j++)
			next[i][j] = next[i + 1][j];
		next[i][a[i + 1]] = i + 1;
	}
	
	hash[0] = 1;
	tot = 1;
	Now = 0, Now2 = 1;
	x1[1] = 1, x2[1] = 0;
	while (1)
	{
		for (i = 1; i <= l2; i++)
		{
			Now = next[Now][bb[i]];
			if (Now == 0)
			{
				if (next[Now][bb[i]] == 0)
				{
					printf("0\n");
					return 0;
				}
				
				Now2++;
				Now = next[Now][bb[i]];
			}
		}
		
		if (hash[Now] == 0)
			hash[Now] = ++tot, x1[tot] = Now2, x2[tot] = Now;
		else
		{
			st = hash[Now];
			x1[++tot] = Now2, x2[tot] = Now;
			break;
		}
	}
	
	if (b < x1[st])
	{
		for (i = 1; i < st; i++)
			if (x1[i] > b)
				break;
		Max = i - 1;
	}
	
	else
	{
		del1 = tot - st;
		del2 = x1[tot] - x1[st];
		b -= x1[st];
		Max += st;
		Max += (b / del2 * del1);
		b %= del2;
		for (i = st + 1; i <= tot; i++)
		{
			if (x1[i] - x1[st] > b)
				break;
			Max++;
		}
	}
	
	Max--;
	cout << (Max / d) << endl;
	return 0;
}