#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

vector<pair<pii, int> > edges;
vector<vi> g;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    edges.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>edges[i].F.F>>edges[i].F.S>>edges[i].S;
        edges[i].F.F--;
        edges[i].F.S--;
    }

    int small=0;
    int large=1e9;
    while(small<=large)
    {
        int mid=(small+large)/2;
        g.resize(n);
        vi btoa(n, -1);
        for(int i=0; i<n; i++) g[i].clear();
        for(int i=0; i<edges.size(); i++)
        {
            if(edges[i].S<=mid) g[edges[i].F.F].push_back(edges[i].F.S);
        }
        if(hopcroftKarp(g, btoa)==n) large=mid-1;
        else small=mid+1;
    }
    if(small>1e9) cout<<-1<<endl;
    else cout<<small<<endl;




    return 0;
}