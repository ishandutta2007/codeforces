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


int n, m, k, p;
ll h[100001], a[100001];

int check(ll t){
	vector<ll> sum(n);
	priority_queue<pll> pq;
	REP(i, n){
		sum[i] = h[i] + m*a[i];
		ll need =  sum[i] - t;
		if(need <= 0) continue;
		ll deadline = (need - h[i] + a[i] - 1) / a[i];
		pq.emplace(deadline, i);
	}
	RREP(i, m){
		REP(j, k){
			if(pq.empty()) return 1;
			pll r = pq.top(); pq.pop();
			if(r.first > i) return 0;
			sum[r.second] -= p;
			ll need =  sum[r.second] - t;
			if(need <= 0) continue;
			ll deadline = (need - h[r.second] + a[r.second] - 1) / a[r.second];
			pq.emplace(deadline, r.second);
		}
	}
	return pq.empty();
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d%d", &n, &m, &k, &p);
	REP(i, n) scanf("%lld%lld", &h[i], &a[i]);
	ll l = 0, r = 1000000000000000ll;
	
	while(l+1<r){
		ll med = (l+r)/2;
		if(check(med)) r = med;
		else l = med;
	}
	printf("%lld\n", r);
	return 0;
}