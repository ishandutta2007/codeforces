#include <cstdio>
#include <algorithm>
#define ll long long
int T, s[11];
ll n, m, cnt;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%I64d%I64d", &n, &m);
		cnt=n/m;
		m%=10;
		for(int i=1; i<=9; ++i) s[i]=m*i%10+s[i-1];
		printf("%I64d\n", (cnt/10)*s[9]+s[cnt%10]);
	}
	return 0;
}