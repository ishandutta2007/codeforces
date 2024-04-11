#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define ll long long

using namespace std;

ll FASTBUFFER;

ll nb, ns, nc, pb, ps, pc, sum, i, l, r, mid;
ll s[1005], need;
char str[1005];

int main()
{
	gets(str + 1);
	for (i = 1; str[i] != 0; i++)
		s[str[i]]++;
	scanf("%I64d %I64d %I64d", &nb, &ns, &nc);
	scanf("%I64d %I64d %I64d", &pb, &ps, &pc);
	scanf("%I64d", &sum);
	l = 0, r = 2000000000000LL;
	while (l < r)
	{
		mid = ((l + r + 1) >> 1);
		need = 0;
		if (s['B'] * mid > nb)
			need += (s['B'] * mid - nb) * pb;
		if (s['S'] * mid > ns)
			need += (s['S'] * mid - ns) * ps;
		if (s['C'] * mid > nc)
			need += (s['C'] * mid - nc) * pc;
		if (need <= sum)
			l = mid;
		else
			r = mid - 1;
	}
	
	printf("%I64d\n", l);
	return 0;
}