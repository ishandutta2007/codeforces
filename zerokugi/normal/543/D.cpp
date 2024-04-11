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
#include <unordered_map>
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

unordered_map<int, int> memo[200001];
int n, m;
vector<vi> g;

int dfs(int u, int p=-1){
	if(p != -1){
		auto it = memo[u].find(p);
		if(it != memo[u].end()) return it->second;
	}
	ll sum = 1;
	vector<ll> v1(g[u].size()+1, 1);
	int i = 1;
	for(int v : g[u])if(v!=p){
		v1[i] = dfs(v, u);
		sum *= v1[i];
		if(sum >= MOD) sum %= MOD;
		i ++;
	}
	if(p != -1){
		return memo[u][p] = sum + 1;
	}else{
		vector<ll> v2(g[u].size()+1, 1);
		RREP(i, g[u].size()) v2[i] = (v2[i+1]*v1[i+1]) % MOD;
		REP(i, g[u].size()) v1[i+1] = (v1[i]*v1[i+1]) % MOD;
		REP(i, g[u].size()){
			memo[u][g[u][i]] = (v1[i] * v2[i+1] + 1) % MOD;
		}
		return sum;
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	g.resize(n);
	REPS(i, n-1){
		int x;
		scanf("%d", &x); x--;
		g[i].pb(x);
		g[x].pb(i);
	}
	vi perm(n);
	iota(ALL(perm), 0);
	sort(RALL(perm), [&](int i, int j){
		return g[i].size() < g[j].size();
	});
	vi ans(n);
	REP(i, n) ans[perm[i]] = dfs(perm[i]);
	REP(i, n) printf("%d%c", ans[i], " \n"[i+1 == n]);
	return 0;
}