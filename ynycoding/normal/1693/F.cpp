#include <cstdio>
#include <algorithm>
const int N=200005;
int T, n, sum[N], mn[N], id[N], tot;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &n, s+1);
		tot=0;
		for(int i=1; i<=n; ++i) s[i]-='0', tot+=s[i]?1:-1;
		std::fill(id, id+n+1, 0);
		if(tot<0)
		{
			std::reverse(s+1, s+n+1);
			for(int i=1; i<=n; ++i) s[i]=1-s[i];
		}
		int t=1;
		while(!s[t]) ++t;
		while(s[t]) ++t;
		if(t>n) { puts("0"); continue; }
		for(int i=1; i<=n; ++i)
		{
			sum[i]=sum[i-1]+(s[i]>0?1:-1);
			if(sum[i]>0&&!id[sum[i]]) id[sum[i]]=i;
		}
		mn[n+1]=0x3f3f3f3f;
		for(int i=n; i; --i) mn[i]=std::min(mn[i+1], sum[i]);
		t=n;
		while(sum[t]>0&&s[t]) --t;
		int ans=0;
		int cs=sum[t];
		while(cs>0)
		{
			++ans;
			int l=(t-id[cs])/2;
			cs-=l, t-=l;
		}
		++ans;
		printf("%d\n", ans);
	}
	return 0;
}