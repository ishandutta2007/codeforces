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


int h, w;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

ll dp[4][4][2004][2004];
char s[2004][2004];

inline bool inside(int y, int x){
	return y>=0 && x>=0 && y<=h+1 && x<=w+1;
}
inline bool isborder(int y, int x){
	return y==0 || x==0 || y==h+1 || x==w+1;
}
inline bool isborder2(int y, int x){
	return y==1 || x==1 || y==h || x==w;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &h, &w);
	REPS(i, h){
		scanf("%s", s[i]+1);
	}
	REP(i, w-2) dp[1][1][0][i+2] = 1;
	REP(i, w-2) dp[1][3][h+1][i+2] = 1;
	REP(i, h-2) dp[1][0][i+2][0] = 1;
	REP(i, h-2) dp[1][2][i+2][w+1] = 1;
	REP(turn, 3){
		if(turn)REP(i, h+2)REP(j, w+2)if(s[i][j] != '#')REP(k, 4)REP(q, 2){
			int dy = i+dir[k][1]+dir[(k+1+2*q)%4][1];
			int dx = j+dir[k][0]+dir[(k+1+2*q)%4][0];
			if(inside(dy, dx) && !isborder(dy, dx) && !isborder2(dy, dx) && s[i+dir[k][1]][j+dir[k][0]]!='#'){
				if(!isborder(i, j) || !isborder(dy, dx)){
					dp[turn+1][k][i][j] += dp[turn-1][k][dy][dx];
				}
			}
//			if(dp[turn+1][k][i][j]) printf("dp[%d][%d][%d][%d] = %lld\n", turn+1, k, i, j, dp[turn+1][k][i][j]);
		}
		REP(i, h+2)REP(j, w+2)if(s[i][j] != '#')REP(k, 2){
			if(inside(i+dir[k][1], j+dir[k][0])) dp[turn+1][k][i][j] += dp[turn+1][k][i+dir[k][1]][j+dir[k][0]];
			if(inside(i+2*dir[k][1], j+2*dir[k][0]) && !isborder2(i+2*dir[k][1], j+2*dir[k][0]) && s[i+dir[k][1]][j+dir[k][0]]!='#'){
				if(!isborder(i, j) || !isborder(i+2*dir[k][1], j+2*dir[k][0])){
					dp[turn+1][k][i][j] += dp[turn][(k+1)%4][i+2*dir[k][1]][j+2*dir[k][0]];
					dp[turn+1][k][i][j] += dp[turn][(k+3)%4][i+2*dir[k][1]][j+2*dir[k][0]];
				}
			}
//			if(dp[turn+1][k][i][j]) printf("dp[%d][%d][%d][%d] = %lld\n", turn+1, k, i, j, dp[turn+1][k][i][j]);
		}
		RREP(i, h+2)RREP(j, w+2)if(s[i][j] != '#')for(int k=2;k<4;k++){
			if(inside(i+dir[k][1], j+dir[k][0])) dp[turn+1][k][i][j] += dp[turn+1][k][i+dir[k][1]][j+dir[k][0]];
			if(inside(i+2*dir[k][1], j+2*dir[k][0]) && !isborder2(i+2*dir[k][1], j+2*dir[k][0]) && s[i+dir[k][1]][j+dir[k][0]]!='#'){
				if(!isborder(i, j) || !isborder(i+2*dir[k][1], j+2*dir[k][0])){
					dp[turn+1][k][i][j] += dp[turn][(k+1)%4][i+2*dir[k][1]][j+2*dir[k][0]];
					dp[turn+1][k][i][j] += dp[turn][(k+3)%4][i+2*dir[k][1]][j+2*dir[k][0]];
				}
			}
//			if(dp[turn+1][k][i][j]) printf("dp[%d][%d][%d][%d] = %lld\n", turn+1, k, i, j, dp[turn+1][k][i][j]);
		}
	}
	ll ans = 0;
	REPS(k, 3){
		REP(i, w-2) ans += dp[k][3][0][i+2];
		REP(i, w-2) ans += dp[k][1][h+1][i+2];
		REP(i, h-2) ans += dp[k][2][i+2][0];
		REP(i, h-2) ans += dp[k][0][i+2][w+1];
	}
	cout << ans/2 << endl;
	return 0;
}