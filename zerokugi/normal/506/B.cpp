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

int n, m;

void dfs1(int r, vector<vi> &g, vi &d, vi &vis){
	vis[r] = 1;
	FOR(v, g[r]) if(!vis[*v]){
		dfs1(*v, g, d, vis);
	}
	d.push_back(r);
}

void dfs2(int r, vector<vi> &g	, vi &vis, UnionFind &uf){
	vis[r] = 1;
	FOR(v, g[r]) if(!vis[*v]){
//		printf("union %d %d\n", r, *v);
		uf.unionSet(r, *v);
		dfs2(*v, g, vis, uf);
	}
}

void SCC(vector<vi> &g, vector<vi> &rg, UnionFind &uf){
	vi d;
	vi vis(n);
	int n = g.size();
	REP(i, n) if(!vis[i]) dfs1(i, g, d, vis);
	vis = vi(n);
	RREP(i, n) if(!vis[d[i]]) dfs2(d[i], rg, vis, uf);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	vector<vi> g(n), rg(n);
	UnionFind uf(n);
	int ans = 0;
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u].pb(v);
		rg[v].pb(u);
		ans += uf.unionSet(u, v);
	}
	UnionFind buf(n);
	SCC(g, rg, buf);
	vi d(n);
	REP(i, n){
		if(buf.root(i) == i && buf.size(i) > 1) d[uf.root(i)] = 1;
	}
	cout << ans + accumulate(ALL(d), 0) << endl;
	return 0;
}