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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int p[3001];
int c[3001];

struct Edge{
    int u, v;
    long long cap, cost;

    Edge(int _u, int _v, long long _cap, long long _cost){
        u = _u; v = _v; cap = _cap; cost = _cost;
    }
};

struct MinCostFlow{
    int n, s, t;
    long long flow, cost;
    vector<vector<int> > graph;
    vector<Edge> e;
    vector<long long> dist;
    vector<int> parent;

    MinCostFlow(int _n){
        // 0-based indexing
        n = _n;
        graph.assign(n, vector<int> ());
    }

    void addEdge(int u, int v, long long cap, long long cost, bool directed = true){
        graph[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));

        graph[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));

        if(!directed)
            addEdge(v, u, cap, cost, true);
    }

    pair<long long, long long> getMinCostFlow(int _s, int _t){
        s = _s; t = _t;
        flow = 0, cost = 0;

        while(SPFA()){
            flow += sendFlow(t, 1LL<<62);
        }

        return make_pair(flow, cost);
    }

    // not sure about negative cycle
    bool SPFA(){
        parent.assign(n, -1);
        dist.assign(n, 1LL<<62);        dist[s] = 0;
        vector<int> queuetime(n, 0);    queuetime[s] = 1;
        vector<bool> inqueue(n, 0);     inqueue[s] = true;
        queue<int> q;                   q.push(s);
        bool negativecycle = false;


        while(!q.empty() && !negativecycle){
            int u = q.front(); q.pop(); inqueue[u] = false;

            for(int i = 0; i < graph[u].size(); i++){
                int eIdx = graph[u][i];
                int v = e[eIdx].v, w = e[eIdx].cost, cap = e[eIdx].cap;

                if(dist[u] + w < dist[v] && cap > 0){
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;

                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v] = true;

                        if(queuetime[v] == n+2){
                            negativecycle = true;
                            break;
                        }
                    }
                }
            }
        }

        return dist[t] != (1LL<<62);
    }

    long long sendFlow(int v, long long curFlow){
        if(parent[v] == -1)
            return curFlow;
        int eIdx = parent[v];
        int u = e[eIdx].u, w = e[eIdx].cost;

        long long f = sendFlow(u, min(curFlow, e[eIdx].cap));

        cost += f*w;
        e[eIdx].cap -= f;
        e[eIdx^1].cap += f;

        return f;
    }
};
int E[3001];
int E2[3001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b; cin >> n >> a >> b;
	MinCostFlow mcmf(n+5);
	int s = 0; 
	int e = n + 3;
	int x = n + 1;
	int y = n + 2;
	mcmf.addEdge(s, x, a, 0);
	mcmf.addEdge(s, y, b, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		E[i] = mcmf.e.size();
		mcmf.addEdge(x, i+1, 1, -p[i]);
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		E2[i] = mcmf.e.size();
		mcmf.addEdge(y, i+1, 1, -c[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		mcmf.addEdge(i, e, 1, 0);
	}
	pair<ll,ll> res = mcmf.getMinCostFlow(s, e);
	ll ans = -res.se;
	cout << ans << '\n';
	vi g,h;
	for(int i = 0; i < n; i++)
	{
		if(mcmf.e[E[i]].cap==0) g.pb(i+1);
	}
	for(int i = 0; i < n; i++)
	{
		if(mcmf.e[E2[i]].cap==0) h.pb(i+1);
	}
	for(int i = 0; i < g.size(); i++)
	{
		cout << g[i] << ' ';
	}
	cout<<'\n';
	for(int i = 0; i < h.size(); i++)
	{
		cout << h[i] << ' ';
	}
}