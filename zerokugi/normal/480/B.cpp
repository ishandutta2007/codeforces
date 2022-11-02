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


int n, l, x, y;

main(){
	scanf("%d%d%d%d", &n, &l, &x, &y);
	set<int> me;
	int f = 0, tar=0, tar2=0;
	REP(i, n){
		int t;
		scanf("%d", &t);
		me.insert(t);
		if(me.count(t-x)) f |= 1;
		if(me.count(t-y)) f |= 2;
		if(me.count(t-x-y)){
			f |= 4;
			tar = t-x;
		}
		if(me.count(t+x-y)){
			if(t+x<=l){
				f |= 8;
				tar2 = t+x;
			}else if(0<=t-y){
				f |= 8;
				tar2 = t-y;
			}
		}
	}
	if((f&3) == 3)puts("0");
	else if(f&1) printf("%d\n%d\n", 1, y);
	else if(f&2) printf("%d\n%d\n", 1, x);
	else if(f&4) printf("%d\n%d\n", 1, tar);
	else if(f&8) printf("%d\n%d\n", 1, tar2);
	else printf("%d\n%d %d\n", 2, x, y);
	return 0;
}