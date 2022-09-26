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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
    vector<long long> dist, potential;
    vector<int> parent;
    bool negativeCost;
 
    MinCostFlow(int _n){
        // 0-based indexing
        n = _n;
        graph.assign(n, vector<int> ());
        negativeCost = false;
    }
 
    void addEdge(int u, int v, long long cap, long long cost, bool directed = true){
        if(cost < 0)
            negativeCost = true;
 
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
 
        potential.assign(n, 0);
        if(negativeCost){
            // run Bellman-Ford to find starting potential
            dist.assign(n, 1LL<<62);
            for(int i = 0, relax = false; i < n && relax; i++, relax = false){
                for(int u = 0; u < n; u++){
                    for(int k = 0; k < graph[u].size(); k++){
                        int eIdx = graph[u][i];
                        int v = e[eIdx].v; ll cap = e[eIdx].cap, w = e[eIdx].cost;
 
                        if(dist[v] > dist[u] + w && cap > 0){
                            dist[v] = dist[u] + w;
                            relax = true;
            }   }   }   }
 
            for(int i = 0; i < n; i++){
                if(dist[i] < (1LL<<62)){
                    potential[i] = dist[i];
        }   }   }
 
        while(dijkstra()){
            flow += sendFlow(t, 1LL<<62);
        }
 
        return make_pair(flow, cost);
    }
 
    bool dijkstra(){
        parent.assign(n, -1);
        dist.assign(n, 1LL<<62);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
 
        dist[s] = 0;
        pq.push(ii(0, s));
 
 
        while(!pq.empty()){
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
 
            if(d != dist[u]) continue;
 
            for(int i = 0; i < graph[u].size(); i++){
                int eIdx = graph[u][i];
                int v = e[eIdx].v; ll cap = e[eIdx].cap;
                ll w = e[eIdx].cost + potential[u] - potential[v];
 
                if(dist[u] + w < dist[v] && cap > 0){
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;
 
                    pq.push(ii(dist[v], v));
        }   }   }
 
        // update potential
        for(int i = 0; i < n; i++){
            if(dist[i] < (1LL<<62))
                potential[i] += dist[i];
        }
 
        return dist[t] != (1LL<<62);
    }
 
    long long sendFlow(int v, long long curFlow){
        if(parent[v] == -1)
            return curFlow;
        int eIdx = parent[v];
        int u = e[eIdx].u; ll w = e[eIdx].cost;
 
        long long f = sendFlow(u, min(curFlow, e[eIdx].cap));
 
        cost += f*w;
        e[eIdx].cap -= f;
        e[eIdx^1].cap += f;
 
        return f;
    }
};

int ans[2222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	vi coord;
	vector<pair<ii,ll> > vec;
	for(int i=0;i<n;i++)
	{
		ll s,t,c; cin>>s>>t>>c;
		ll l=s; ll r=s+t;
		coord.pb(l); coord.pb(r);	
		vec.pb({{l,r},c});
	}
	sort(coord.begin(),coord.end()); coord.erase(unique(coord.begin(),coord.end()),coord.end());
	for(int i=0;i<n;i++)
	{
		vec[i].fi.fi=lower_bound(coord.begin(),coord.end(),vec[i].fi.fi)-coord.begin();
		vec[i].fi.se=lower_bound(coord.begin(),coord.end(),vec[i].fi.se)-coord.begin();
	}
	MinCostFlow mcmf(4*n+5);
	int s=4*n+3; int e=4*n+4;
	for(int i=0;i<n;i++)
	{
		mcmf.addEdge(s,2*n+i,1,0);
		mcmf.addEdge(2*n+i,vec[i].fi.fi,1,0);
		mcmf.addEdge(vec[i].fi.se,3*n+i,1,0);
		mcmf.addEdge(2*n+i,3*n+i,1,vec[i].se);
		mcmf.addEdge(3*n+i,e,1,0);
		/*
		mcmf.addEdge(s,vec[i].fi.fi,1,0);
		mcmf.addEdge(vec[i].fi.se,e,1,0);
		mcmf.addEdge(vec[i].fi.fi,vec[i].fi.se,1,vec[i].se);
		*/
		//cerr<<vec[i].fi.fi<<' '<<vec[i].fi.se<<'\n';
	}
	for(int i=0;i+1<coord.size();i++)
	{
		mcmf.addEdge(i,i+1,k,0);
	}
	/*
	for(int i=0;i<coord.size();i++)
	{
		mcmf.addEdge(i,e,int(1e9),0);
	}
	*/
	pair<ll,ll> sol = mcmf.getMinCostFlow(s,e);
	//cout<<sol.se<<'\n';
	for(int i=0;i<n;i++)
	{
		for(int id:mcmf.graph[2*n+i])
		{
			//check if the edge from 2*n+i to 3*n+i is used
			auto ed = mcmf.e[id];
			//cerr<<ed.u<<' '<<ed.v<<' '<<ed.cap<<' '<<ed.cost<<'\n';
			if(ed.v==3*n+i)
			{
				if(ed.cap==1)
				{
					ans[i]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}