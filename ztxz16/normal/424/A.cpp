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

int ans, n, i, s[1005], x;
char str[1005];
string Ans = "";

int main()
{
	x = 'x' + 'X';
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (i = 1; i <= n; i++)
	{
		s[str[i]]++;
		if (s[str[i]] > n / 2)
			ans++, s[str[i]]--, s[x - str[i]]++, Ans += (x - str[i]);
		else
			Ans += str[i];
	}
	
	printf("%d\n", ans);
	cout << Ans << endl;
	return 0;
}