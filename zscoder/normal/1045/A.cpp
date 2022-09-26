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
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

struct Edge {
    int v;
    int flow, cap;
    int rev;
};

const int SZ = 20011;
struct MaxFlow {
    vector<Edge> adj[SZ];
    int excess[SZ];
    int dist[SZ], count[SZ+1], b = 0;
    bool active[SZ];
    vi B[SZ];
    
    void addedge(int u, int v, int C) {
        Edge a{v, 0, C, sz(adj[v])};
        Edge b{u, 0, 0, sz(adj[u])};
        adj[u].pb(a), adj[v].pb(b); 
    } 

    void enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < SZ) {
            active[v] = 1;
            B[dist[v]].pb(v);
            b = max(b, dist[v]);
        }
    }

    void push (int v, Edge &e) {
        int amt = min(excess[v], e.cap-e.flow);
        if (dist[v] == dist[e.v]+1 && amt > 0) {
            e.flow += amt, adj[e.v][e.rev].flow -= amt;
            excess[e.v] += amt, excess[v] -= amt;
            enqueue(e.v);
        }
    }

    void gap (int k) {
        F0R(v,SZ) if (dist[v] >= k) {
            count[dist[v]] --;
            dist[v] = SZ;
            count[dist[v]] ++;
            enqueue(v);
        }
    }

    void relabel (int v) {
        count[dist[v]] --; dist[v] = SZ;
        for (auto e: adj[v]) if (e.cap> e.flow) dist[v] = min(dist[v], dist[e.v] + 1);
        count[dist[v]] ++;
        enqueue(v);
    }

    void discharge(int v) {
        for (auto &e: adj[v]) {
            if (excess[v] > 0) push(v,e);
            else break;
        }
        if (excess[v] > 0) {
            if (count[dist[v]] == 1) gap(dist[v]); 
            else relabel(v);
        }
    }

    int maxFlow (int s, int t) {
        for (auto &e: adj[s]) excess[s] += e.cap;
        
        count[0] = SZ;
        enqueue(s); active[t] = 1;
        
        while (b >= 0) {
            if (sz(B[b])) {
                int v = B[b].back(); B[b].pop_back();
                active[v] = 0; discharge(v);
            } else b--;
        }
        return excess[t];
    }
};
MaxFlow mf;
vector<ii> ans;
int taken[5111];
const int INF=int(1e6);
void build(int n) {  // build the tree
  for (int i = n - 1; i > 0; --i) 
  {
	  mf.addedge(i,i*2,INF);
	  mf.addedge(i,i*2+1,INF);
  }
}
int query(int n, int l, int r, int source) {  // add edge on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) 
    {
		mf.addedge(source, l, 1);
		l++;
	}
    if (r&1) 
    {
		r--;
		mf.addedge(source, r, 1);
	}
  }
  return res;
}
/*
const int MAXN1 = 5001;
const int MAXN2 = 5001;
const int MAXM = MAXN1*MAXN2+1;

int n1, n2, edges;
int last[MAXN1];
int pre[MAXM];
short head[MAXM];
short matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    pre[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = pre[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = pre[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
*/
vector<pair<int,vi> > queries;
bool finalans[11111];
bitset<5111> B[5111];
int cnt[5111];
int cnta[5111];
bool used[5111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int s = SZ-2; int e = SZ-1;
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		mf.addedge(m+i,e,1);
	}
	build(m);
	for(int i=0;i<n;i++)
	{
		int t; cin>>t;
		if(t==0)
		{
			mf.addedge(s,2*m+i,1);
			vi vec; int k; cin>>k;
			for(int j=0;j<k;j++)
			{
				int x; cin>>x; x--; vec.pb(x);
				mf.addedge(2*m+i, x+m, 1);
			}
			queries.pb(mp(t,vec));
		}
		else if(t==1)
		{
			mf.addedge(s,2*m+i,1);
			int l,r; cin>>l>>r; l--; r--;
			query(m,l,r+1,2*m+i);
			vi vv={l,r};
			queries.pb(mp(t,vv));
		}
		else
		{
			mf.addedge(s,2*m+i,2);
			int a,b,c; cin>>a>>b>>c; a--; b--; c--;
			mf.addedge(2*m+i,m+a,1);
			mf.addedge(2*m+i,m+b,1);
			mf.addedge(2*m+i,m+c,1);
			vi vv={a,b,c};
			queries.pb(mp(t,vv));
		}
	}
	cout<<mf.maxFlow(s,e)<<'\n';
	for(int i=0;i<m;i++)
	{
		for(auto ed:mf.adj[m+i])
		{
			if(ed.v==e&&ed.flow==1)
			{
				finalans[i]=1; break;
			}
		}
	}
	memset(taken,-1,sizeof(taken));
	for(int i=0;i<n;i++)
	{
		int t=queries[i].fi;
		vi vec=queries[i].se;
		if(t==2)
		{
			vi used; vi zz;
			for(auto ed:mf.adj[2*m+i])
			{
				if(ed.v>=m&&ed.v<2*m)
				{
					if(ed.flow==1) used.pb(ed.v-m);
					else zz.pb(ed.v-m);
				}
			}
			if(used.empty()) continue;
			while(used.size()<2)
			{
				int bb = zz.back(); zz.pop_back();
				if(finalans[bb]){used.pb(bb);}
			}
			for(int v:used)
			{
				taken[v]=i; ans.pb(mp(i+1,v+1));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		int t=queries[i].fi;
		vi vec=queries[i].se;
		if(t==0)
		{
			vi used; vi zz;
			for(auto ed:mf.adj[2*m+i])
			{
				if(ed.v>=m&&ed.v<2*m)
				{
					if(ed.flow==1) used.pb(ed.v-m);
					else zz.pb(ed.v-m);
				}
			}
			if(!used.empty())
			{
				if(taken[used[0]]==-1)
				{
					taken[used[0]]=i;
					ans.pb(mp(i+1,used[0]+1));
				}
			}
		}
	}
	vi remaining;
	for(int i=0;i<m;i++)
	{
		if(taken[i]==-1&&finalans[i]) remaining.pb(i);
	}
	vector<pair<int,ii> > intervals;
	for(int i=0;i<n;i++)
	{
		int t=queries[i].fi;
		vi vec=queries[i].se;
		if(t==1)
		{
			intervals.pb(mp(i,mp(vec[0],vec[1])));
		}
	}
	//MaxFlow mf2;
	int lsiz = intervals.size(); int rsiz = remaining.size();
	/*
	init(lsiz,rsiz);
	for(int i=0;i<lsiz;i++)
	{
		//mf2.addedge(s,i,1); 
		int l = intervals[i].se.fi; int r = intervals[i].se.se; 
		for(int j=0;j<rsiz;j++)
		{
			if(l<=remaining[j]&&remaining[j]<=r)
			{
				//mf2.addedge(i,j+lsiz,1);
				addEdge(i,j);
			}
		}
	}
	maxMatching();
	for(int i=0;i<lsiz;i++)
	{
		if(matching[i]!=-1)
		{
			ans.pb(mp(intervals[i].fi+1,remaining[matching[i]]+1));
		}
	}
	*/
	for(int i=0;i<lsiz;i++)
	{
		int l = intervals[i].se.fi; int r = intervals[i].se.se; 
		for(int j=0;j<rsiz;j++)
		{
			if(l<=remaining[j]&&remaining[j]<=r)
			{
				B[j].set(i,1);
				cnt[j]++;
				cnta[i]++;
			}
		}
	}
	while(1)
	{
		int MN=int(1e9); int u=-1;
		for(int i=0;i<rsiz;i++)
		{
			if(used[i]) continue;
			if(cnt[i]<MN){MN=cnt[i]; u=i;}
		}
		if(u==-1) break;
		used[u]=1; 
		//int u = (*vec.begin()).se; vec.erase(vec.begin()); assert(!used[u]&&u>=0&&u<m); used[u]=1; 
		int mn=int(1e9); int id=-1;
		for(int i=0;i<lsiz;i++)
		{
			if(B[u][i])
			{
				if(cnta[i]<mn)
				{
					mn=cnta[i]; id=i;
				}
			}
		}
		assert(id!=-1);
		ans.pb(mp(intervals[id].fi+1, remaining[u]+1));
		for(int i=0;i<lsiz;i++)
		{
			if(B[u][i])
			{
				B[u].set(i,0);
				cnta[i]--; cnt[u]--;
			}
		}
		for(int i=0;i<rsiz;i++)
		{
			if(B[i][id])
			{
				B[i].set(id,0);
				cnt[i]--;
			}
		}
	}
	for(ii v:ans)
	{
		cout<<v.fi<<' '<<v.se<<'\n';
	}
}