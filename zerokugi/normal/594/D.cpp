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

vi eratosthenes_sieve(int n){
	vi res(n+1);
	if(n<2) return res;
	res[2]=1;
	for(int i=3;i<=n;i+=2){
		if(i*i<=n && !res[i]) for(int j=i+i+i;j<=n;j+=i+i) res[j]=1;
		res[i]=!res[i];
	}
	return res;
}
vi prime_list(const vi& isprime){
	vi res;if(isprime.size()<=2)return res;
	res.push_back(2);
	for(unsigned int i=3;i<isprime.size();i+=2)
		if(isprime[i])res.push_back(i);
	return res;
}
vi prime_list(int n){
	return prime_list(eratosthenes_sieve(n));
}

struct handler{
	typedef ll val_t;
	handler(){}
	val_t def_val(){ return 1; }
	static val_t update(const val_t &l, const val_t &r){
		return l * r % MOD;
	}
	static val_t merge(const val_t &l, const val_t &r){
		return l * r % MOD;
	}
};

template<typename Handler>
struct SegTree{
	typedef typename Handler::val_t val_t;
	vector<val_t> val;
	Handler hdl;
	int n;
	
	SegTree(int size):hdl(){
		n=1;
		while(n<size) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
	}
	SegTree(const vector<val_t> &in):hdl(){
		n=1;
		while(n<in.size()) n<<=1;
		val=vector<val_t>(2*n, hdl.def_val());
		for(int i=n-1 + in.size()-1;i>=0;i--){
			if(n-1 <= i) val[i] = in[i - (n-1)];
			else val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
		}
	}
	void update(int i, val_t a){
		i += n-1;
		val[i] = hdl.update(val[i], a);
		while(i > 0){
			i = (i-1)/2;
			val[i] = hdl.merge(val[i*2+1],val[i*2+2]);
		}
	}
	val_t query(int a,int b,int k,int l,int r){
		if(r<=a||b<=l) return hdl.def_val();
		if(a<=l&&r<=b) return val[k];
		return hdl.merge(query(a, b, k*2+1, l, (l+r)/2),
					   query(a, b, k*2+2, (l+r)/2, r)
					  );
	}
	val_t query(int a, int b){return query(a, b, 0, 0, n);}
	val_t operator[](size_t i){return query(i, i+1);}
	friend ostream& operator<<(ostream &os, SegTree<Handler> &t){
		REP(i, t.n) os << (i ? ", " : "[") << t.query(i, i+1);
		return os << "]";
	}
};

int n, m;

struct Query{
	int l, r, i;
	Query(int l, int r, int i):l(l), r(r), i(i){}
};


ll modPow(long long x, long long y){
    long long r = 1, a = x % MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> inv(1000001);
	inv[1]=1;
	for(int i=2;i<=1000000;i++) inv[i] = (MOD+((long long)-inv[MOD%i]*(MOD/i))%MOD)%MOD;

	vi pl = prime_list(1000);
	
	scanf("%d", &n);
	vi d(n);
	REP(i, n){
		int x;
		scanf("%d", &d[i]);
	}
	scanf("%d", &m);
	vector<Query> Q;
	REP(i, m){
		int l, r;
		scanf("%d%d", &l, &r); l--;
		Q.eb(l, r, i);
	}
	sort(ALL(Q), [&](const Query & a, const Query & b){
		return a.r < b.r;
	});
	
	SegTree<handler> seg(n);
	
	vi prv(1000001, -1);
	
	int j = 0;
	
	vi ans(m);
	
	REP(i, n+1){
		while(j < m && Q[j].r == i){
			ans[Q[j].i] = seg.query(Q[j].l, Q[j].r);
			j ++;
		}
		
		if(i == n) break;
		vector<pii> pls;
		for(int p : pl){
			if(p > d[i]) break;
			if(d[i] % p == 0){
				int c = 0;
				while(d[i] % p == 0){
					d[i] /= p;
					c ++;
				}
				pls.eb(p, c);
			}
		}
		if(d[i] > 1) pls.eb(d[i], 1);
		for(pii it : pls){
			int p, c; tie(p, c) = it;
			if(prv[p] != -1) seg.update(prv[p], (ll)inv[p-1] * p % MOD);
			seg.update(i, (p-1) * modPow(p, c-1) % MOD);
			prv[p] = i;
		}
	}
	REP(i, m) printf("%d\n", ans[i]);
	return 0;
}