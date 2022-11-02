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
#include <iterator>
#include <functional>
#include <cassert>
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
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


int n, m;
double p[100001];
vector<pii> g[100001];
int cnts[100001];
int dfs(int r, int p){
	int res = 1;
	FOR(v, g[r])if(v->first!=p){
		int c = dfs(v->first, r);
		cnts[v->second] = c;
		res += c;
	}
	return res;
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n){
		vector<pair<pii, int>> e;
		REP(i, n-1){
			int u, v, w;
			cin >> u >> v >> w; u--; v--;
			g[u].eb(v, i);
			g[v].eb(u, i);
			e.eb(pii(u, v), w);
		}
		dfs(0, -1);
		double ans = .0;
		REP(i, n-1){
			double q = 0;
			int u = e[i].first.first;
			int v = e[i].first.second;
			int w = e[i].second;
			int c1 = cnts[i];
			int c2 = n - c1;
			p[i] = 1 - ((double)(c1)*(c1-1)*(c1-2) + (double)(c2)*(c2-1)*(c2-2))/n/(n-1)/(n-2);
			ans += p[i] * w;
		}
		cin >> m;
		REP(i, m){
			int j, w;
			cin >> j >> w; j--;
			ans -= p[j] * (e[j].second - w);
			e[j].second = w;
			printf("%.10f\n", ans*2);
		}
	}
	return 0;
}