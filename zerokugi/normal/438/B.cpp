#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)

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
int d[100005];

main(){
	scanf("%d%d", &n, &m);
	REP(i, n){
		int x;
		scanf("%d", &x);
		d[i] = x;
	}
	vector<pipii> e;
	REP(i, m){
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		e.push_back(mp(min(d[x], d[y]), mp(x, y)));
	}
	sort(e.rbegin(), e.rend());
	
	UnionFind uf(n);
	double ans = 0;
	REP(i, m){
		if(!uf.findSet(e[i].second.first, e[i].second.second)){
			ll s1 = uf.size(e[i].second.first);
			s1 *= (ll)uf.size(e[i].second.second);
			ans +=  (double) e[i].first * s1 / ((double)n*(n-1));
			uf.unionSet(e[i].second.first, e[i].second.second);
		}
	}
	
	printf("%.9f\n", 2*ans);
	return 0;
}