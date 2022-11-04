#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long sg[105] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
long long hash[1000005], tot;
long long n, i, now, s, SG;

int main()
{
	scanf("%I64d", &n);
	tot = n;
	for (i = 1; i * i <= n; i++)
	{
		if (hash[i] == 1)
			continue;
		now = i, s = 0;
		if (i != 1)
		{
			while (now <= n)
			{
				now *= i, s++;
				if (now < 1000000)
					hash[now] = 1;
			}
		}
		
		else
			s = 1;
		SG ^= sg[s];
		tot -= s;
	}
	
	if ((tot & 1) == 1)
		SG ^= 1;
	if (SG > 0)
		printf("Vasya\n");
	else
		printf("Petya\n");
	return 0;
}