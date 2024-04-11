#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

int n,m,sx,sy,tx,ty;

int S,T;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g[N];

void add(int x,int y,int z)
{
	g[x].push_back(mp(y,z));
	g[y].push_back(mp(x,z));
}

int x[N],y[N],a[N],b[N];

int d[N];

priority_queue<pii,vector<pii>,greater<pii>>q;

void dijkstra()
{
	fill(d+S,d+T+1,1e18);
	d[S]=0;
	q.push(mp(d[S],S));
	while(!q.empty())
	{
		pii t=q.top();
		q.pop();
		int x=t.sd;
		if(d[x]!=t.fs)
			continue;
		for(auto [v,w]:g[x])
		{
			if(d[v]>d[x]+w)
			{
				d[v]=d[x]+w;
				q.push(mp(d[v],v));
			}
		}
	}
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
	S=0,T=m*3+1;
	add(S,T,abs(sx-tx)+abs(sy-ty));
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		add(S,i,min(abs(x[i]-sx),abs(y[i]-sy)));
		add(T,i,abs(x[i]-tx)+abs(y[i]-ty));
		a[i]=x[i],b[i]=y[i];
	}
	sort(a+1,a+m+1);
	sort(b+1,b+m+1);
	for(int i=1;i<m;i++)
	{
		add(i+m,i+m+1,a[i+1]-a[i]);
		add(i+m*2,i+m*2+1,b[i+1]-b[i]);
	}
	for(int i=1;i<=m;i++)
	{
		add(i,m+lower_bound(a+1,a+m+1,x[i])-a,0);
		add(i,m*2+lower_bound(b+1,b+m+1,y[i])-b,0);
	}
	dijkstra();
	printf("%lld\n",d[T]);
}