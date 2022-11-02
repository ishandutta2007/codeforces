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
#include <unordered_set>
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
typedef long long RInteger;
struct Rational{
	RInteger p,q;
	Rational(RInteger pp=1,RInteger qq=1):p(pp),q(qq){
		if(q==0)p=1;else if(p==0)q=1;
		else{
			if(q<0)q=-q,p=-p;
			RInteger g=__gcd(abs(p),q);
			p/=g;q/=g;
		}
	};
};
Rational operator+(const Rational &a,const Rational &b){
	return Rational(a.p*b.q+b.p*a.q,a.q*b.q);
}
Rational operator-(const Rational &a){
	return Rational(-a.p,a.q);
}
Rational operator-(const Rational &a,const Rational &b){
	return Rational(a.p*b.q-b.p*a.q,a.q*b.q);
}
Rational operator*(const Rational &a,const Rational &b){
	return Rational(a.p*b.p,a.q*b.q);
}
Rational operator/(const Rational &a,const Rational &b){
	return Rational(a.p*b.q,a.q*b.p);
}
bool operator==(const Rational &a,const Rational &b){
	return (a.p==b.p)&&(a.q==b.q);
}
bool operator<(const Rational &a,const Rational &b){
	return a.p*b.q<b.p*a.q;
}
bool operator>(const Rational &a,const Rational &b){return b<a;}
bool operator<=(const Rational &a,const Rational &b){return (a<b)||(a==b);}
bool operator>=(const Rational &a,const Rational &b){return (a>b)||(a==b);}
bool operator!=(const Rational &a,const Rational &b){return !(b==a);}
ostream & operator<<(ostream &os, const Rational &r){
	return os << r.p << "/" << r.q;
}

int n, m, k;
vector<vi> g;
int deg[100001], ok[100001], adj[100001];

typedef pair<Rational, int> pRi;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	g.resize(n);
	REP(i, n) ok[i] = 1;
	REP(i, k){
		int u;
		scanf("%d", &u); u--;
		ok[u] = 0;
	}
	REP(i, m){
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u].pb(v); g[v].pb(u);
		deg[u] ++; deg[v] ++;
		adj[u] += ok[v];
		adj[v] += ok[u];
	}
	priority_queue<pRi, vector<pRi>, greater<pRi>> pq;
	
	REP(i, n)if(ok[i]){
		pq.emplace(Rational(adj[i], deg[i]), i);
//		cout << "emplace " << mp(Rational(adj[i], deg[i]), i) << endl;
	}
	Rational ans(0, 1);
	
	vi eraseq;
	unordered_set<int> ansv;
	REP(i, n) if(ok[i]) ansv.insert(i);
//	cout << ansv << endl;
	while(!pq.empty()){
		Rational cost;
		int i;
		tie(cost, i) = pq.top(); pq.pop();
		if(cost != Rational(adj[i], deg[i])) continue;
//		cout << cost << ": " << i << endl;
		if(cost > ans){
			for(int j : eraseq) ansv.erase(j);
			eraseq.clear();
//			cout << "new " << ansv << endl;
			ans = cost;
		}
		eraseq.pb(i);
		ok[i] = 0;
		for(int v : g[i])if(ok[v]){
			pq.emplace(Rational(-- adj[v], deg[v]), v);
		}
	}
//cerr << ans << endl;
	cout << ansv.size() << endl;
	for(int i : ansv) cout << i+1 << " "; cout << endl;
	return 0;
}