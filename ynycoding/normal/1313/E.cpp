#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define N 1000005
using std::vector;
int n, m, cnta[N], cntb[N], cnt[N], ex[N<<1], k;
ll sum[N], ans;
char a[N], b[N], s[N], t[N<<1];
inline int lowbit(int x) { return x&(-x); }
inline void add(int x, int v) { while(x<=n) cnt[x]+=v, x+=lowbit(x); }
inline void add1(int x, int v) { while(x<=n) sum[x]+=v, x+=lowbit(x); }
inline int que(int x) { int ret=0; while(x) ret+=cnt[x], x-=lowbit(x); return ret; }
inline ll que1(int x) { ll ret=0; while(x) ret+=sum[x], x-=lowbit(x); return ret; }
inline exkmp(char *s, int n)
{
	ex[1]=n;
	for(int x=1; x<n&&s[x]==s[x+1]; ex[2]=x, ++x);
	k=2;
	for(int i=3; i<=n; ++i)
	{
		int p=k+ex[k]-1, l=ex[i-k+1];
		if(i+l-1<p) ex[i]=l;
		else
		{
			int t=p-i+1;
			if(t<0) t=0;
			while(s[t+1]==s[i+t]&&i+t<=n) ++t;
			ex[i]=t, k=i;
		}
	}
}
int main()
{
	scanf("%d%d%s%s%s", &n, &m, a+1, b+1, s+1);
	for(int i=1; i<=m; ++i) t[i]=s[i];
	t[m+1]='#';
	for(int i=1; i<=n; ++i) t[i+m+1]=a[i];
	exkmp(t, n+m+1);
	for(int i=m+2; i<=n+m+1; ++i) cnta[i-m-1]=std::min(ex[i], m-1);
	for(int i=1; i<=n+m+1; ++i) ex[i]=0;
	for(int i=1; i<=m; ++i) t[i]=s[m-i+1];
	t[m+1]='#';
	for(int i=1; i<=n; ++i) t[i+m+1]=b[n-i+1];
	exkmp(t, n+m+1);
	for(int i=m+2; i<=n+m+1; ++i) cntb[n+m-i+2]=std::min(ex[i], m-1);
	for(int i=1; i<=n; ++i)
	{
		if(i>m-1&&cnta[i-m+1]) add(m-cnta[i-m+1], -1), add1(m-cnta[i-m+1], m-1-cnta[i-m+1]);
		if(cnta[i]) add(m-cnta[i], 1), add1(m-cnta[i], -m+1+cnta[i]);
		if(cntb[i]) ans+=(ll)que(cntb[i])*cntb[i]+que1(cntb[i]);
	}
	printf("%lld", ans);
	return 0;
}