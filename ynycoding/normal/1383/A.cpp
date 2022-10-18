#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=100005, K=21;
int T, n, is[K][K], ans;
char s[N], t[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		scanf("%s%s", s+1, t+1);
		memset(is, 0, sizeof(is));
		for(int i=1; i<=n; ++i) is[s[i]-'a'][t[i]-'a']=1;
		for(int i=0; i<20; ++i) for(int j=0; j<i; ++j) if(is[i][j]) { puts("-1"); goto out; }
		ans=0;
		for(int i=0; i<20; ++i)
		{
			int mx=20;
			for(int j=i+1; j<20; ++j) if(is[i][j])
			{
				mx=j;
				break;
			}
			if(mx==20) continue;
			++ans;
			for(int j=i+1; j<20; ++j) is[mx][j]|=is[i][j];
		}
		printf("%d\n", ans);
		out:;
	}
	return 0;
}