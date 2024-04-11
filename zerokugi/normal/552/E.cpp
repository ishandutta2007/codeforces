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

ll parse(int &p, int d);

string s;

ll num(int &p){
    ll res = 0;
    if(p>=s.size()) throw "error 0";
    if(s[p] == '('){
        res = parse(++p, 4);
        if(p>=s.size() || s[p++] != ')') throw "error 0";
    }else{
        if(!isdigit(s[p]) || s[p] == '0') throw "error 1";
        for(;isdigit(s[p]);++p) res = res*10+s[p]-'0';
    }
    return res;
}
 
ll parse(int &p, int d=1){
	if(p == s.size()) return 0;
    ll res = d?parse(p, d-1) : num(p);
    while(p<s.size()){
        if(d == 0 && s[p] == '*'){
            res *= num(++p);
        }else if(d == 1 && s[p] == '+'){
            res += parse(++p, 0);
        }else break;
    }
    return res;
}

int n, m;

main(){
	string ss;
	cin >> ss;
	vi d({-1, (int)ss.size()});
	REP(i, ss.size()){
		if(ss[i] == '*') d.pb(i);
	}
	sort(ALL(d));
	ll ans = 0;
	REP(i, d.size())REP(j, i){
		int l = d[j]+1, r = d[i];
		if(l < 0 || ss.size() < r) continue;
		s = ss.substr(0, l) + "(" + ss.substr(l, r - l) + ")" + ss.substr(r, ss.size());
		int p = 0;
		ans = max(ans, parse(p));
	}
	cout << ans << endl;
	return 0;
}