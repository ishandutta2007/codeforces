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

int n,m,k,w;
char d[1001][11][11];
vector<int> g[1001];
int visited[1001];

void dfs(int r){
	visited[r] = 1;
	FOR(it, g[r]){
		if(visited[*it]) continue;
		printf("%d %d\n", *it, r);
		dfs(*it);
	}
}

main(){
	scanf("%d%d%d%d", &n, &m, &k, &w);
	vector<pipii> e;
	REP(i, k)REP(j, n){
		scanf("%s", d[i][j]);
	}
	REP(i, k)REP(j, i){
		int sum = 0;
		REP(y, n)REP(x, m) sum += d[i][y][x] != d[j][y][x];
		if(sum*w < n*m) e.push_back(pipii(sum*w, pii(i+1, j+1)));
	}
	REP(i, k) e.push_back(pipii(n*m, pii(0, i+1)));
	sort(ALL(e));
	
	int ans = 0;
	UnionFind uf(k+1);
	FOR(it, e){
		if(uf.unionSet(it->second.first, it->second.second)){
			ans += it->first;
			g[it->second.first].push_back(it->second.second);
			g[it->second.second].push_back(it->second.first);
		}
	}
	printf("%d\n", ans);
	dfs(0);
	return 0;
}