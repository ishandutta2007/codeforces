#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=1000005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
int n, t, cnt[N], sum, f[N], cur, ans;
int g[N];
char s[N];
int main()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	for(int i=n, ok=1; i; --i)
	{
		cnt[i]=(s[i+1]=='1'?0:cnt[i+1]);
		if(s[i]=='1') ok=0;
		else ++cnt[i];
		sum=sum+ok;
	}
	if(sum==n) return printf("%d\n", n), 0;
	while(s[t+1]=='0') ++t;
	++t;
	cur=1;
	for(int i=1; i<=n; ++i) if(s[i]=='1')
	{
		inc(ans, mval(g[0]+cur));
		for(int j=cnt[i]; ~j; --j) inc(f[i], mval(g[j]+cur)), g[j]=mval(MOD-cur);
		inc(cur, f[i]);
//		inc(ans, f[i]);
//		printf("now %d %d %d\n", i, cnt[i], f[i]);
	}
	printf("%d\n", 1ll*ans*t%MOD*(sum+1)%MOD);
	return 0;
}