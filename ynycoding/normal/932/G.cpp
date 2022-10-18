#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000005
const int MOD=1000000007;
int n, ans[N], f[N];
char s[N], t[N];
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }
namespace PAM{
	int nxt[N][26], len[N], fail[N], sum[N], d[N], top[N], lst, sz;
	inline void init(void)
	{
		sz=1;
		fail[0]=1;
		len[1]=-1;
	}
	inline void insert(int r, int x)
	{
		int p=lst;
		while(s[r]!=s[r-len[p]-1]) p=fail[p];
		if(!nxt[p][x])
		{
			int u=++sz, k=fail[p];
			len[u]=len[p]+2;
			while(s[r]!=s[r-len[k]-1]) k=fail[k];
			fail[u]=nxt[k][x];
			d[u]=len[u]-len[fail[u]];
			top[u]=(d[u]==d[fail[u]])?top[fail[u]]:fail[u];
			nxt[p][x]=u;
		}
		lst=nxt[p][x];
	}
}
using namespace PAM;
int main()
{
	scanf("%s", t+1);
	n=strlen(t+1);
	for(int i=1; i*2<=n; ++i) s[2*i-1]=t[i], s[2*i]=t[n-i+1];
	init();
	ans[0]=1;
	for(int i=1; i<=n; ++i)
	{
		insert(i, s[i]-'a');
		for(int p=lst; p; p=top[p])
		{
			f[p]=ans[i-len[top[p]]-d[p]];
			if(top[p]!=fail[p]) inc(f[p], f[fail[p]]);
			if(!(i&1)) inc(ans[i], f[p]);
		}
	}
	printf("%d\n", ans[n]);
	return 0;
}