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


int k, n, m;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &k, &n, &m);
	vi type(n);
	vector<ll> v(k);
	REP(i, k){
		scanf("%lld", &v[i]);
	}
	vector<pair<double, int>> d;
	vector<vector<pair<ll, ll>>> add(k);
	vector<pii> assign(k, pii(0, -1));
	REP(i, n){
		int t, j, b;
		scanf("%d%d%d", &t, &j, &b); j--;
		if(t == 1 && b-v[j] > 0) chmax(assign[j], pii(b-v[j], i));
		if(t == 2) add[j].eb(b, i);
		if(t == 3) d.eb(b, i);
		type[i] = t;
	}
	REP(i, k){
		if(assign[i].second >= 0) add[i].eb(assign[i].first - v[i], assign[i].second);
	}
	priority_queue<pair<double, int>> pq;
	FOR(it, d){
		pq.push(*it);
	}
	REP(i, k){
		sort(RALL(add[i]));
		REP(j, add[i].size()){
			pq.emplace(1. + (double)add[i][j].first/v[i], add[i][j].second);
			v[i] += add[i][j].first;
		}
	}
	vi ans;
	REP(i, m){
		if(pq.empty()) break;
		int t = pq.top().second; pq.pop();
		ans.pb(t);
	}
	cout << ans.size() << endl;
	REP(i, ans.size()) if(type[ans[i]] == 1)cout << ans[i]+1 << " ";
	REP(i, ans.size()) if(type[ans[i]] == 2)cout << ans[i]+1 << " ";
	REP(i, ans.size()) if(type[ans[i]] == 3)cout << ans[i]+1 << " ";
	cout << endl;
	return 0;
}