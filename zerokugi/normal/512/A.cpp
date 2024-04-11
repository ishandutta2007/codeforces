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
int g[30][30];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<string> s(n);
	vi same(n, 1);
	REP(i, n) cin >> s[i];
	REP(i, 100){
		REP(j, n-1){
			if(same[j] && s[j+1].size() == i && i<s[j].size()){
				cout << "Impossible" << endl;
				return 0;
			}
			if(same[j] && i<s[j].size() && i<s[j+1].size()){
				if(s[j][i] != s[j+1][i]){
					same[j] = 0;
					g[s[j][i]-'a'][s[j+1][i]-'a'] = 1;
				}
			}
		}
	}
	REP(k, 30)REP(i, 30)REP(j, 30) g[i][j] |=  g[i][k] & g[k][j];
	REP(i, 30)if(g[i][i]){
		cout << "Impossible" << endl;
		return 0;
	}
	vi used(26);
	REP(i, 26){
		REP(j, 26)if(!used[j]){
			if([&](){
				REP(k, 26) if(g[k][j]) return 0;
				return 1;
			}()){
				cout << (char)('a'+j);
				REP(k, 26) g[j][k] = 0;
				used[j] = 1;
			}
		}
	}
	cout << endl;
	return 0;
}