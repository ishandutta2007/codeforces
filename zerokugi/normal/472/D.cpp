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
class LCADist{
	int n;
	vector< vector<int> > parentI;
	vector< vector<ll > > parentL;
	vector<int> depth;
	ll ans;
	int maxdepth;
	
	void initdfs(vector< vector<pii> > &g, int r, int p, int d){
		depth[r] = d;
		REP(i, g[r].size()){
			if(g[r][i].first != p){
				parentI[0][g[r][i].first] = r;
				parentL[0][g[r][i].first] = g[r][i].second;
				initdfs(g, g[r][i].first, r, d+1);
			}
		}
	}
public:
	LCADist(vector< vector<pii> > &g, int root) {
		n=g.size();
		maxdepth = 0;
		while(n>>maxdepth) maxdepth ++;
		
		parentI = vector< vector<int> >(maxdepth+1, vector<int>(n));
		parentL = vector< vector<ll > >(maxdepth+1, vector<ll>(n));
		depth = vector<int>(n);
		
		parentI[0][0] = -1;
		initdfs(g, root, -1, 0);
		REP(k, maxdepth){
			REP(i, n){
				if(parentI[k][i] < 0) parentI[k+1][i] = -1;
				else{
					parentI[k+1][i] = parentI[k][parentI[k][i]];
					parentL[k+1][i] = parentL[k][parentI[k][i]] + parentL[k][i];
				}
			}
		}
	}
	
	ll lca(int u, int v){
		if(depth[u] > depth[v]) swap(u, v);
		ll ans = 0;
		if(u==v) return ans;
		REP(k, maxdepth+1){
			if((depth[v]-depth[u])>>k&1){
				ans += parentL[k][v];
				v = parentI[k][v];
			}
		}
		if(u==v) return ans;
		RREP(k, maxdepth+1){
			if(parentI[k][u] != parentI[k][v]){
				ans += parentL[k][u] + parentL[k][v];
				u = parentI[k][u];
				v = parentI[k][v];
			}
		}
		return ans + parentL[0][u] + parentL[0][v];
	}
};

main(){
	scanf("%d", &n);
	vector<vi> d(n, vi(n));
	vector<pair<int, pii> > e;
	REP(i, n)REP(j, n){
		int x;
		scanf("%d", &x);
		d[i][j] = x;
		if(j < i || (i == j && x != 0)){
			if(x == 0){
				puts("NO");
				return 0;
			}
			e.emplace_back(x, pii(j, i));
		}
	}
	sort(ALL(e));
	UnionFind uf(n);
	vector<vector<pii>> g(n);
	REP(i, e.size()){
		int u = e[i].second.first;
		int v = e[i].second.second;
		int c = e[i].first;
		if(uf.unionSet(u, v)){
			g[u].emplace_back(v, c);
			g[v].emplace_back(u, c);
		}
	}
	LCADist lca(g, 0);
	REP(i, n)REP(j, n){
		if(lca.lca(i, j) != (ll)d[i][j]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}