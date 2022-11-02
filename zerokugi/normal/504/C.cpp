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
vi d;
vector<ll> solve(int l, int r){
	if(l+1==r)   return vector<ll>({0, 0, 1, 0});
	if(d[l] == d[r-1]){
		if(l+2==r) return vector<ll>({1, 1, 1, 0});
		vector<ll> res = solve(l+1, r-1);
		return vector<ll>({res[0]+res[2], res[1]+res[2], res[2], res[0]+res[1]+res[2]+res[3]});
	}
	
	vi c(n+1);
	vector<ll> res(4);
	for(int i=l;i<r;i++) c[d[i]] ++;
	res[1] = [&](){
		vi a(n+1);
		for(int i=l;i<(l+r)/2;i++){
			if((++a[d[i]])*2>c[d[i]]){
				return i-l;
			}
		}
		if((r-l)&1 && (c[d[(l+r)/2]]&1)==0) return (r-l)/2;
		for(int i=(l+r)/2-l;l+i<r;i++){
			if(d[l+i] != d[r-1-i]){
				return i;
			}
		}
	}();
	reverse(d.begin()+l, d.begin()+r);
	res[0] = [&](){
		vi a(n+1);
		for(int i=l;i<(l+r)/2;i++){
			if((++a[d[i]])*2>c[d[i]]){
				return i-l;
			}
		}
		if((r-l)&1 && (c[d[(l+r)/2]]&1)==0) return (r-l)/2;
		for(int i=(l+r)/2-l;l+i<r;i++){
			if(d[l+i] != d[r-1-i]){
				return i;
			}
		}
	}();
	res[2] = 1;
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	d = vi(n);
	map<int, int> dist;
	REP(i, n){
		int x;
		scanf("%d", &x);
		d[i] = x;
		dist[x] ++;
	}
	int odd = 0;
	FOR(it, dist){
		odd += it->second & 1;
	}
	if(odd > 1) cout << 0 << endl;
	else if([&](){
		for(int l=0,r=n-1;l<r;l++,r--)if(d[l]!=d[r]) return 0;
		return 1;
	}()) cout << (ll)n*(n+1)/2 << endl;
	else{
		auto ans = solve(0, n);
		cout << accumulate(ALL(ans), 0ll) << endl;
	}
	return 0;
}