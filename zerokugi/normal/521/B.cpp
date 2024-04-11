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
const int MOD = 1000000009;


int n, m;
int dp[20001];
int d[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
map<pii, int> blocks;
set<int> q;
vector<pii> p;

bool removable(int x, int y){
	REP(i, 3){
		int tx = x-1+i;
		int ty = y+1;
		if(blocks.count(pii(tx, ty))){
			if(blocks.count(pii(tx-1, ty-1)) + blocks.count(pii(tx, ty-1)) + blocks.count(pii(tx+1, ty-1)) <= 1) return 0;
		}
	}
	return 1;
}

main(){
	cin >> n;
	REP(i, n){
		int x, y;
		cin >> x >> y;
		p.eb(x, y);
		blocks[pii(x, y)] = i;
	}
	int turn = 0;
	vi ans;
	do{
		FOR(it, blocks){
			int x, y;
			tie(x, y) = it->first;
			if(removable(x, y)) q.insert(it->second);
		}
		while(!q.empty()){
			int t = turn%2 ? *q.begin() : *q.rbegin();
			q.erase(t);
			if(!blocks.count(p[t]) || !removable(p[t].first, p[t].second)) continue;
			blocks.erase(p[t]);
			ans.pb(t);
			REP(i, 8){
				int tx = p[t].first+d[i][0];
				int ty = p[t].second+d[i][1];
				auto it = blocks.find(pii(tx, ty));
				if(it == blocks.end()) continue;
				int idx = it->second;
				if(removable(tx, ty)) q.insert(idx);
				else q.erase(idx);
			}
			turn ++;
		}
	}while(!blocks.empty());
	ll sum = 0;
	ll b = 1;
	RREP(i, n){
		sum += b*ans[i]%MOD;
		b=b*n%MOD;
	}
	cout << sum % MOD << endl;
	return 0;
}