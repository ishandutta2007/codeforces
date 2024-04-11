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

int n, a, b;

typedef vector< vector<pii> > Graph;
Graph g;
vector<int> s;
vector<int> ans;

bool dfs(int r, int p);

bool skip(int r, int p){
	FOR(e, g[r]){
		if(e->first == p) continue;
		return dfs(e->first, r);
	}
	return true;
}

bool dfs(int r, int p){
	if(g[r].size() == 2 && g[r][0].first == r) swap(g[r][0], g[r][1]);
	FOR(e, g[r]){
		if(e->first == p) continue;
		if(e->first == r){
			ans[r] = e->second;
			return true;
		}else{
			bool ret = skip(e->first, r);
			if(ret){
				ans[r] = ans[e->first] = e->second;
				return true;
			}
		}
	}
	return false;
}
map<int, int> in;

main(){
	scanf("%d %d %d", &n, &a, &b);
	g = Graph(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		s.push_back(x);
		in[x] = i;
	}
	sort(ALL(s));
	REP(i, n){
		auto it = lower_bound(ALL(s), a-s[i]);
		if(it == s.end() || *it != a-s[i] ) continue;
		g[i].emplace_back(it - s.begin(), 0);
	}
	REP(i, n){
		auto it = lower_bound(ALL(s), b-s[i]);
		if(it == s.end() || *it != b-s[i]) continue;
		g[i].emplace_back(it - s.begin(), 1);
	}
	ans = vector<int>(n, -1);
	REP(i, n){
		if(ans[i] != -1 || g[i].size() == 2) continue;
		if(g[i].size() == 0 || !dfs(i, -1)){
			puts("NO");
			return 0;
		}
	}
	REP(i, n){
		if(g[i].size() != 2 || (g[i][0].first != i && g[i][1].first != i)) continue;
		if(!dfs(i, -1)){
			puts("NO");
			return 0;
		}
	}
	REP(i, n){
		if(ans[i] != -1) continue;
		if(!dfs(i, -1)){
			puts("NO");
			return 0;
		}
	}
	vi aa(n);
	REP(i, n){
		if(ans[i] == -1){
			puts("NO");
			return 0;
		}
		aa[in[s[i]]] = ans[i];
	}
	puts("YES");
	REP(i, n){
		printf("%d ", aa[i]);
	}
	return 0;
}