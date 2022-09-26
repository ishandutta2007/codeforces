#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MX = 2222;
const int INF = int(1e9);

struct MaxFlow //by yutaka1999, have to define INF and MX (the Max number of vertices)
{
	struct edge
	{
		int to,cap,rev;
		edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
	};
	vector <edge> vec[MX];
	int level[MX];
	int iter[MX];
	
	void addedge(int s,int t,int c) //adds an edge of cap c to the flow graph
	{
		int S=vec[s].size(),T=vec[t].size();
		vec[s].push_back(edge(t,c,T));
		vec[t].push_back(edge(s,0,S));
	}
	void bfs(int s)
	{
		memset(level,-1,sizeof(level));
		queue <int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty())
		{
			int v = que.front();que.pop();
			for(int i=0;i<vec[v].size();i++)
			{
				edge&e=vec[v][i];
				if (e.cap>0&&level[e.to]<0)
				{
					level[e.to]=level[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	ll flow_dfs(int v,int t,ll f)
	{
		if (v==t) return f;
		for(int &i=iter[v];i<vec[v].size();i++)
		{
			edge &e=vec[v][i];
			if (e.cap>0&&level[v]<level[e.to])
			{
				ll d=flow_dfs(e.to,t,min(f,ll(e.cap)));
				if (d>0)
				{
					e.cap-=d;
					vec[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	ll maxflow(int s,int t) //finds max flow using dinic from s to t
	{
		ll flow = 0;
		while(1)
		{
			bfs(s);
			if (level[t]<0) return flow;
			memset(iter,0,sizeof(iter));
			while (1)
			{
				ll f=flow_dfs(s,t,INF);
				if(f==0) break;
				flow += f;
			}
		}
	}
};

bool isadj(ii a, ii b)
{
	return (abs(a.fi-b.fi)+abs(a.se-b.se)==1);
}

int getid(int x, int ty)
{
	return (x*2+ty);
}

int gettype(ii a)
{
	a.fi=abs(a.fi); a.se=abs(a.se);
	if(a.fi%2==0&&a.se%2==0) return 1;
	if(a.fi%2==0&&a.se%2==1) return 2;
	if(a.fi%2==1&&a.se%2==0) return 0;
	return 3;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	MaxFlow mf;
	ll sum=0;
	vector<pair<ii,int> > vec;
	for(int i=0;i<n;i++)
	{
		int x,y,w; cin>>x>>y>>w; sum+=w;
		vec.pb({{x,y},w});
	}
	int s=MX-2; int e=MX-1;
	for(int i=0;i<n;i++)
	{
		if(gettype(vec[i].fi)==0) mf.addedge(s,getid(i,0),INF);
		if(gettype(vec[i].fi)==3) mf.addedge(getid(i,1),e,INF);
		mf.addedge(getid(i,0),getid(i,1),vec[i].se);
		//cerr<<"TY: "<<i<<' '<<gettype(vec[i].fi)<<'\n';
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(isadj(vec[i].fi,vec[j].fi)&&gettype(vec[j].fi)-gettype(vec[i].fi)==1)
			{
				mf.addedge(getid(i,1),getid(j,0),INF);
			}
		}
	}
	cout<<sum-mf.maxflow(s,e)<<'\n';
}