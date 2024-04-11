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

char s[600][600];

int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(s, 'X', sizeof(s));
	cin >> n >> m;
	REPS(i, n)REPS(j, m) cin >> s[i][j];
	int sx, sy, gx, gy;
	cin >> sy >> sx >> gy >> gx;
	queue<pii> q;
	q.emplace(sx, sy);
	
	int c = 0;
	REP(i, 4){
		int dx = gx+d[i][0];
		int dy = gy+d[i][1];
		c += (s[dy][dx] == '.' || (dy == sy && dx == sx));
	}
	
	if(sx == gx && sy == gy){
		puts(c >= 1 ? "YES" : "NO");
		return 0;
	}
	
	if(s[gy][gx] == '.' && c <= 1){
		puts("NO");
		return 0;
	}
	while(!q.empty()){
		int x, y; tie(x, y) = q.front(); q.pop();
//		cout << x << ", " << y << endl;
		if(y == gy && x == gx){
			puts("YES");
			return 0;
		}
		REP(i, 4){
			int dx = x+d[i][0];
			int dy = y+d[i][1];
			if(s[dy][dx] == '.' || (dy == gy && dx == gx)){
				s[dy][dx] = 'X';
				q.emplace(dx, dy);
			}
		}
	}
	puts("NO");
	return 0;
}