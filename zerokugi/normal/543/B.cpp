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


int n, m;
int d[3001][3001];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	REP(i, n)REP(j, n) d[i][j] = INF;
	vector<vi> g(n);
	REP(i, m){
		int u, v;
		cin >> u >> v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	REP(s, n){
		queue<int> q;
		q.push(s);
		d[s][s] = 0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v : g[u]) if(d[s][v] == INF){
				d[s][v] = d[s][u] + 1;
				q.push(v);
			}
		}
	}
	int s1, s2, l1, t1, t2, l2;
	cin >> s1 >> t1 >> l1; s1--; t1--;
	cin >> s2 >> t2 >> l2; s2--; t2--;
	if(d[s1][t1] > l1 || d[s2][t2] > l2){
		puts("-1");
		return 0;
	}
	int ans = d[s1][t1] + d[s2][t2];
	REP(i, n)REP(j, i){
		int d1 = min(d[s1][i] + d[i][j] + d[j][t1], d[t1][i] + d[i][j] + d[j][s1]);
		int d2 = min(d[s2][i] + d[i][j] + d[j][t2], d[t2][i] + d[i][j] + d[j][s2]);
		if(d1 <= l1 && d2 <= l2){
			ans = min(ans, d1 + d2 - d[i][j]);
		}
	}
	cout << m - ans << endl;
	return 0;
}