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


const int BLOCK = 300;
int n, m, q;
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

int visited[200001];

void dfs(const vector<vi> &g, int u, int id, vi &to){
	if(visited[u] == id) return ;
	to.pb(u);
	visited[u] = id;
	FOR(v, g[u]) dfs(g, *v, id, to);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	vector<vector<pii>> e(m);
	REP(i, m){
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c); x--, y--;
		if(x>y) swap(x, y);
		e[c-1].eb(x, y);
	}
	vector<vi> to(n);
	vector<UnionFind> vuf;
	vector<vi> g(n);
	REP(i, m){
		if(e[i].size() > BLOCK){
			vuf.emplace_back(n);
			REP(j, e[i].size())vuf.back().unionSet(e[i][j].first, e[i][j].second);
		}else{
			vi t;
			REP(j, e[i].size()){
				t.pb(e[i][j].first);
				t.pb(e[i][j].second);
				g[e[i][j].first].push_back(e[i][j].second);
				g[e[i][j].second].push_back(e[i][j].first);
			}
			sort(ALL(t)); UNIQUE(t);
			FOR(u, t){
				if(visited[*u]!=i+1){
					vi conn;
					dfs(g, *u, i+1, conn);
					REP(i, conn.size())REP(j, i) to[min(conn[j], conn[i])].pb(max(conn[j], conn[i]));
				}
				g[*u].clear();
			}
		}
	}
	REP(i, n){
		sort(ALL(to[i]));
//		cout << to[i] << endl;
	}
	scanf("%d", &q);
	REP(i, q){
		int x, y;
		scanf("%d%d", &x, &y); x--, y--;
		if(x>y) swap(x, y);
		int ans = 0;
		FOR(uf, vuf) ans += uf->findSet(x, y);
		ans += upper_bound(ALL(to[x]), y) - lower_bound(ALL(to[x]), y);
		printf("%d\n", ans);
	}
	return 0;
}