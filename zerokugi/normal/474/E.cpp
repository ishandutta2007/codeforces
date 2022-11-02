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
#define int long long
typedef long long ll;
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

// _XV NG

typedef pair<int, int> SegT;
static const pair<int, int> defvalue(0, INF);
class SegTree{
	private:
		vector<SegT> val;
		int n;
		
		SegT combine(SegT a, SegT b){
			return max(a, b);
		}
		
	public:
		SegTree(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n, defvalue);
		}
		//i vf a XV
		void update(int i,SegT a){
			i+=n-1;
			val[i]=a;
			while(i>0){
				i=(i-1)/2;
				val[i]=combine(val[i*2+1],val[i*2+2]);
			}
		}
		//[a, b) l
		pair<int, int> query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return defvalue;
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};

int n, m;
ll k;
main(){
	scanf("%d%lld", &n, &k);
	vector<pair<ll, int> > d(n);
	REP(i, n){
		ll x;
		scanf("%lld", &x);
		d[i] = pii(x, i);
	}
	sort(ALL(d));
	SegTree seg(n);
	vi idx(n);
	vi prev(n, INF);
	REP(i, n) idx[d[i].second] = i;
	REP(i, n){
		int t = idx[i];
		int ub = lower_bound(ALL(d), pair<ll, int>(d[t].first-k+1, 0)) - d.begin();
		int lb = lower_bound(ALL(d), pair<ll, int>(d[t].first+k, 0)) - d.begin();
		pii res = max(seg.query(0, ub), seg.query(lb, n));
		seg.update(t, pii(res.first+1, t));
		prev[t] = res.second;
	}
	pii cur = seg.query(0, n);
	printf("%d\n", cur.first);
	int c = cur.second;
	vi ans;
	do{
		ans.push_back(1+d[c].second);
		c = prev[c];
	}while(c < n);
	RFOR(it, ans) printf("%d ", *it);
	return 0;
}