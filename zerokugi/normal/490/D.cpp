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
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;


ll a, b;

main(){
	ll xa, ya, xb, yb;
	cin >> xa >> ya;
	a = xa*ya;
	cin >> xb >> yb;
	b = xb*yb;
	ll g = __gcd(a, b);
	a /= g;
	b /= g;
	vi pa(4), pb(4);
	for(int i=2;i<=3;i++)for(;a%i == 0;a/=i) pa[i] ++;
	for(int i=2;i<=3;i++)for(;b%i == 0;b/=i) pb[i] ++;
	if(a > 1 || b > 1){
		cout << "-1" << endl;
		return 0;
	}
	ll res = pa[3] + pb[3];
	pa[2] += pa[3];
	pb[2] += pb[3];
	ll t = min(pa[2], pb[2]);
	pa[2] -= t;
	pb[2] -= t;
	cout << res + pa[2] + pb[2] << endl;
	for(;xa%3==0 && pa[3];xa=xa/3*2)pa[3] --;
	for(;ya%3==0 && pa[3];ya=ya/3*2)pa[3] --;
	for(;xb%3==0 && pb[3];xb=xb/3*2)pb[3] --;
	for(;yb%3==0 && pb[3];yb=yb/3*2)pb[3] --;
	for(;xa%2==0 && pa[2];xa=xa/2)pa[2] --;
	for(;ya%2==0 && pa[2];ya=ya/2)pa[2] --;
	for(;xb%2==0 && pb[2];xb=xb/2)pb[2] --;
	for(;yb%2==0 && pb[2];yb=yb/2)pb[2] --;
	cout << xa << " " << ya << endl;
	cout << xb << " " << yb << endl;
	return 0;
}