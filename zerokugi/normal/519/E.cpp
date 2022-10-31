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
#include <unordered_map>
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

class LCA{
	int n;
	vector< vector<int> > parent;
	vector<int> depth;
	ll ans;
	int maxdepth;
	
public:
	LCA(vector< vector<int> > &g, int root) {
		n=g.size();
		maxdepth = 0;
		while(n>>maxdepth) maxdepth ++;
		
		parent = vector< vector<int> >(maxdepth+1, vector<int>(n));
		depth = vector<int>(n);
		
		parent[0][0] = -1;
		queue<pii> que;
		que.emplace(root, -1);
		while(!que.empty()){
			const int r = que.front().first;
			const int p = que.front().second;
			que.pop();
			depth[r] = p==-1 ? 0 : depth[p]+1;
			parent[0][r] = p;
			REP(i, g[r].size()) if(g[r][i] != p) que.emplace(g[r][i], r);
		}
		
		REP(k, maxdepth){
			REP(i, n){
				if(parent[k][i] < 0) parent[k+1][i] = -1;
				else parent[k+1][i] = parent[k][parent[k][i]];
			}
		}
	}
	
	ll lca(int u, int v){
		if(depth[u] > depth[v]) swap(u, v);
		ll ans = 0;
		REP(k, maxdepth+1){
			if((depth[v]-depth[u])>>k&1){
				v = parent[k][v];
			}
		}
		if(u==v) return u;
		RREP(k, maxdepth+1){
			if(parent[k][u] != parent[k][v]){
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	
	int getdepth(int u){
		return depth[u];
	}
	int up(int v, int i){
		REP(k, maxdepth+1){
			if((i>>k)&1){
				v = parent[k][v];
			}
		}
		return v;
	}
};

int n, m;
unordered_map<int, int> memo[100005];
vector<vi> g;
int count(int u, int p){
	auto it = memo[u].find(p);
	if(it != memo[u].end()) return it->second;
	int &res = memo[u][p] = 1;
	FOR(v, g[u])if(*v!=p) res += count(*v, u);
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	g.resize(n);
	REP(i, n-1){
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	LCA lca(g, 0);
	scanf("%d", &m);
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		if(u == v){
			printf("%d\n", n);
			continue;
		}
		int x = lca.lca(u, v);
		int d = lca.getdepth(u) + lca.getdepth(v) - 2*lca.getdepth(x);
		if(d&1){
			printf("0\n");
			continue;
		}
		int center, nu, nv;
		if(lca.getdepth(u) > lca.getdepth(v)){
			center = lca.up(u, d/2);
			nu = lca.up(u, d/2 - 1);
			nv = lca.up(u, d/2 + 1);
		}else if(lca.getdepth(u) < lca.getdepth(v)){
			center = lca.up(v, d/2);
			nu = lca.up(v, d/2 + 1);
			nv = lca.up(v, d/2 - 1);
		}else{
			center = x;
			nu = lca.up(u, d/2 - 1);
			nv = lca.up(v, d/2 - 1);
		}
		printf("%d\n", n-count(nu, center)-count(nv, center));
	}
	return 0;
}