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
struct Query{
	int l, r, x;
	Query(int l, int r, int x)
		:l(l), r(r), x(x){
	}	
};
class SegTreeLazy{
	typedef int SegT;
	static const SegT defvalue = -1;
	private:
		vector<SegT> val, lazy;
		vector<int> lazyf;
		int n;
		
		SegT combine(SegT a, SegT b){
			return a&b;
		}
		SegT merge(SegT a, SegT b){
			return a|b;
		}
		
		void applyLazy(SegT k){
			if(lazyf[k]){
				lazyf[k] = 0;
				val[k] = merge(val[k], lazy[k]);
				if(k*2+2 < lazy.size()){
					lazy[k*2+1] = lazyf[k*2+1] ? merge(lazy[k*2+1], lazy[k]) : lazy[k];
					lazy[k*2+2] = lazyf[k*2+2] ? merge(lazy[k*2+2], lazy[k]) : lazy[k];
					lazyf[k*2+1] = lazyf[k*2+2] = 1;
				}
			}
		}
	public:
		SegTreeLazy(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n, 0);
			lazy=vector<SegT>(2*n, 0);
			lazyf=vector<int>(2*n, 0);
		}
		//[a, b) laXV
		void update(int a,int b,SegT x,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			applyLazy(k);
			if(r<=a||b<=l) return;
			if(a<=l&&r<=b){
				lazy[k] = x;
				lazyf[k] = 1;
				applyLazy(k);
			}else{
				update(a,b,x,k*2+1,l,(l+r)/2);
				update(a,b,x,k*2+2,(l+r)/2,r);
				val[k] = combine(val[k*2+1], val[k*2+2]);
			}
		}
		//[a, b) l
		SegT query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return -1;
			applyLazy(k);
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};


main(){
	scanf("%d%d", &n, &m);
	vector<Query> qs;
	REP(i, m){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x); l--;
		qs.emplace_back(l, r, x);
	}
	SegTreeLazy seg(n);
	REP(i, m) seg.update(qs[i].l, qs[i].r, qs[i].x);
	REP(i, m){
		if(seg.query(qs[i].l, qs[i].r) != qs[i].x){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	REP(i, n) printf("%d ", seg.query(i, i+1));
	return 0;
}