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


// Z v



class RARS{
	typedef ll SegT;
	class SegTree{
		private:
			vector<SegT> val;
			int n;
			
			SegT combine(SegT a, SegT b){
				return a + b;
			}
			
		public:
			SegTree(int size){
				n=1;
				while(n<size)n<<=1;
				val=vector<SegT>(2*n, 0);
			}
			SegTree(const vector<SegT> &in){
				n=1;
				while(n<in.size())n<<=1;
				val=vector<SegT>(2*n, 0);
				for(int i=n-1 + in.size()-1;i>=0;i--){
					if(n-1 <= i) val[i] = in[i - (n-1)];
					else val[i] = combine(val[i*2+1],val[i*2+2]);
				}
			}
			//i vf a XV
			void update(int i,SegT a){
				i+=n-1;
				val[i]+=a;
				while(i>0){
					i=(i-1)/2;
					val[i]=combine(val[i*2+1],val[i*2+2]);
				}
			}
			//[a, b) l
			SegT query(int a,int b,int k=0,int l=0,int r=-1){
				if(r==-1)r=n;
				if(r<=a||b<=l) return 0;
				if(a<=l&&r<=b){
					return val[k];
				}else{
					return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
				}
			}
	};
    SegTree dif, pre;
public:
    RARS(int n):dif(n),pre(n){}
    void add(int s, int t, ll v){
        dif.update(s, v);
        dif.update(t, -v);
        pre.update(s, v * s);
        pre.update(t, -v * t);
    }
    ll sum(int s, int t){
        if (s > 0) return sum(0, t) - sum(0, s);
        return dif.query(0, t) * t - pre.query(0, t);
    }
};


int n, m;
main(){
	scanf("%d%d", &n, &m);
	RARS seg(n);
	set<pii> range;
	REP(i, n+1) range.insert(pii(i, i));
	REP(i, m){
		int type, l, r, x;
		scanf("%d%d%d", &type, &l, &r);
		if(type == 1){
			scanf("%d", &x);
			l --;
			auto it = range.lower_bound(pii(l+1, 0));
			int w = it->second;
			--it;
			if(it->first < l) range.insert(pii(l, w));
			it = range.lower_bound(pii(l+1, 0));
			while(it!=range.end() && it->first <= r){
				seg.add(l, it->first, abs(x - it->second));
				l = it->first;
				it = range.erase(it);
			}
			seg.add(l, r, abs(x - it->second));
			range.insert(pii(r, x));
		}else{
			printf("%I64d\n", seg.sum(l-1, r));
		}
	}
	return 0;
}