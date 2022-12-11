#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
struct graph
{
	int v[400010];
	int t[400010];
	int h[200010];
	int n;
	graph()
	{
		n=0;
		memset(h,0,sizeof h);
	}
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
};
graph g;
const ll p=1000000007;
ll pw[200010];
int x[200010];
int y[200010];
int d[200010];
int c[200010];
int point;
int edge;
int b[200010];
void dfs(int x,int f)
{
	b[x]=1;
	point++;
	int i;
	for(i=g.h[x];i;i=g.t[i])
	{
		if(g.v[i]!=f)
			edge++;
		if(!b[g.v[i]])
			dfs(g.v[i],x);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		c[i]=x[i];
		d[i]=y[i];
	}
	sort(c+1,c+n+1);
	sort(d+1,d+n+1);
	for(i=1;i<=n;i++)
	{
		x[i]=lower_bound(c+1,c+n+1,x[i])-c;
		y[i]=lower_bound(d+1,d+n+1,y[i])-d;
		g.add(x[i],y[i]+n);
		g.add(y[i]+n,x[i]);
	}
	pw[0]=1;
	for(i=1;i<=2*n;i++)
		pw[i]=pw[i-1]*2%p;
	ll ans=1;
	for(i=1;i<=2*n;i++)
		if(!b[i])
		{
			edge=point=0;
			dfs(i,0);
			if(edge==point-1)
				ans=ans*(pw[point]-1)%p;
			else
				ans=ans*pw[point]%p;
		}
	printf("%I64d\n",ans);
	return 0;
}