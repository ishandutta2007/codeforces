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

vi factorlist(int n){
	vi res(n+1);
	if(n<2) return res;
	for(int i=2;i<=n;i++)if(!res[i]){
		for(int j=i;j<=n;j+=i) if(!res[j]) res[j] = i;
	}
	return res;
}

int n, m;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vi fact = factorlist(510000);
	vi evod(510000);
	scanf("%d%d", &n, &m);
	vector<vi> divs(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		vi v;
		while(x != 1){
			v.pb(fact[x]);
			x /= fact[x];
		}
		UNIQUE(v);
		REP(b, 1<<v.size())if(b){
			int p = 1, c = 0;
			REP(j, v.size())if((b>>j)&1){
				p*=v[j];
				c ^= 1;
			}
			evod[p] = c;
			divs[i].pb(p);
		}
	}
	vi cnt(510000), inserted(n);
	ll ans = 0, elements = 0;;
	REP(i, m){
		int x;
		scanf("%d", &x); x--;
		if(!inserted[x]){
			for(int y : divs[x]){
				if(evod[y]) ans += cnt[y];
				else ans -= cnt[y];
				cnt[y] ++;
			}
			elements ++;
		}else{
			for(int y : divs[x]){
				cnt[y] --;
				if(evod[y]) ans -= cnt[y];
				else ans += cnt[y];
			}
			elements --;
		}
		inserted[x] ^= 1;
		printf("%I64d\n", elements*(elements-1)/2 - ans);
	}
	return 0;
}