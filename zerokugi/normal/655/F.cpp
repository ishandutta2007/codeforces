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
template<int N, int MOD>
struct Comb{
	ll fact[N+1], inv[N+1];
	Comb(){
		fact[0] = inv[0] = inv[1] = 1;
		for(int i=2;i<=N;i++) inv[i] = (MOD+((ll)-inv[MOD%i]*(MOD/i))%MOD)%MOD;
		REPS(i, N){
			fact[i] = fact[i-1]*i%MOD;
			inv[i] = inv[i]*inv[i-1]%MOD;
		}
	}
	ll operator()(int n, int r){
		if(n < 0 || r < 0 || r > n) return 0;
		ll res = inv[r]*inv[n-r];
		if(res >= MOD) res%= MOD;
		res *= fact[n];
		if(res >= MOD) res%= MOD;
		return res;
	}
};
Comb<300000, MOD> C;


template<int N>
struct Divisor{
	vi fact;
	
	Divisor():fact(N+1){
		for(int i=2;i<=N;i++){
			if(fact[i] == 0)
				for(int j=i;j<=N;j+=i) fact[j] = i;
		}
	}
	
	vi get(int n){
		int prod = 1;
		vector<pii> v;
		while(n > 1){
			int p = fact[n];
			n /= p;
			int c = 1;
			while(n % p == 0){
				n /= p;
				c ++;
			}
			v.eb(p, c);
			prod *= c + 1;
		}
		vi res(prod, 1);
		REP(s, prod){
			int x = 1;
			REP(j, v.size()){
				if(s % (x * (v[j].second + 1))){
					res[s] = res[s - x] * v[j].first;
					break;
				}
				x *= (v[j].second + 1);
			}
		}
		return res;
	}
};
const int N = 1000000;
Divisor<N> divisor;

int n, k, m;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	vi coef(N+1);
	REPS(i, N){
		auto ret = divisor.get(i);
		ret.pop_back();
		for(const int x : ret) coef[i] -= coef[x];
		coef[i] += i;
	}
	map<int, int> cnt;
	ll ans = 0;
	REP(i, n+m){
		int x;
		cin >> x;
		auto ret = divisor.get(x);
		for(const int x : ret){
			ans += coef[x] * C(cnt[x]++, k-1);
			ans %= MOD;
		}
		if(n <= i) cout << ans << endl;
	}
	
	return 0;
}