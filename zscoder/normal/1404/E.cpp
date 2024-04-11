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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

const int N = 211;
int n,m;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
char a[N+10][N+10];

bool isvalid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&a[x][y]=='a');
}

const int MX = N*N+20;
const int INF = int(1e9);
const int INF2 = int(1e6);
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

int getid(int x, int y)
{
	return x*m+y;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		for(int j=0;j<m;j++) 
		{
			if(s[j]=='#') a[i][j]='a';
			//cin>>a[i][j];
			else a[i][j]='b';
		}
	}
	MaxFlow mf;
	int s = MX-2; int e = MX-1;
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<m;k++)
		{
			if(!isvalid(j,k)) continue;
			//if this is in S-cut
			if(!isvalid(j+dx[2],k+dy[2])||a[j+dx[2]][k+dy[2]]!=a[j][k])
			{
				mf.addedge(getid(j,k), e, 1);
			}
			else
			{
				mf.addedge(getid(j,k), getid(j+dx[2],k+dy[2]), 1);
			}
			//if this is in T-cut
			if(!isvalid(j+dx[0],k+dy[0])||a[j+dx[0]][k+dy[0]]!=a[j][k])
			{
				mf.addedge(s, getid(j,k), 1);
			}
			else
			{
				mf.addedge(getid(j+dx[0],k+dy[0]), getid(j,k), 1);
			}
		}
	}
	cout<<mf.maxflow(s,e)<<'\n';
}