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
typedef pair<ll, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

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

const ll INF = 1LL<<60;
const double EPS = 1e-8;
const int MOD = 1000000007;

int n, m, k;
vector<vp> g;
vector<ll> dist;

void dijkstra(int s, vector<pii> &ret){
	int n = g.size();
	ret = vector<pii>(n, pii(INF, 0));
	priority_queue<pii, vector<pii>, greater<pii> > dp;
	dp.push(pii(0, s));
	ret[s] = pii(0, 1);
	while(!dp.empty()){
		int s = dp.top().second;
		int c = dp.top().first;
		dp.pop();
		if(ret[s].first < c) continue;
		FOR(it, g[s]){
			int t = it->first;
			if(ret[t].first > ret[s].first+it->second){
				ret[t].first = ret[s].first+it->second;
				ret[t].second = 1;
				dp.push(pii(ret[t].first, t));
			}else if(ret[t].first == ret[s].first+it->second){
				ret[t].second ++;
			}
		}
	}
}

main(){
	scanf("%d%d%d", &n, &m, &k);
	g = vector<vp>(n);
	dist = vector<ll>(n, INF);
	vp e;
	REP(i, m){
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		g[u-1].emplace_back(v-1, x);
		g[v-1].emplace_back(u-1, x);
	}
	REP(i, k){
		int u, x;
		scanf("%d%d", &u, &x);
		g[0].emplace_back(u-1, x);
		e.emplace_back(u-1, x);
		chmin(dist[u-1], (ll)x);
	}
	sort(ALL(e));
	int ans = 0;
	vector<pii> res;
	dijkstra(0, res);
//	cout << res << endl;
	REP(j, k){
		int i = e[j].first;
		ll d = e[j].second;
		int c = 1;
		while(j+1<k && e[j] == e[j+1]){
			c++;j++;
		}
//		printf("%d %d %d\n", i, d, c);
		if(d >  res[i].first) ans += c;
		if(d == res[i].first) ans += (res[i].second > c) ? c : c-1;
	}
	printf("%d\n", ans);
	return 0;
}