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


const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

bool dfs(vector<vi> &g, vector<int> &color, int v, int c){
	color[v] = c;
	FOR(it, g[v]){
		if(color[*it] == c) return false;
		if(!color[*it] && !dfs(g, color, *it, -c)) return false;
	}
	return true;
}

bool isBipartite(vector<vi> &g){
	int n = g.size();
	vector<int> color(n);
	REP(i, n) if(!color[i] && !dfs(g, color, i, 1)) return false;
	return true;
}

int n, m;
int g[1000][1000];
main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	n = 1000;
//	REP(k, n)REP(i, n)REP(j, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
//	return 0;
	
	
	scanf("%d%d", &n, &m);
	vector<vi> lg(n);
	REP(i, n)REP(j, n) g[i][j] = (i == j) ? 0 : INF;
	UnionFind uf(n);
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u][v] = 1;
		g[v][u] = 1;
		lg[u].pb(v);
		lg[v].pb(u);
		uf.unite(u, v);
	}
	if(!isBipartite(lg)){
		puts("-1");
		return 0;
	}
	REP(k, n)REP(i, n)REP(j, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	vi d(n);
	REP(i, n)REP(j, n)
		if(g[i][j] != INF) chmax(d[uf.root(i)], g[i][j]);
	cout << accumulate(ALL(d), 0) << endl;
	return 0;
}