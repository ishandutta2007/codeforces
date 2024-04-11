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

template <typename T=int>
struct Zipper{
	vector<T> dec;
	unordered_map<T, int> enc;
	Zipper(){}
	void add(T t){dec.pb(t);}
	size_t size(){return dec.size();}
	void compile(){
		sort(ALL(dec)); UNIQUE(dec);
		REP(i, dec.size()) enc[dec[i]] = i;
	}
	T operator[](int i){return dec[i];}
	T operator()(T t){return enc[t];}
	int lb(T t){return lower_bound(ALL(dec), t) - dec.begin();}
	int ub(T t){return upper_bound(ALL(dec), t) - dec.begin();}
};

int n, m;
typedef unsigned long long int ull;
const ull B = 1000000007;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	vi d(n);
	
	REP(i, n){
		int x;
		scanf("%d", &x);
		d[i] = x;
	}
	reverse(ALL(d));
	scanf("%d", &m);
	vi q(m);
	REP(i, m) scanf("%d", &q[i]), q[i] = n - q[i];
	sort(ALL(q));
	int p = 0;

	vi ans(n);
	vi opened(1, -1);
	REP(i, n){
		if(p<m && q[p] == i){
			p ++;
			ans[i] = d[i];
			opened.push_back(d[i]);
		}else if(opened.back() == d[i]){
			ans[i] = -d[i];
			opened.pop_back();
		}else{
			ans[i] = d[i];
			opened.push_back(d[i]);
		}
	}
	if(opened.size() > 1){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	reverse(ALL(ans));
	REP(i, n) cout << -ans[i] << " ";
	cout << endl;
	return 0;
}