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

int n;

ll getdigitsum(ll x){
	ll res = 0;
	while(x){
		res += x%10;
		x /= 10;
	}
	return res;
}

ll strtoi(string s){
	stringstream ss(s);
	ll res;
	ss >> res;
	return res;
}
ll tp[20];
ll tenpow(int t){
	if(t<0) return 0;
	return tp[t];
}
ll solve(ll s){
	ll l=0;
	vi dig;
	ll t=s;
	while(t){
		dig.push_back(t%10);
		t/=10;
		l++;
	}
	reverse(ALL(dig));
	ll res = 0;
	REP(i, l){
		res += (dig[i])*(s%tenpow(l-1-i)+1);
		REP(j, dig[i]) res += j*tenpow(l-i-1);
		
		if(i != l-1) res += (dig[i])*45ll*tenpow(l-i-2)*(l-i-1);
	}
	return res;
}

ll t;
main(){

	tp[0] = 1;
	REP(i, 18) tp[i+1] = tp[i]*10;

	cin >> t;
	
	ll l=0, r = 100000000000000000ll;
	while(l+1<r){
		ll med = (r+l)/2;
		if(t <= solve(med))r = med;
		else l = med;
	}
	for(ll i=r;;i++){
		ll tar=solve(i)-t;
		ll l=-1, rr=min(i, 100000ll);
		while(l+1<rr){
			ll med = (rr-l+1)/2+l;
			ll res = solve(med);
			if(tar == res){
				printf("%lld %lld\n", med+1, i);
				return 0;
			}
			if(tar < res) rr = med;
			else l = med;
		}
	}
	cout << r << endl;
	cout << solve(r) << endl;

//	s = '1' + string(5, '0');
	while(cin >> t) cout << solve(t) << endl;
//	REP(i, 101) printf("%3lld,", getdigitsum(i));
	return 0;
}