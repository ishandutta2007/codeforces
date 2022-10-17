#include<bits/stdc++.h>
using namespace std;

const int N=4e6+1e3+7,P=998244353;

typedef long long ll;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int n,m,u[N],v[N];

vector<pii>g[N];

struct node{
	ll d;
	int x;
	node(int _x=0,ll _d=0){x=_x,d=_d;};
};

bool operator <(node a,node b)
{
	return a.d>b.d;
}

priority_queue<node>q;

ll d[N];

void dij()
{
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int x=t.x;
		if(d[x]!=t.d)
			continue;
		for(int i=0;i<g[x].size();i++)
		{
			int v=g[x][i].fs;
			if(d[v]>d[x]+g[x][i].sd)
			{
				d[v]=d[x]+g[x][i].sd;
				q.push(node(v,d[v]));
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]);
	for(int j=1;j<=20;j++)
	{
		if(j!=20)
			for(int i=1;i<=n;i++)
				g[i+n*(j-1)].push_back(mp(i+n*j,1<<(j-1)));
		for(int i=1;i<=m;i++)
		{
			if(j&1)
				g[u[i]+n*(j-1)].push_back(mp(v[i]+n*(j-1),1));
			else
				g[v[i]+n*(j-1)].push_back(mp(u[i]+n*(j-1),1));
		}
	}
	fill(d+1,d+n*20+1,1e18);
	d[1]=0;
	q.push(node(1,0));
	dij();
	ll ans=1e15;
	for(int i=1;i<=20;i++)
		ans=min(ans,d[i*n]);
	if(ans!=1e15)
	{
		printf("%lld\n",ans%P);
		return 0;
	}
	for(int i=1;i<=n*20;i++)
		g[i].clear();
	for(int i=1;i<=n;i++)
		g[i].push_back(mp(i+n,1<<25)),g[i+n].push_back(mp(i,1<<25));
	for(int i=1;i<=m;i++)
		g[u[i]+n].push_back(mp(v[i]+n,1)),g[v[i]].push_back(mp(u[i],1));
	fill(d+n+1,d+n*2+1,1e18);
	for(int i=1;i<=n;i++)
		if(d[i+19*n]!=1e18)
		{
			d[i]=d[i+19*n]-((1<<19)-1)+19ll*(1<<25); 
			q.push(node(i,d[i]));
		}
	dij();
	ll w1=d[n],w2=d[2*n];
	ll w11=w1/(1<<25),w12=w1%(1<<25);
	ll w21=w2/(1<<25),w22=w2%(1<<25);
	ll ans1,ans2;
	if(w1<w2)
		ans1=w11,ans2=w12;
	else
		ans1=w21,ans2=w22;
	printf("%lld\n",((qpow(2,ans1)-1+P)%P+ans2)%P);
}
/*
21 20
2 1 
2 3
4 3
4 5
6 5
6 7
8 7
8 9
10 9
10 11
12 11
12 13
14 13
14 15
16 15
16 17
18 17
18 19
20 19
20 21
*/