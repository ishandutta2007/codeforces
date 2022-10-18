#include <cstdio>
#include <algorithm>
#define MAXN 200005
int n, k, a[MAXN], l[MAXN], le[MAXN], sum[MAXN<<2], cnt[MAXN<<2], ans, mx;
inline int rev(int a) { int ret=0; while(a) ret<<=1, ret+=(a&1), a>>=1; return ret; }
inline int len(int a) { return (a>>10)?10+l[a>>10]:l[a]; }
int main()
{
	scanf("%d%d", &n, &k);
	l[1]=1;
	for(int i=1; i<=1025; ++i) l[i<<1]=l[i<<1|1]=l[i]+1;
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	std::sort(a+1, a+n+1);
	for(int i=1; i<=k; ++i) ans+=len(a[i]);
	for(int i=1; i<=n; ++i) le[i]=len(a[i]), a[i]=rev(a[i]), mx=std::max(a[i], mx);
	for(int i=1; i<=n; ++i)
	{
		int cur=0;
		while(le[i]--) cur=((cur<<1)|(a[i]&1)), a[i]>>=1, (cnt[cur]<k?sum[cur]+=le[i]:0), ++cnt[cur];
	}
	for(int i=1; i<=mx*2; ++i) if(cnt[i]>=k) ans=std::min(ans, sum[i]);
	printf("%d\n", ans);
	return 0;
}