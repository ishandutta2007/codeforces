#include <cstdio>
#include <algorithm>
const int N=405;
int T, n, m, sum[N], sc[N], sr[N], mx, ans;
char s[N][N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		ans=0x3f3f3f3f;
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i) scanf("%s", s[i]+1);
		for(int i=1; i<=n; ++i)
		{
			std::fill(sum, sum+m+1, 0);
			std::fill(sr, sr+m+1, 0);
			std::fill(sc, sc+m+1, 0);
			for(int j=i; j<=n; ++j)
			{
				if(j>i)
				{
					int cur=0;
					for(int t=1; t<=m; ++t)
					{
						if(j>i+1) cur+=s[j-1][t]-'0';
						if(j>i+1) sc[t]+=s[j-1][t]=='0';
						sum[t]+=cur;
						sr[t]=sr[t-1]+(s[j][t]=='0')+(s[i][t]=='0');
					}
				}
				if(j>=i+4)
				{
					mx=-0x3f3f3f3f;
					for(int t=4; t<=m; ++t)
					{
						mx=std::max(mx, sum[t-3]+sr[t-3]-sc[t-3]);
						ans=std::min(ans, sum[t-1]+sr[t-1]-mx+sc[t]);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}