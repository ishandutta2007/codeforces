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
#include <unordered_set>
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

const int BLOCK = 100;
int n, m, q;
char d[100001][15];
pii target[1000005];

struct Query{
	char t, c;
	int x, y;
	Query(char t, int u, int v, char c=' '):t(t), x(u), y(v), c(c){}
};


pii predfs(int x, int y, const vi &ignore){
	if(x < 0 || y < 0 || n <= y || m <= x) return pii(x, y);
	const int t = y*10+x;
	if(target[t].first != -3) return target[t];
	int dx = 0, dy = 0;
	if(d[y][x] == '^') dy --;
	if(d[y][x] == '<') dx --;
	if(d[y][x] == '>') dx ++;
	if(*lower_bound(ALL(ignore), t) == t){
		return pii(x, y);
	}
	target[t] = pii(-2, -2);
	auto res = predfs(x+dx, y+dy, ignore);
	return target[t] = res;
}

pii dfs(int x, int y, const vi &ignore, unordered_set<int> &visited){
	if(x < 0 || y < 0 || n <= y || m <= x) return pii(x, y);
	const int t = y*10+x;
	if(visited.find(t) != visited.end()) return pii(-2, -2);
	visited.insert(t);
	int dx = 0, dy = 0;
	if(*lower_bound(ALL(ignore), t) == t){
		if(d[y][x] == '^') dy --;
		if(d[y][x] == '<') dx --;
		if(d[y][x] == '>') dx ++;
		return dfs(x+dx, y+dy, ignore, visited);
	}
	return dfs(target[t].first,  target[t].second, ignore, visited);
}

main(){
	scanf("%d%d%d", &n, &m, &q);
	REP(i, n){
		scanf("%s", d[i]);
	}
	while(q){
		char t, c;
		int x, y;
		vi ignore;
		vector<Query> query;
		for(int i=0;i<BLOCK&&q;){
			q--;
			scanf(" %c%d%d", &t, &y, &x); x--, y--;
			if(t == 'C'){
				ignore.push_back(y*10+x);
				scanf(" %c", &c);
				query.emplace_back(t, x, y, c);
				i ++;
			}else query.emplace_back(t, x, y);
		}
		ignore.push_back(INF);
		sort(ALL(ignore));
		UNIQUE(ignore);
		REP(i, n*10+m) target[i] = pii(-3, -3);
		REP(i, n)REP(j, m) predfs(j, i, ignore);
		REP(i, query.size()){
			const char t = query[i].t;
			const int x = query[i].x;
			const int y = query[i].y;
			const char c = query[i].c;
			if(t == 'A'){
				unordered_set<int> visited;
				pii res = dfs(x, y, ignore, visited);
				printf("%d %d\n", res.second + 1, res.first + 1);
			}else d[y][x] = c;
		}
	}
	return 0;
}