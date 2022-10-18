#include <cstdio>
#include <map>
#include <bitset>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using std::bitset;
const int N=55, M=50005;
int n, a[N], sum, b[2][N], vis[N], tp, ans=INF, rx, rs;
bitset<N*M/2> f[N][N>>1], g[N][N>>1];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=2*n; ++i) scanf("%d", a+i), sum+=a[i];
	std::sort(a+1, a+2*n+1);
	f[2*n][n][0]=1;
	for(int x=2*n; x>1; --x)
	{
		for(int l=1; l<=n; ++l)
		{
			if(l>1) f[x-1][l-1]|=f[x][l]<<a[x];
			f[x-1][l]|=f[x][l];
		}
		for(int s=0; s<=sum; ++s) if(f[x][1][s])
		{
			if(ans>std::max(sum-s, s+a[x]+a[1]))
			{
				ans=std::max(sum-s, s+a[x]+a[1]);
				rx=x, rs=s;
			}
		}
	}
	g[rx][1][rs]=1;
	for(int x=rx; x<2*n; ++x)
	{
		for(int l=1; l<=n; ++l)
		{
			g[x+1][l]|=g[x][l];
			g[x+1][l+1]|=g[x][l]>>a[x+1];
		}
	}
	int x=2*n, l=n, s=0;
	while(1)
	{
		if(l==1&&ans==std::max(sum-s, s+a[x]+a[1]))
		{
			b[0][++tp]=x;
			break;
		}
		if(g[x-1][l][s]) --x;
		else if(s+a[x]<=sum&&g[x-1][l-1][s+a[x]]) b[0][++tp]=x, s+=a[x], --l, --x;
		else exit(114);
	}
	std::reverse(b[0]+1, b[0]+n+1);
	tp=0;
	for(int i=1; i<=n; ++i) vis[b[0][i]]=1;
	for(int i=2*n; i; --i) if(!vis[i]) b[1][++tp]=i;
	for(int i=1; i<=n; ++i) printf("%d ", a[b[0][i]]);
	puts("");
	for(int i=1; i<=n; ++i) printf("%d ", a[b[1][i]]);
	puts("");
	return 0;
}