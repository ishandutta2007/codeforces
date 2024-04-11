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

string db="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
vector<vi> g, rg;

void setpath(int u, string &res){
//	cout << "setpath " << u << "(" << db[u/m] << db[u%m] << ")" << endl;
	res.pb(db[u%m]);
	if(!g[u].empty()){
		int v = g[u].back();
		g[u].pop_back();
		setpath(v, res);
	}
}

void visit(vector<vi>& g, int a, vector<int>& path) {
  while (!g[a].empty()){
    int b = g[a].back();
    g[a].pop_back();
    visit(g, b, path);
  }
  path.push_back(a);
}
bool eulerPath(vector<vi> g, int s, vector<int> &path) {
  int n = g.size(), m = 0;
  vector<int> deg(n);
  REP(u, n){
    m += g[u].size();
    FOR(e, g[u]) --deg[*e]; //  in-deg
    deg[u] += g[u].size();      // out-deg
  }
  int k = n - count(ALL(deg), 0);
  if (k == 0 || (k == 2 && deg[s] == 1)) {
    path.clear();
    visit(g, s, path);
    reverse(ALL(path));
    return path.size() == m + 1;
  }
  return false;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	sort(ALL(db));
	m = db.size();
	g.resize(m*m);
	rg.resize(m*m);
	REP(i, n){
		string s;
		cin >> s;
		int a = lower_bound(ALL(db), s[0]) - db.begin();
		int b = lower_bound(ALL(db), s[1]) - db.begin();
		int c = lower_bound(ALL(db), s[2]) - db.begin();
		int u = a*m+b;
		int v = b*m+c;
		g[u].pb(v);
		rg[v].pb(u);
	}
	int start = -1;
	int f = 0;
	REP(i, m*m){
		if(g[i].size() != rg[i].size()){
			if(g[i].size() + 1 == rg[i].size() && !f){
				f ++;
			}else if(g[i].size() == rg[i].size() + 1 && start == -1){
				start = i;
			}else{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if(start == -1){
		REP(i, m*m){
			if(g[i].size()){
				start = i;
				break;
			}
		}
	}
	vi res;
	if(!eulerPath(g, start, res)) cout << "NO" << endl;
	else{
		cout << "YES" << endl << db[start/m];
		REP(i, res.size()) cout << db[res[i]%m];
		cout << endl;
	}
	return 0;
}