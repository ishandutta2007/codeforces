#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define mo 1000000007LL
#define ll long long

using namespace std;

ll len, q, qn, q1, k, Now, Ans, i, pos[1000005], tot;
char str[1000005];

ll sumi(ll a, ll b);

int main()
{
	gets(str + 1);
	scanf("%I64d", &k);
	for (i = 1; str[i] != 0; i++)
		if (str[i] == '0' || str[i] == '5')
			pos[++tot] = i;
	len = i - 1;
	q = sumi(2, len);
	qn = sumi(q, k);
	q1 = 1 - q;
	while (q1 < 0)
		q1 += mo;
	q1 = sumi(q1, mo - 2);
	for (i = 1; i <= tot; i++)
	{
		Now = sumi(2, pos[i] - 1) - sumi(2, pos[i] - 1) * qn % mo;
		Now = (Now + mo) % mo;
		Now *= q1;
		Now %= mo;
		Ans += Now;
		Ans %= mo;
	}
	
	printf("%I64d\n", Ans);
	return 0;
}

ll sumi(ll a, ll b)
{
	ll ret = 1, c = a, i;
	for (i = 1; i <= b; (i <<= 1))
	{
		if ((b & i) > 0)
			ret *= c, ret %= mo;
		c *= c, c %= mo;
	}
	
	return ret;
}