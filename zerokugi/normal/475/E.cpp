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

struct UnionFind {
  vector<int> data;
  UnionFind(int size=0) : data(size, -1) { }
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
UnionFind uf;

vector<vi> g;
int size[2001][2001];
int memo[2001][2001];
int rec(int r, int p){
	if(p != -1 && memo[r][p] != 0) return memo[r][p];
	int rnum = uf.size(r);
	if(p == -1){
		vi childs;
		int res = rnum*rnum;
		FOR(v, g[r])if(*v != p){
			res += rec(*v, r);
			res += size[*v][r]*rnum;
			childs.push_back(size[*v][r]);
		}
		vi dp(2001);
		dp[0] = 1;
		REP(i, childs.size()){
			RREP(j, 2001-childs[i]){
				dp[j+childs[i]] |= dp[j];
			}
		}
		int mm = 0;
		REP(i, n-rnum){
			if(dp[i]) mm = max(mm, i*(n-rnum-i));
		}
		return res + mm;
	}else{
		memo[r][p] = rnum*rnum;
		size[r][p] = rnum;
		FOR(v, g[r])if(*v != p){
			memo[r][p] += rec(*v, r);
			memo[r][p] += rnum*size[*v][r];
			size[r][p] += size[*v][r];
		}
		return memo[r][p];
	}
}
int BCCdfs(int r, int p, vector<vi> &g, vi &steps, vi &visited, UnionFind &uf, int step){
	if(visited[r] >= 1) return steps[r];
	steps[r] = step;
	visited[r] ++;
	int minstep = INF;
	FOR(v, g[r])if(*v!=p){
		int ret = BCCdfs(*v, r, g, steps, visited, uf, step+1);
		if(ret <= step) uf.unionSet(r, *v);
		chmin(minstep, ret);
	}
	return minstep;
}

UnionFind BCC(vector<vi> &g){
	vi steps(g.size());
	vi visited(g.size());
	uf = UnionFind(g.size());
	REP(i, g.size()) if(!visited[i]) BCCdfs(i, -1, g, steps, visited, uf, 0);
	return uf;
}

main(){
	scanf("%d%d", &n, &m);
	g = vector<vi>(n);
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v);u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	UnionFind uf = BCC(g);
	vector<vi> g2(n);
	REP(i, n){
		REP(j, g[i].size()){
			if(uf.root(i) != uf.root(g[i][j])){
				g2[uf.root(i)].push_back(uf.root(g[i][j]));
				g2[uf.root(g[i][j])].push_back(uf.root(i));
			}
		}
	}
	REP(i, n){
		sort(ALL(g2[i]));
		UNIQUE(g2[i]);
	}
	g = g2;
	int ans = 0;
	REP(i, n) if(uf.root(i) == i){
		ans = max(ans, rec(i, -1));
	}
	cout << ans << endl;
	return 0;
}