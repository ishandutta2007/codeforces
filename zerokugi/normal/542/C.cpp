#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0) : d(n, -1){}
  bool unite(int x, int y) {
    if ((x = root(x)) != (y = root(y))){
      if (d[y] < d[x]) swap(x, y);
      d[x] += d[y]; d[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y){return root(x) == root(y);}
  int root(int x){return d[x] < 0 ? x : d[x] = root(d[x]);}
  int size(int x=-1) {return x<0 ? d.size() : -d[root(x)];}
};

// g: Ot
// rg: tOt
// ng: Ot
// comps A_
// TopologicalSort: Arootg|WJ
// SO(E+V)

struct SCC{
	int n;
	vector<vi> g, rg, ng;
	vector<vi> comps;
	UnionFind uf;
	SCC(const vector<vi> &g):n(g.size()),g(g),rg(n),ng(n),comps(n),uf(n){
		REP(i, n)REP(j, g[i].size()) rg[g[i][j]].pb(i);
		vi d, vis(n);
		REP(i, n) if(!vis[i]){
			stack<int> st;
			st.push(i);
			while(!st.empty()){
				int r = st.top(); st.pop();
				if(r >= 0){
					if(vis[r]) continue;
					vis[r] = 1;
					st.push(~r);
					for(int v : g[r]) if(!vis[v]) st.push(v);
				}else d.push_back(~r);
			}
		}
		vis = vi(n);
		RREP(i, n) if(!vis[d[i]]){
			stack<int> st;
			st.push(d[i]);
			while(!st.empty()){
				int r = st.top(); st.pop();
				if(vis[r]) continue;
				vis[r] = 1;
				for(int v : rg[r]) if(!vis[v]){
					uf.unite(r, v);
					st.push(v);
				}
			}
		}
		REP(i, n) for(int v : g[i]) if(uf.root(i) != uf.root(v)) ng[uf.root(i)].push_back(uf.root(v));
		REP(i, n){
			sort(ALL(ng[i]));
			UNIQUE(ng[i]);
		}
		REP(i, n) comps[uf.root(i)].pb(i);
	}
	vi TopologicalSort(){
		vi deg(n), res;
		REP(i, n)REP(j, ng[i].size()) deg[ng[i][j]] ++;
		queue<int> q;
		REP(i, n)if(uf.root(i) == i && deg[i] == 0) q.push(i);
		while(!q.empty()){
			int u = q.front(); q.pop();
			res.pb(u);
			for(int v : ng[u])if(--deg[v] == 0)	q.push(v);
		}
		return res;
	}
};

int n, m;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	vector<vi> g(n);
	vi cycle;
	REP(i, n){
		int x;
		scanf("%d", &x);
		x--;
		if(x == i) cycle.pb(i);
		else g[x].pb(i);
	}
	SCC scc(g);
	ll ans = 1;
	REP(i, n){
		if(scc.uf.size(i) > 1 && scc.uf.root(i) == i){
			cycle.pb(i);
			ans = ans/__gcd<ll>(ans, (ll)scc.uf.size(i))*(ll)scc.uf.size(i);
		}
	}
	vector<ll> d(n, INF);
	queue<int> q;
	REP(i, cycle.size()){
		q.push(cycle[i]);
		d[cycle[i]] = 0;
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int v : scc.ng[u]){
			if(chmin(d[v], d[u] + 1)) q.push(v);
		}
	}
	ll md = 0;
	REP(i, n) if(scc.uf.root(i) == i) md = max(md, d[i]);
	ll ans2 = ans;
	while(ans2 < md) ans2 += ans;
	cout << ans2 << endl;
	return 0;
}