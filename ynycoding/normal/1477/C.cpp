#include <cstdio>
#include <algorithm>
#define ll long long
const int N=5005;
int n, x[N], y[N], vis[N], id, cur;
ll mx;
inline ll dis(int a, int b) { return 1ll*(x[a]-x[b])*(x[a]-x[b])+1ll*(y[a]-y[b])*(y[a]-y[b]); }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i);
	cur=1;
	vis[1]=1;
	printf("%d ", 1);
	for(int i=1; i<n; ++i)
	{
		mx=0;
		for(int j=1; j<=n; ++j) if(!vis[j]&&dis(cur, j)>mx)
			mx=dis(cur, j), id=j;
		cur=id;
		printf("%d ", cur);
		vis[cur]=1;
	}
	return 0;
}