#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MX = 555;
const int INF = int(1e8);

struct MaxFlow 
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

ll n,m; 

int getid(int i, int j)
{
	return i*m+j;
}

bool isvalid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}

vector<ii> moves;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	ll ans = 0;
	if(m>18)
	{
		ll tmp = (m-13)/6;
		m -= tmp*6;
		ans += tmp*6*n;
	}
	if(n>18)
	{
		ll tmp = (n-13)/6;
		n -= tmp*6;
		ans += tmp*6*m;
	}
	for(int i=-3;i<=3;i++)
	{
		for(int j=-3;j<=3;j++)
		{
			if(abs(i)+abs(j)==3) moves.pb(mp(i,j));
		}
	}
	MaxFlow mf;
	int s=MX-1; int e=MX-2;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if((i+j)%2==0) 
			{
				mf.addedge(getid(i,j),e,1); continue;
			}
			mf.addedge(s,getid(i,j),1);
			for(ii d:moves)
			{
				int x=i+d.fi; int y=j+d.se;
				if(isvalid(x,y))
				{
					mf.addedge(getid(i,j),getid(x,y),1);
				}
			}
		}
	}
	ans+=mf.maxflow(s,e)*2;
	cout<<ans<<'\n';
}