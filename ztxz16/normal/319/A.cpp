#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#define mo 1000000007
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int mi[105], Ans, len, i, xx;
char str[105];

int main()
{
	mi[0] = 1;
	for (i = 1; i <= 100; i++)
		mi[i] = (mi[i - 1] + mi[i - 1]) % mo;
	scanf("%s", str + 1);
	len = strlen(str + 1);
	xx = 1;
	for (i = 1; i <= len; i++, xx = (xx + xx) % mo)
		if (str[i] == '1')
			Ans += (long long)mi[len - i] * mi[len - i] % mo * xx % mo, Ans %= mo;
	printf("%d\n", Ans);
	return 0;
}