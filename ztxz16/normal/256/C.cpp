#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll SG(ll i);

ll n, i, x, Now;

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &x);
		Now ^= SG(x);
	}
	
	if (Now == 0)
		printf("Rublo\n");
	else
		printf("Furlo\n");
	return 0;
}

ll SG(ll x)
{
	if (x >= 2562991876LL)
		return 2;
    if (x>=45212176)
		return 1;
    if (x>=50626)
		return 1;
    if (x>=6724)
		return 3;
    if (x>=82)
		return 0;
    if (x>=16)
		return 2;
    if (x>=4)
		return 1;
    return 0;
}