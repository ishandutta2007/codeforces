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

class SegTree{
	typedef int SegT;
	private:
		vector<SegT> val;
		int n;
		
	public:
		SegTree(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n, 0);
		}
		//i vf
		SegT get(int i){
			SegT ret;
			i+=n-1;
			ret = val[i];
			while(i>0){
				i=(i-1)/2;
				ret = max(ret, val[i]);
			}
			return ret;
		}
		//[a, b) xZbg
		void set(int a,int b, SegT x,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return;
			if(a<=l&&r<=b){
				val[k] = x;
			}else{
				set(a,b,x,k*2+1,l,(l+r)/2);
				set(a,b,x,k*2+2,(l+r)/2,r);
			}
		}
};


int n;
main(){
	map<int, int> prev;
	map<int, int> cnt;
	scanf("%d", &n);
	SegTree seg(n+1);
	vi ans;
	int end = 1;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		cnt[x] ++;
		if(cnt[x] == 4){
			REP(j, 4) ans.push_back(x);
			prev.clear();
			cnt.clear();
		}else{
			if(!prev[x]) prev[x] = i;
			else{
				int t = seg.get(prev[x]);
				if(!t){
					seg.set(prev[x]+1, i, x);
					prev[x] = i;
				}else{
					REP(j, 2){
						ans.push_back(t);
						ans.push_back(x);
					}
					prev.clear();
					cnt.clear();
				}
			}
		}
	}
	printf("%d\n", ans.size());
	FOR(it, ans) printf("%d ", *it);
	return 0;
}