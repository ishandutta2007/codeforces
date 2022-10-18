#include <cstdio>
#include <cstring>
#include <algorithm>
#define i128 __int128
#define ll long long
const int N=65;
int n, q, x, to[N][2], rvis[N], rvis1[N];
ll vis[N];
i128 a[N][3*N];
inline i128 abs(i128 x) { return x<0?-x:x; }
void gauss(int n, int rm)
{
	for(int i=1; i<=n; ++i)
	{
		int cur=0;
		for(int j=i; j<=n; ++j) if(a[j][i])
		{
			if(!cur||abs(a[j][i])<abs(a[cur][j])) cur=j;
		}
		if(!cur) exit(114);
		for(int j=i; j<=rm; ++j) std::swap(a[cur][j], a[i][j]);
		for(int j=1; j<=n; ++j) if(i!=j)
		{
			i128 d=std::__gcd(a[i][i], a[j][i]);
			ll m=a[i][i]/d, mul=a[j][i]/d;
			for(int k=1; k<=rm; ++k) a[j][k]*=m;
			for(int k=i; k<=rm; ++k) a[j][k]-=a[i][k]*mul;
		}
		for(int i=1; i<=n; ++i)
		{
			i128 d=0;
			for(int j=1; j<=rm; ++j) d=std::__gcd(d, a[i][j]);
			for(int j=1; j<=rm; ++j) a[i][j]/=d;
		}
	}
}
char s[N];
bool chk(int u)
{
	if(u==x) return 1;
	if(rvis1[u]) return 1;
	if(rvis[u]||!vis[u]) return 0;
	rvis[u]=1;
	if(chk(to[u][vis[u]&1])) { rvis1[u]=1; return 1; }
	return 0;
}
int main()
{
	scanf("%d", &n);
	a[1][2*n]=1;
	for(int i=1, x, y; i<n; ++i)
	{
		scanf("%d%d", &x, &y);
		to[i][0]=x, to[i][1]=y;
		a[i][i]+=-2;
		++a[y][i], ++a[y][i+n];
		++a[x][i];
		--a[i][i+n];
		a[i][i+2*n]=-1;
	}
	gauss(n-1, 3*n-1);
	scanf("%d", &q);
	for(int i=1; i<=q; ++i)
	{
		scanf("%d%s", &x, s+1);
		ll ans=0;
		for(int i=1; i<n; ++i)
		{
			i128 sum=a[i][n*2]+a[i][2*n+x];
			for(int j=1; j<n; ++j) if(s[j]=='R') sum+=a[i][n+j];
			sum*=-1;
			if(sum%a[i][i]) { puts("-1"); goto out; }
			ll v=(sum/a[i][i])*2+(s[i]=='R');
			if(v<0) { puts("-1"); goto out; }
			ans+=v;
			vis[i]=v;
		}
		std::fill(rvis+1, rvis+n+1, 0);
		std::fill(rvis1+1, rvis1+n+1, 0);
		for(int i=1; i<n; ++i) if(vis[i]&&!chk(i)) { puts("-1"); goto out; }
		printf("%lld\n", ans);
		out:;
	}
	return 0;
}