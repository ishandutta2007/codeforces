#include <cstdio>
#include <ctime>
#include <set>
#include <vector>
#include <algorithm>
#define pb push_back
#define ull unsigned long long
using std::vector;
using std::set;
const int N=45, T=15;
int n, k, q[T], p[T][N], col[T][N], ok[N], col1[N], cnt[T][3], tt;
void dfs(int u)
{
	int q=::q[u], *p=::p[u], *col=::col[u], *ncol=::col[u+1], *cnt=::cnt[u];
	cnt[0]=cnt[1]=cnt[2]=0;
	if(u==k)
	{
		int r2=0;
		std::copy(col+1, col+n+1, ncol+1);
		col=ncol;
		for(int i=1; i<=q; ++i) ++cnt[col[p[i]]];
		for(int i=1; i<=cnt[1]; ++i) col[p[i]]=1;
		for(int i=cnt[1]+1; i<=cnt[1]+cnt[0]; ++i) col[p[i]]=0;
		for(int i=cnt[1]+cnt[0]+1; i<=q; ++i) col[p[i]]=2;
		for(int i=1, is=1; i<=n; ++i)
		{
			is&=(col[i]==1);
			if(!col[i]&&!ok[i])
			{
				if(!is||r2!=n-i) puts("REJECTED"), exit(0);
			}
		}
		for(int i=1; i<=n; ++i) if(std::max(col[i], 1)<col[i-1]) puts("REJECTED"), exit(0);
		return;
	}
	for(int i=1; i<=q; ++i) ++cnt[col[p[i]]];
	std::copy(col+1, col+n+1, ncol+1);
	for(int i=1; i<=cnt[1]; ++i) ncol[p[i]]=1;
	for(int i=cnt[1]+1; i<=q; ++i) ncol[p[i]]=2;
	for(int i=cnt[1]; i<=cnt[1]+cnt[0]; ++i)
	{
		ncol[p[i]]=1;
		dfs(u+1);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	if(n==1) return puts("ACCEPTED"), 0;
	if(!k) return puts("REJECTED"), 0;
	for(int i=1; i<=k; ++i)
	{
		scanf("%d", q+i);
		for(int j=1; j<=q[i]; ++j) scanf("%d", p[i]+j);
		if(i==k) for(int j=1; j<=q[i]; ++j) ok[p[i][j]]=1;
	}
	dfs(1);
	puts("ACCEPTED");
	return 0;
}