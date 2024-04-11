#include <bits/stdc++.h>
#define MAX_N 100005
using namespace std;
typedef long long ll;
ll a, b, c, d, e;

int main()
{
	scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &d, &e);
	if(a<=c && c<=b && b<=d)
	{
		if(c<=e && e<=b)
		{
			printf("%I64d", b-c);
		}
		else printf("%I64d", b-c+1LL);
	}
	else if(c<=a && a<=d && d<=b)
	{
		if(a<=e && e<=d)
		{
			printf("%I64d", d-a);
		}
		else printf("%I64d", d-a+1LL);
	}
	else if(a<=c && d<=b)
	{
		if(c<=e && e<=d)
		{
			printf("%I64d", d-c);
		}
		else printf("%I64d", d-c+1LL);
	}
	else if(c<=a && b<=d)
	{
		if(a<=e && e<=b)
		{
			printf("%I64d", b-a);
		}
		else printf("%I64d", b-a+1LL);
	}
	else puts("0");
}