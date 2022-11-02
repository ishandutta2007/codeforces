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


int n, m;
vector<string> s;

int solve2(vector<string> &s, int dy, int dx, int w, int h){
	int x = dx - w+1;
	int y = dy - h+1;
	while(s[dy+1][x]!=s[y][dx+1]){
		if(s[dy+1][x] == 'X'){
			for(int i=x;i<=dx;i++){
				if(s[dy+1][i] == '.') return INF;
				s[dy+1][i] = '.';
			}
			y ++;dy ++;
		}else if(s[dy][dx+1] == 'X'){
			for(int i=y;i<=dy;i++){
				if(s[i][dx+1] == '.') return INF;
				s[i][dx+1] = '.';
			}
			x ++;dx ++;
		}else break;
	}
	return w*h;
}

int solve(int y, int x){
	int dx, dy;
	REP(i, n){
		if(s[y+i][x] == 'X') dy = y+i;
		else break;
	}
	REP(i, m){
		if(s[y][x+i] == 'X') dx = x+i;
		else break;
	}
	for(int i=y;i<=dy;i++)for(int j=x;j<=dx;j++){
		if(s[i][j] == '.') return -1;
		else s[i][j] = '.';
	}
	if(s[dy+1][dx] == '.' && s[dy][dx+1] == '.'){
		REP(k, n)
			REP(l, m)
				if(s[k][l] == 'X') return -1;
		return min(dy-y+1, dx-x+1);
	}
	int res1 = INF, res2 = INF;
	
	int w, h;
	vector<string> t = s;
	if(s[dy+1][dx] == 'X'){
		int sx = dx;
		RREP(i, dx){
			if(s[dy+1][i] == 'X') sx = i;
			else break;
		}
		w = dx - sx + 1;
		h = dy - y + 1;
		res1 = solve2(s, dy, dx, w, h);
		REP(k, n)
			REP(l, m)
				if(s[k][l] == 'X') res1 = INF;
	}
	if(t[dy][dx+1] == 'X'){
		int sy = dy;
		RREP(i, dy){
			if(t[i][dx+1] == 'X') sy = i;
			else break;
		}
		h = dy - sy + 1;
		w = dx - x + 1;
		res2 = solve2(t, dy, dx, w, h);
		REP(k, n)
			REP(l, m)
				if(t[k][l] == 'X') res2 = INF;
	}
	int res = min(res1, res2);
	if(res == INF) return -1;
	else return res;
}

main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	s = vector<string>(n+2);
	s[0] = string(m+2, '.');
	REP(i, n){
		cin >> s[i+1];
		s[i+1] = "." + s[i+1] + ".";
	}
	s[n+1] = string(m+2, '.');
	int mx = INF;
	int my = INF;
	n += 2;
	m += 2;
	REP(i, n){
		REP(j, m){
			if(s[i][j] == 'X'){
				int res = solve(i, j);
				cout << res << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}