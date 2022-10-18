#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define K 105
#define N 1000005
#define MOD 1000000007
int n, k, a[N+2*K], f[N+2*K], pre[K], id[K], ans[K], rans, lim;
int trans[K][K], ret[K][K], tmp[K][K];
ll m;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void upt(int &x, int a) { x=mval(x+a); }
bool cmp(int a, int b) { return pre[a]<pre[b]; }
void mul(int a[][K], int b[][K], int c[][K])
{
	for(int i=1; i<=lim; ++i) for(int j=1; j<=lim; ++j) tmp[i][j]=0;
	for(int i=1; i<=lim; ++i) for(int k=1; k<=lim; ++k) for(int j=1; j<=lim; ++j)
	upt(tmp[i][j], 1ll*a[i][k]*b[k][j]%MOD);
	for(int i=1; i<=lim; ++i) for(int j=1; j<=lim; ++j) c[i][j]=tmp[i][j];
}
inline void qp(ll p)
{
	for(int i=1; i<=lim; ++i) ret[i][i]=1;
	while(p)
	{
		if(p&1) mul(trans, ret, ret);
		p>>=1, mul(trans, trans, trans);
	}
}
char s[N];
int main()
{
	scanf("%d%d", &m, &k);
	scanf("%s", s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'a'+1, pre[a[i]]=i;
	for(int i=1; i<=k; ++i) id[i]=i;
	std::sort(id+1, id+k+1, cmp);
	if(m<=2*k)
	{
		for(int i=n+1, cur=1; i<=n+m; ++i, cur=cur==k?1:cur+1) a[i]=id[cur];
		std::fill(pre, pre+k+1, 0);
		for(int i=1; i<=n+m; ++i) f[i]=mval(2ll*f[i-1]%MOD+MOD-(pre[a[i]]?f[pre[a[i]]-1]+1:0)+1), pre[a[i]]=i;
		printf("%d\n", f[n+m]+1);
		return 0;
	}
	for(int i=n+1, cur=1; i<=n+2*k; ++i, cur=cur==k?1:cur+1) a[i]=id[cur];
	std::fill(pre, pre+k+1, 0);
	for(int i=1; i<=n+2*k; ++i) f[i]=mval(2ll*f[i-1]%MOD+MOD-(pre[a[i]]?f[pre[a[i]]-1]+1:0)+1), pre[a[i]]=i;
	m-=2*k;
	for(int i=1; i<=k+1; ++i) ans[i]=f[2*k+n-i+1];
	lim=k+1;
	for(int i=2; i<=k+1; ++i) trans[i][i-1]=1;
	trans[1][1]=2, trans[1][k+1]=MOD-1;
	qp(m);
	for(int i=1; i<=lim; ++i) upt(rans, 1ll*ret[1][i]*ans[i]%MOD);
	printf("%d\n", rans+1);
	return 0;
}