#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

char s1[2000005], s2[2000005];
int n, i, ss1, ss2, ss, temp;

int main()
{
	scanf("%d\n", &n);
	gets(s1 + 1);
	gets(s2 + 1);
	n <<= 1;
	for (i = 1; i <= n; i++)
	{
		if (s1[i] == '1')
			ss++;
		if (s1[i] == '1' && s2[i] == '1')
			ss1++;
		if (s1[i] == '1' && s2[i] == '0')
			ss2++;
		if (s1[i] == '0' && s2[i] == '1')
			ss2++;
	}
	
	if ((ss1 & 1) == 1)
	{
		ss -= (ss1 - 1);
		if ((ss2 & 1) == 1)
			ss -= ((ss2 >> 1) + 1);
		else
			ss -= (ss2 >> 1);
	}
	
	else
	{
		ss -= ss1;
		ss -= (ss2 >> 1);
	}
	
	if (ss == 0)
		printf("Draw\n");
	if (ss < 0)
		printf("Second\n");
	if (ss > 0)
		printf("First\n");
	return 0;
}