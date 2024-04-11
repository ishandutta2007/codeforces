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

typedef vector< vector<int> > Graph;
bool dfs(Graph &g, vector<int> &color, int u, int c, vi &trace){
	color[u] = c;
	trace.pb(u);
	for(int v : g[u]){
		if(color[v] == c) return false;
		if(!color[v] && !dfs(g, color, v, -c, trace)) return false;
	}
	return true;
}

int n, m;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	UnionFind ufr(n), ufb(n);
	vector<pii> er, eb;
	char pr = 'B';
	REP(i, m){
		int u, v;
		char c;
		scanf("%d%d %c", &u, &v, &c); u--; v--;
		if(pr != c){
			swap(er, eb);
			swap(ufr, ufb);
		}
		pr = c;
		er.eb(u, v);
		ufb.unite(u, v);
	}
	vi ans(n+1);
	REP(_, 2){
		vector<vi> g(n);
		for(auto e: er){
			int u, v; tie(u, v) = e;
			u = ufr.root(u);
			v = ufr.root(v);
			g[u].pb(v);
			g[v].pb(u);
		}
		int f = 1;
		vector<int> color(n);
		int sum = 0;
		vi v;
		vector<vi> inv(n);
		REP(i, n) inv[ufr.root(i)].pb(i);
		REP(i, n) if(ufr.root(i) == i && !color[i]){
			vi t;
			if(!dfs(g, color, i, 1, t)) f = 0;
			if(!f) break;
			vector<vi> tmp(2);
			for(int u: t) for(int v : inv[u]) tmp[color[u] == 1].pb(v);
			if(tmp[0].size() > tmp[1].size()) swap(tmp[0], tmp[1]);
			v.insert(v.end(), ALL(tmp[0]));
		}
		if(f) if(ans.size() > v.size()) swap(ans, v);
		swap(er, eb);
		swap(ufr, ufb);
	}
	if(ans.size() == n + 1) cout << -1 << endl;
	else{
		cout << ans.size() << endl;
		for(int x : ans) cout << x + 1 << " "; cout << endl;
	}
	return 0;
}