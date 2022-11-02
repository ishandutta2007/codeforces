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
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m;

class LCA{
	int n;
	vector< vector<int> > parent;
	vector<int> depth;
	ll ans;
	int maxdepth;
	
	void initdfs(vector< vector<int> > &g, int r, int p, int d){
		depth[r] = d;
		parent[0][r] = p;
		REP(i, g[r].size()) if(g[r][i] != p) initdfs(g, g[r][i], r, d+1);
	}
public:
	LCA(vector< vector<int> > &g, int root) {
		n=g.size();
		maxdepth = 0;
		while(n>>maxdepth) maxdepth ++;
		
		parent = vector< vector<int> >(maxdepth+1, vector<int>(n));
		depth = vector<int>(n);
		
		parent[0][0] = -1;
		initdfs(g, root, -1, 0);
		
		REP(k, maxdepth){
			REP(i, n){
				if(parent[k][i] < 0) parent[k+1][i] = -1;
				else parent[k+1][i] = parent[k][parent[k][i]];
			}
		}
	}
	
	ll lca(int u, int v){
		if(depth[u] > depth[v]) swap(u, v);
		ll ans = 0;
		REP(k, maxdepth+1){
			if((depth[v]-depth[u])>>k&1){
				v = parent[k][v];
			}
		}
		if(u==v) return u;
		RREP(k, maxdepth+1){
			if(parent[k][u] != parent[k][v]){
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct Query{
	int t, x,y;
	Query(int tt, int xx, int yy){
		t = tt;
		x = xx;
		y = yy;	
	}
};
main(){
	scanf("%d%d", &n, &m);
	vector<vi> g(n+1);
	vector<int> par(n, -1);
	vector<vector<pii>> ask(m);
	vector<Query> Q;
	REP(i, m){
		int t, x, y=0;
		scanf("%d%d", &t, &x); x--;
		if(t==1){
			scanf("%d", &y);y--;
			par[x] = y;
			g[x].push_back(y);
			g[y].push_back(x);
		}else if(t == 2){
			
		}else{
			scanf("%d", &y);y--;
			ask[y].push_back(pii(x, i));
		}
		Q.emplace_back(t, x, y);
	}
	REP(i, n){
		if(par[i] == -1){
			g[n].push_back(i);
			g[i].push_back(n);
		}
	}
	LCA lca(g, n);
	UnionFind uf(n);
	int k = 0;
	vector<pii> ans;
	REP(i, m){
		int t = Q[i].t;
		int x = Q[i].x;
		int y = Q[i].y;
		
		if(t==1) uf.unionSet(x, y);
		if(t==2){
			if(k < ask.size())FOR(to, ask[k]){
				ans.emplace_back(to->second, (uf.findSet(x, to->first) && lca.lca(x, to->first) == to->first));
			}k ++;
		}
	}
	sort(ALL(ans));
	FOR(it, ans) puts(it->second ? "YES" : "NO");
	return 0;
}