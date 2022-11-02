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
	vector<int> W;
	UnionFind(int size) : data(size, -1), W(size, 0) {}
	bool unionSet(int x, int y) {
		int rx = root(x), ry = root(y);
		if (rx != ry) {
			if (data[ry] < data[rx]){
				swap(x, y);
				swap(rx, ry);
			}
			int rW = max(max(W[rx], W[ry]), (1+W[rx])/2 + (1+W[ry])/2 + 1);
			W[rx] = rW;
			data[rx] += data[ry]; data[ry] = rx;
		}
		return rx != ry;
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
	int query(int x){
		return W[root(x)];
	}
	int setW(int x, int w){
		W[root(x)] = w;
	}
};

pii dfs(vector<vi> &g, int r, int p){
	pii res(0, r);
	FOR(v, g[r]) if(*v != p){
		pii ret = dfs(g, *v, r);
		ret.first ++;
		chmax(res, ret);
	}
	return res;
}

int getR(vector<vi> &g, int r){
	pii res = dfs(g, r, -1);
	return dfs(g, res.second, -1).first;
}

int n, m, q;
main(){
	scanf("%d%d%d", &n, &m, &q);
	UnionFind uf(n);
	vector< vi > g(n);
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v);
		u --;v --;
		if(uf.unionSet(u, v)){
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	vector<int> visited(n);
	REP(i, n) if(!visited[uf.root(i)]){
		uf.setW(i, getR(g, i));
		visited[uf.root(i)] = 1;
	}
	REP(i, q){
		int t, u ,v;
		scanf("%d%d", &t, &u);
		if(t == 1){
			printf("%d\n", uf.query(u-1));
		}else{
			scanf("%d", &v);
			uf.unionSet(u-1, v-1);
		}
	}
	return 0;
}