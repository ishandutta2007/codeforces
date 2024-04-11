#include <cstdio>
#include <algorithm>
const int N=200005;
int n, p[N], vis[N], stk[N][2], top;
int st[N], tp;
inline void swp(int x, int y)
{
	stk[++top][0]=x, stk[top][1]=y;
}
inline void solveone(int x)
{
	if(x==p[x]) return;
	int y=p[x];
	while(p[y]!=x)
	{
		swp(x, y);
		y=p[y];
	}
	swp(y, p[x]);
	swp(y, x);
	swp(x, p[x]);
}
inline void solvetwo(int u, int v)
{
	swp(u, v);
	int x=p[v];
	while(x!=v) swp(u, x), x=p[x];
	x=p[u];
	while(x!=u) swp(x, v), x=p[x];
	swp(u, v);
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", p+i);
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		st[++tp]=i;
		int x=i;
		while(!vis[x])
		{
			vis[x]=1;
			x=p[x];
		}
	}
	for(int i=1; i<=tp; i+=2)
	{
		if(i<tp) solvetwo(st[i], st[i+1]);
		else
		{
			int x=st[i];
			if(p[p[x]]!=x) solveone(x);
			else p[st[i-1]]=st[i-1], solvetwo(st[i-1], x);
		}
	}
	printf("%d\n", top);
	for(int i=1; i<=top; ++i) printf("%d %d\n", stk[i][0], stk[i][1]);
	return 0;
}