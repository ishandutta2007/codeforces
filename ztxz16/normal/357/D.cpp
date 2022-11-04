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

typedef long long ll;

ll n, m, l1, l2, temp, h1[1000005], s[1000005][30];
char s1[1000005], s2[1000005];

void Work(ll l1, ll l2, char s1[], char s2[]);
ll gcd(ll a, ll b);

int main()
{
	cin >> n >> m;
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
	if (l1 < l2)
		Work(l1, l2, s1, s2);
	else
		swap(n, m), Work(l2, l1, s2, s1);
	return 0;
}

void Work(ll l1, ll l2, char s1[], char s2[])
{
	ll i, j, lcm, Now, Ans = 0;
	for (i = 1; i <= l1; i++)
		s1[i] -= ('a' - 1);
	for (i = 1; i <= l2; i++)
		s2[i] -= ('a' - 1);
	lcm = l1 * l2 / gcd(l2, l1);
	for (i = 1; i <= l1; i++)
	{
		if (h1[i] > 0)
		{
			Ans += s[h1[i]][0] - s[h1[i]][s1[i]];
			continue;
		}
		
		Now = i;
		while (1)
		{
			h1[Now] = i;
			Now += l1;
			if (Now > l2)
				Now -= l2;
			s[i][0]++, s[i][s2[Now]]++;
			if (Now == i)
				break;
		}
		
		Ans += s[i][0] - s[i][s1[i]];
	}
	
	Ans *= (l1 * n / lcm);
	printf("%I64d\n", Ans);
	return;
}

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}