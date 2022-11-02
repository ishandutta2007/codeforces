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
int parity[100001];
vector<int> g[100001];
vi ans;

void dfs(int r, int p){
	parity[r] ^= 1;
	ans.push_back(r);
	FOR(v, g[r]){
		if(*v == p) continue;
		dfs(*v, r);
		parity[r] ^= 1;
		ans.push_back(r);
		if(parity[*v]){
			ans.push_back(*v);
			parity[*v] ^= 1;
			ans.push_back(r);
			parity[r] ^= 1;
		}
	}
}

main(){
	scanf("%d%d", &n, &m);
	UnionFind uf(n);
	int ufc = 1;
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v); u--;v--;
		if(uf.unionSet(u, v)) {
			g[u].push_back(v);
			g[v].push_back(u);
			ufc ++;
		}
	}
	REP(i, n) scanf("%d", &parity[i]);
	int q = -1;
	REP(i, n){
		if(parity[i]){
			if(q == -1){
				q = uf.root(i);
			}else if(q != uf.root(i)){
				puts("-1");
				return 0;
			}
		}
	}
	if(q == -1){
		puts("0");
		return 0;
	}
	dfs(q, -1);
	if(parity[q]) ans.resize(ans.size()-1);
	printf("%d\n", (int)ans.size());
	REP(i, ans.size()) printf("%d%s", ans[i]+1, i+1 == ans.size() ? "\n" : " ");
	return 0;
}