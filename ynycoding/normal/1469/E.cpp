#include <cstdio>
#include <algorithm>
#define N 4000005
int T, n, k, lim, cnt[N], sum[N];
char a[N], ans[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		ans[k+1]=0;
		scanf("%s", a+1);
		for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+(a[i]=='0');
		int num=n-k+1;
		lim=0;
		while(num) num>>=1, ++lim;
		lim=std::min(lim, k);
		std::fill(cnt, cnt+(1<<lim)+1, 0);
		std::fill(ans+1, ans+k+1-lim, '0');
		for(int i=n, s=0; i>=k-lim+1; --i)
		{
			if(i+lim<=n) s>>=1, s|=((a[i]-'0')<<(lim-1));
			else s|=((a[i]-'0')<<(n-i));
			if(i+lim-1<=n&&sum[i-1]==sum[i-(k-lim)-1]) ++cnt[s];
		}
		int u=(1<<lim)-1, t=0;
		for(; t<=u; ++t) if(!cnt[t^u]) break;
		if(t>u) puts("NO");
		else
		{
			puts("YES");
			for(int i=k-lim+1; i<=k; ++i) ans[i]='0'+((t>>(k-i))&1);
			puts(ans+1);
		}
	}
	return 0;
}