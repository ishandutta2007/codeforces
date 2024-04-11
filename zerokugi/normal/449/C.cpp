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


int n;
main(){
	scanf("%d", &n);
	vi res(n+1);
	for(int i=2;i<=n;i++){
		if(i*i<=n && !res[i]) for(int j=i+i;j<=n;j+=i) if(!res[j]) res[j]=i;
	}
	
	vector<set<int> > pl(n+1);
	REP(i, n+1){
		if(i<2) continue;
		pl[res[i]?res[i]:i].insert(i);
	}
	vector<pii> ans;
	REP(i, n+1){
		if(i<3) continue;
		if(pl[i].size()&1 && i*2 <= n){
			pl[2].erase(i*2);
			pl[i].insert(i*2);
		}
		while(pl[i].size() > 1){
			int a = *pl[i].begin();pl[i].erase(a);
			int b = *pl[i].begin();pl[i].erase(b);
			ans.emplace_back(a, b);
		}
	}
	while(pl[2].size() > 1){
		int a = *pl[2].begin();pl[2].erase(a);
		int b = *pl[2].begin();pl[2].erase(b);
			ans.emplace_back(a, b);
	}
	printf("%d\n", ans.size());
	REP(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}