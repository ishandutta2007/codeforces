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

bool bipartite_matching_dfs(
	int v, const vector< vector<int> > &conn,
	vector<bool> &used, vector<int> &match)
{
	used[v] = true;
	for(int i = 0; i < conn[v].size(); ++i){
		int u = conn[v][i], w = match[u];
		if(w < 0 || (!used[w] && bipartite_matching_dfs(w, conn, used, match))){
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}
//O(EV)
int bipartite_matching(const vector< vector<int> > &conn){
	int res = 0;
	vector<int> match(conn.size(), -1);
	vector<bool> used(conn.size(), false);
	for(int v = 0; v < conn.size(); ++v){
		if(match[v] < 0){
			fill(used.begin(), used.end(), false);
			if(bipartite_matching_dfs(v, conn, used, match)){ ++res; }
		}
	}
	return res;
}

main(){
	scanf("%d", &n);
	vi a(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	scanf("%d", &m);
	vi b(m);
	REP(i, m){
		int x;
		scanf("%d", &x);
		b[i] = x;
	}
	vector<vi> g(n+m);
	REP(i, n)REP(j, m){
		if(abs(a[i]-b[j]) <= 1){
			g[i].push_back(n+j);
			g[n+j].push_back(i);
		}
	}
	cout << bipartite_matching(g) << endl;
	return 0;
}