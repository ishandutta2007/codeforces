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
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
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

main(){
	scanf("%d", &n);
	vi d(n+1);
	REP(i, n){
		int x;
		scanf("%d", &x); x--;
		d[i+1] = x + d[i];
	}
	int sum = 0;
	vi f(n+1);
	REPS(i, n){
		sum = d[i];
		int s = max(sum, i-sum);
		if(f[s]) continue;
		f[s] = -1;
		int j = i;
		int p = sum > i-sum;
		int q = 1-p;
		int last = q;
		while(j<n){
			int l = j, r = n;
			while(l+1 < r){
				int m = (l+r) >> 1;
				if(max(d[m] - d[j], (m-j) - (d[m] - d[j])) < s) l = m;
				else r = m;
			}
			if(max(d[r] - d[j], (r-j) - (d[r] - d[j])) != s){
				p = q = -1;
				break;
			}
			if(d[r] - d[j] > (r-j) - (d[r] - d[j])){
				p++;
				last = 0;
			}else{
				q++;
				last = q;
			}
			j = r;
		}
		if((p<q && last) || (q<p && !last)) f[s] = max(p, q);
	}
	vector<pii> ans;
	REPS(i, n){
		if(f[i] > 0) ans.emplace_back(f[i], i);
	}
	sort(ALL(ans));
	cout << ans.size() << endl;
	REP(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}