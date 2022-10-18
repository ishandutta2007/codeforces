#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=20;
int T, n, mx, vis[N], ans, e[N][N], st[N], f[1<<N];
char s[100005], t[100005];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0; i<n; ++i) if(e[u][i]&&!vis[i ])
		dfs(i);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s%s", &n, s+1, t+1);
		mx=0;
		memset(e, 0, sizeof(e));
		memset(st, 0, sizeof(st));
		for(int i=1; i<=n; ++i)
		{
			e[s[i]-'a'][t[i]-'a']=1;
			e[t[i]-'a'][s[i]-'a']=1;
			st[t[i]-'a']|=1<<(s[i]-'a');
			mx=std::max({mx, s[i]-'a', t[i]-'a'});
		}
		n=mx+1;
		memset(vis, 0, sizeof(vis));
		ans=n;
		for(int i=0; i<n; ++i) if(!vis[i]) dfs(i), --ans;
		for(int s=1; s<(1<<n); ++s)
		{
			f[s]=n+1;
			for(int i=0; i<n; ++i) if((s>>i)&1)
			{
				f[s]=std::min(f[s], f[s^(1<<i)]+((st[i]&s)!=st[i]));
			}
		}
		printf("%d\n", ans+f[(1<<n)-1]);
	}
	return 0;
}