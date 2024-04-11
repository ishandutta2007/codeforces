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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MX = 111;
const int INF = 10000000;

struct MaxFlow //by yutaka1999
{
	struct edge
	{
		int to,cap,rev;
		edge(int to=0,int cap=0,int rev=0):to(to),cap(cap),rev(rev){}
	};
	vector <edge> vec[MX];
	int level[MX];
	int iter[MX];
	
	void addedge(int s,int t,int c)
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
	int flow_dfs(int v,int t,int f)
	{
		if (v==t) return f;
		for(int &i=iter[v];i<vec[v].size();i++)
		{
			edge &e=vec[v][i];
			if (e.cap>0&&level[v]<level[e.to])
			{
				int d=flow_dfs(e.to,t,min(f,e.cap));
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
	int max_flow(int s,int t)
	{
		int flow = 0;
		while(1)
		{
			bfs(s);
			if (level[t]<0) return flow;
			memset(iter,0,sizeof(iter));
			while (1)
			{
				int f=flow_dfs(s,t,INF);
				if(f==0) break;
				flow += f;
			}
		}
	}
};


/*
template<typename TT, int V, int E> struct DinicFlow //by KADR
{
	int ds[V + 1], q[V + 1], nx[E + 1], last[V + 1], ver[E + 1], now[V + 1], n, edgesCount, S, T;
	TT cap[E + 1];
	DinicFlow() :n(0), S(0), T(0), edgesCount(0){}
	DinicFlow(int _n) :n(_n), S(0), T(0), edgesCount(0){}
	inline void reset(int _n = 0)
	{
		edgesCount = 0;
		n = _n;
		memset(last, -1, n*sizeof(int));
	}
	inline void addEdge(int v, int w, TT c, TT rc)
	{
		ver[edgesCount] = w; cap[edgesCount] = c;  nx[edgesCount] = last[v]; last[v] = edgesCount++;
		ver[edgesCount] = v; cap[edgesCount] = rc; nx[edgesCount] = last[w]; last[w] = edgesCount++;
	}
	inline bool bfs()
	{
		memset(ds, 63, n*sizeof(int));
		int a = 0, b = 0;
		ds[T] = 0;
		q[0] = T;
		while (a <= b)
		{
			int v = q[a++];
			for (int w = last[v]; w >= 0; w = nx[w])
			{
				if (cap[w ^ 1] && ds[ver[w]]>ds[v] + 1)
				{
					ds[ver[w]] = ds[v] + 1;
					q[++b] = ver[w];
				}
			}
		}
		return ds[S]<1000000000;
	}
	TT dfs(int v, TT cur)
	{
		if (v == T) return cur;
		for (int &w = now[v]; w >= 0; w = nx[w])
		{
			if (cap[w] && ds[ver[w]] == ds[v] - 1)
			{
				TT rr = dfs(ver[w], min(cur, cap[w]));
				if (rr)
				{
					cap[w] -= rr;
					cap[w ^ 1] += rr;
					return rr;
				}
			}
		}
		return 0;
	}
	inline TT maxFlow()
	{
		TT ans = 0;
		while (bfs())
		{
			memcpy(now, last, n*sizeof(int));
			TT tf = dfs(S, 1000000000);
			while (tf) 
			{
				//cerr << tf << endl;
				ans += tf;
				tf = dfs(S, 1000000000);
			}
		}
		return ans;
	}
};
*/
int a[101];
//DinicFlow <int, 103, 1003> flow;

vi pf;
vi p[101];
ii pairs[101];
int ans;
int n, m; 

int solve(int x)
{
	MaxFlow flow;
	//flow.S = 0;
	//flow.T = n + 1;
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		while(a[i]%pf[x]==0)
		{
			cnt++;
			a[i]/=pf[x];
		}
		if(i&1) flow.addedge(0, i, cnt);
		else flow.addedge(i, n+1, cnt);
	}
	for(int i = 0; i < m; i++)
	{
		int l = pairs[i].fi; int r = pairs[i].se;
		flow.addedge(l, r, 10000000);
	}
	return flow.max_flow(0, n+1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int x = a[i];
		for(int j = 2; j*j <= x; j++)
		{
			if(x%j==0) pf.pb(j);
			while(x%j==0)
			{
				p[i].pb(j);
				x/=j;
			}
		}
		if(x>1)
		{
			pf.pb(x); p[i].pb(x);
		}
	}
	sort(pf.begin(), pf.end());
	pf.erase(unique(pf.begin(), pf.end()), pf.end());
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < p[i].size(); j++)
		{
			p[i][j] = lower_bound(pf.begin(), pf.end(), p[i][j]) - pf.begin();
		}
	}
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		if(!(u&1)) swap(u, v);
		pairs[i] = ii(u, v);
	}
	for(int i = 0; i < pf.size(); i++)
	{
		ans += solve(i);
	}
	cout << ans;
}