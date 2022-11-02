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

vector<ull> getbits(string &s_){
	REP(i, s_.size()) s_[i] -= '0';
	reverse(ALL(s_));
	vector<ull> res(32);
	s_.resize(s_.size()+6);
	vi s;
	REP(i, s_.size()/6) s.pb(s_[i*6]+10*s_[i*6+1]+100*s_[i*6+2]+1000*s_[i*6+3]+10000*s_[i*6+4]+100000*s_[i*6+5]);
	REP(i, 2000){
		if(s[0]&1){
			res[i/64] |= 1ll<<(i&63);
			-- s[0];
		}
		int f = 0;
		REP(j, s.size()){
			if(j && s[j]&1) s[j-1] += 500000;
			s[j]>>=1;
			f |= s[j];
		}
		if(!f) break;
	}
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<vector<ull>> maxbit(2000), unit(2000);
	REP(i, n){
		string s;
		cin >> s;
		vector<ull> x = getbits(s);
		vector<ull> u(32);
		int f = 1;
		RREP(j, 2000){
			if((x[j/64]>>(j&63))&1){
				if(maxbit[j].empty()){
					maxbit[j] = x;
					u[i/64] |= 1ll<<(i&63);
					unit[j] = u;
					f = 0;
					break;
				}else{
					REP(k, 32){
						x[k] ^= maxbit[j][k];
						u[k] ^= unit[j][k];
					}
				}
			}
		}
		if(f){
			int c = 0;
			FOR(it, u) c += __builtin_popcountll(*it);
			printf("%d", c);
			REP(j, 32)if(u[j]){
				REP(k, 64)if((u[j]>>k)&1)
					printf(" %d", j*64+k);
			}
			printf("\n");
		}else printf("%d\n", 0);
	}
	return 0;
}