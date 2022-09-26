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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int INF = int(1e9);
const int MX = 2111;

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

ii points[1234];
vi row[1234];
vi col[1234];
vector<pair<ii,ii> > hori;
vector<pair<ii,ii> > vert;
bool mvc[2222];
vector<ii> adj[2222];
bool matched[2222];
int visited[2222][2];
void dfs(int u, int pre=1)
{
	visited[u][pre]=1;
	for(ii x:adj[u])
	{
		if(x.se!=pre&&!visited[x.fi][pre^1])
		{
			dfs(x.fi,pre^1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<int> R,C;
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		R.pb(x); C.pb(y); points[i]=mp(x,y);
	}
	sort(R.begin(),R.end()); R.erase(unique(R.begin(),R.end()),R.end());
	sort(C.begin(),C.end()); C.erase(unique(C.begin(),C.end()),C.end());
	for(int i=0;i<n;i++)
	{
		points[i].fi = lower_bound(R.begin(),R.end(),points[i].fi)-R.begin();
		points[i].se = lower_bound(C.begin(),C.end(),points[i].se)-C.begin();
		col[points[i].fi].pb(points[i].se);
		row[points[i].se].pb(points[i].fi);
	}
	MaxFlow mf;
	int s=MX-1; int e=MX-2;
	int id=0;
	for(int i=0;i<C.size();i++)
	{
		sort(row[i].begin(),row[i].end());
		for(int j=1;j<row[i].size();j++)
		{
			mf.addedge(s,id,1);
			hori.pb(mp(mp(row[i][j-1],row[i][j]),mp(i,id)));
			id++;
		}
	}
	for(int i=0;i<R.size();i++)
	{
		sort(col[i].begin(),col[i].end());
		for(int j=1;j<col[i].size();j++)
		{
			mf.addedge(id,e,1);
			vert.pb(mp(mp(col[i][j-1],col[i][j]),mp(i,id)));
			id++;
		}
	}
	for(int i=0;i<hori.size();i++)
	{
		for(int j=0;j<vert.size();j++)
		{
			int l1 = hori[i].fi.fi; int r1 = hori[i].fi.se; int y = hori[i].se.fi; int lab1 = hori[i].se.se;
			int l2 = vert[j].fi.fi; int r2 = vert[j].fi.se; int x = vert[j].se.fi; int lab2 = vert[j].se.se;
			if(x>l1&&x<r1&&y>l2&&y<r2)
			{
				//cerr<<"ADD EDGE : "<<lab1<<' '<<lab2<<'\n';
				mf.addedge(lab1,lab2,1);
			}
		}
	}
	mf.maxflow(s,e);
	for(int i=0;i<hori.size();i++)
	{
		for(auto E:mf.vec[i])
		{
			if(E.to!=s)
			{
				adj[i].pb(mp(E.to,1-E.cap));
				adj[E.to].pb(mp(i,1-E.cap));
				if(E.cap==0){matched[i]=matched[E.to]=1;}
			}
		}
	}
	for(int i=0;i<hori.size();i++)
	{
		if(!matched[i])
		{
			dfs(i);
		}
	}
	vi K;
	for(int i=0;i<hori.size();i++)
	{
		if(!visited[i][0]&&!visited[i][1]) K.pb(i);
	}
	for(int i=hori.size();i<hori.size()+vert.size();i++)
	{
		if(!visited[i][0]&&!visited[i][1])
		{
			
		}
		else K.pb(i);
	}
	for(int v:K)
	{
		//cerr<<"MVC : "<<v<<'\n';
		mvc[v]=1;
	}
	vector<pair<ii,ii> > rows;
	vector<pair<ii,ii> > cols;
	for(int i=0;i<hori.size();i++)
	{
		int l1 = hori[i].fi.fi; int r1 = hori[i].fi.se; int y = hori[i].se.fi; int lab1 = hori[i].se.se;
		if(!mvc[lab1])
		{
			if(!rows.empty()&&rows.back().se.se==y&&rows.back().se.fi==l1)
			{
				int L = rows.back().fi.fi;
				rows.pop_back();
				rows.pb(mp(mp(L,y),mp(r1,y)));
			}
			else rows.pb(mp(mp(l1,y),mp(r1,y)));
		}
	}
	for(int i=0;i<vert.size();i++)
	{
		int l2 = vert[i].fi.fi; int r2 = vert[i].fi.se; int x = vert[i].se.fi; int lab2 = vert[i].se.se;
		if(!mvc[lab2])
		{
			if(!cols.empty()&&cols.back().se.fi==x&&cols.back().se.se==l2)
			{
				int L = cols.back().fi.se;
				cols.pop_back();
				cols.pb(mp(mp(x,L),mp(x,r2)));
			}
			else cols.pb(mp(mp(x,l2),mp(x,r2)));
		}
	}
	for(int i=0;i<n;i++)
	{
		int x=points[i].fi; int y=points[i].se;
		{
			bool ex=0;
			for(auto X:rows)
			{
				if(X.fi.fi<=x&&x<=X.se.fi&&X.fi.se<=y&&X.se.se>=y) {ex=1; break;}
			}
			if(!ex){rows.pb(mp(mp(x,y),mp(x,y)));}
		}
		{
			bool ex=0;
			for(auto X:cols)
			{
				if(X.fi.fi<=x&&x<=X.se.fi&&X.fi.se<=y&&X.se.se>=y) {ex=1; break;}
			}
			if(!ex){cols.pb(mp(mp(x,y),mp(x,y)));}
		}
	}
	cout<<rows.size()<<'\n';
	for(auto X:rows)
	{
		cout<<R[X.fi.fi]<<' '<<C[X.fi.se]<<' '<<R[X.se.fi]<<' '<<C[X.se.se]<<'\n';
	}
	cout<<cols.size()<<'\n';
	for(auto X:cols)
	{
		cout<<R[X.fi.fi]<<' '<<C[X.fi.se]<<' '<<R[X.se.fi]<<' '<<C[X.se.se]<<'\n';
	}
}