#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T;
ll a, b;
int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", (a-1ll)*9+b);
	}
	return 0;
}