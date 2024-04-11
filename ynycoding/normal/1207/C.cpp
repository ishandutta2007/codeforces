#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 200005
int T, n, a, b, r[MAXN];
ll dp[MAXN][2];
char tmp[MAXN];
int main()
{
	dp[0][1]=0x3f3f3f3f3f3f3f;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &a, &b);
		scanf("%s", tmp);
		tmp[n]='0';
		for(int i=1; i<=n; ++i) r[i]=(tmp[i-1]-'0')|(tmp[i]-'0');
		for(int i=1; i<=n; ++i)
		{
			if(r[i]) dp[i][0]=0x3f3f3f3f3f3f3f, dp[i][1]=std::min(dp[i-1][0]+2*a+2*b, dp[i-1][1]+a+2*b);
			else dp[i][0]=std::min(dp[i-1][0]+a+b, dp[i-1][1]+2*a+b), dp[i][1]=std::min(dp[i-1][0]+2*a+2*b, dp[i-1][1]+a+2*b);
		}
		printf("%I64d\n", dp[n][0]+b);
	}
	return 0;
}