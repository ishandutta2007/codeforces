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
	return Rational((a.p)*(b.p),(a.q)*(b.q));
}
Rational operator/(const Rational &a,const Rational &b){
	return Rational((a.p)*(b.q),(a.q)*(b.p));
}
bool operator==(const Rational &a,const Rational &b){
	return (a.p==b.p)&&(a.q==b.q);
}
bool cmp(const Rational &a,const Rational &b){
	ll g1=(a.p&&b.p) ? __gcd(abs(a.p), abs(b.p)) : 1;
	ll g2=__gcd(a.q, b.q);
	return (a.p/g1)*(b.q/g2)<(a.q/g2)*(b.p/g1);
}bool operator<(const Rational &a,const Rational &b){
	return (a.p)*(b.q)<(a.q)*(b.p);
}
bool operator>(const Rational &a,const Rational &b){return b<a;}
bool operator<=(const Rational &a,const Rational &b){return (a<b)||(a==b);}
bool operator>=(const Rational &a,const Rational &b){return (a>b)||(a==b);}
bool operator!=(const Rational &a,const Rational &b){return !(b==a);}

typedef pair<Rational, Rational> P;

int n, m;

int cw(const P &x, const P &y){
	return cmp(x.first*y.second, x.second*y.first);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	vector<P> d;
	REP(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		d.eb(Rational(1, x), Rational(1, y));
	}
	vector<P> g = d;
	sort(ALL(g), [](const P &p, const P &q){
		if(p.first == q.first) return p.second > q.second;
		return p.first < q.first;
	});
	UNIQUE(g);
	vector<P> st;
	REP(i, g.size()){
		if(!st.empty() && st.back().second <= g[i].second) continue;
		while(st.size()>0 && st.back().first == g[i].first) st.pop_back();
		while(st.size()>1 && cw(st.back()-st[st.size()-2], g[i]-st[st.size()-2])) st.pop_back();
		st.pb(g[i]);
	}
	
	set<P> p;
	REP(i, st.size()) p.insert(st[i]);
	vi ans;
	REP(i, n) if(p.count(d[i])) ans.pb(i+1);
	sort(ALL(ans));
	REP(i, ans.size()) cout << ans[i] << " \n"[i+1==ans.size()];
	return 0;
}