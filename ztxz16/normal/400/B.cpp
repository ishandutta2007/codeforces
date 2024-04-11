#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int n, m, i, j, a, b, now, ans, f[1005];
char str[1005];
set <int> s;
set <int>::iterator it;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (j = 1; j <= m; j++)
			if (str[j] == 'G')
				a = j;
			else if (str[j] == 'S')
				b = j;
		if (a > b)
		{
			printf("-1\n");
			return 0;
		}
		
		else
			s.insert(b - a);
	}
	
	f[0] = 1;
	for (it = s.begin(); it != s.end(); ++it)
	{
		now = *it;
		if (f[now])
			continue;
		ans++;
		for (j = m; j >= now; j--)
			if (f[j - now])
				f[j] = 1;
	}
	
	printf("%d\n", s.size());
	return 0;
}