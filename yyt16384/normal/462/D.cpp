#include <cstdio>
#include <vector>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
const int MOD=1000000007;
int n;
std::vector<int> sons[MAXN];
int col[MAXN];
int f[MAXN];
int g[MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=1;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		sons[x].push_back(i);
	}
	for (int i=0;i<n;++i) scanf("%d",&col[i]);
}
void solve()
{
	static int pres[MAXN];
	static int sufs[MAXN];
	for (int i=n-1;i>=0;--i)
	{
		int m=sons[i].size();
		pres[0]=1;
		for (int j=0;j<m;++j)
			pres[j+1]=(long long)pres[j]*f[sons[i][j]]%MOD;
		sufs[m]=1;
		for (int j=m-1;j>=0;--j)
			sufs[j]=(long long)sufs[j+1]*f[sons[i][j]]%MOD;
		f[i]=pres[m];
		for (int j=0;j<m;++j)
			g[i]=(g[i]+(long long)pres[j]*g[sons[i][j]]%MOD*sufs[j+1])%MOD;
		if (col[i])
		{
			g[i]=f[i];f[i]=0;
		}
		f[i]=(f[i]+g[i])%MOD;
	}
	printf("%d\n",g[0]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}