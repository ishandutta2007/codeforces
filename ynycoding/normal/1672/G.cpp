#include <cstdio>
#include <numeric>
#include <algorithm>
const int N=2005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, m, a[N][N], cnt, fa[N<<1], cur[N<<1], ct[N<<1];
char s[N];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s+1);
		for(int j=1; j<=m; ++j) a[i][j]=s[j]=='?'?2:s[j]-'0';
	}
	if(!(n&1)&&(m&1))
	{
		for(int i=1; i<=std::max(n, m); ++i) for(int j=1; j<i; ++j) std::swap(a[i][j], a[j][i]);
		std::swap(n, m);
	}
	int x=1, y=1;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(a[i][j]==2) x=i, y=j;
	for(int i=1; i<=m; ++i) std::swap(a[x][i], a[1][i]);
	for(int i=1; i<=n; ++i) std::swap(a[i][y], a[i][1]);
	std::iota(fa, fa+n+m+1, 0);
	int is=!(n&1)&&!(m&1);
	for(int i=2; i<=n; ++i) for(int j=2; j<=m; ++j) if(a[i][j]==1)
	{
		if(a[1][j]!=2) a[1][j]^=1;
		if(a[i][1]!=2) a[i][1]^=1;
		if(a[1][1]!=2) a[1][1]^=1;
		a[i][j]=0;
	}
	else cnt+=(a[i][j]==2&&is);
	for(int i=2; i<=n; ++i) cur[i]=a[i][1], ct[i]=1, cnt+=a[i][1]==2;
	for(int i=2; i<=m; ++i) cur[i+n]=a[1][i], ct[i+n]=1, cnt+=a[1][i]==2;
	if(a[1][1]!=2)
	{
		if((n&1)&&(m&1))
		{
			for(int i=2; i<=n; ++i) if(a[i][1]!=a[1][1]) return puts("0"), 0;
			for(int i=2; i<=m; ++i) if(a[1][i]!=a[1][1]) return puts("0"), 0;
		}
		else if((n&1)&&!(m&1))
		{
			for(int i=2; i<=n; ++i) a[1][1]^=a[i][1];
			for(int i=2; i<=m; ++i) if(a[1][i]!=a[1][1]) return puts("0"), 0;
		}
		return puts("1"), 0;
	}
	if((n&1)&&(m&1))
	{
		for(int i=2; i<=n; ++i) for(int j=2; j<=m; ++j) if(a[i][j]==2)
		{
			int x=findfa(i), y=findfa(j+n);
			if(x!=y)
			{
				fa[x]=y;
				ct[y]^=ct[x];
				cur[y]=(cur[x]==2||cur[y]==2)?2:cur[x]^cur[y];
			}
			else ++cnt;
		}
		int ok0=1, ok1=1;
		for(int i=1; i<=n+m; ++i) if(i!=1&&i!=n+1&&findfa(i)==i)
		{
			if(cur[i]==2) --cnt;
			else
			{
				if(ct[i]) cur[i]?ok0=0:ok1=0;
				else cur[i]?ok0=ok1=0:0;
			}
		}
		printf("%d\n", 1ll*(ok0+ok1)*qpow(2, cnt)%MOD);
	}
	else if(is) printf("%d\n", qpow(2, cnt+1));
	else
	{
		int ct=0, ok0=1, ok1=1;
		for(int i=2; i<=n; ++i) ct+=a[i][1]==2;
		for(int i=2; i<=m; ++i)
		{
			int rt=0, cur=0;
			for(int j=1; j<=n; ++j) cur^=a[j][i], rt+=a[j][i]==2;
			if(rt) ct+=rt-1;
			else (cur&1)?ok0=0:ok1=0;
		}
		printf("%d\n", 1ll*(ok0+ok1)*qpow(2, ct)%MOD);
	}
	return 0;
}