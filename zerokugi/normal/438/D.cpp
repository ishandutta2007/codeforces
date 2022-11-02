#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)

class SegTree{
	typedef pii SegT;
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
			val=vector<SegT>(2*n, pii(0, 0));
		}
		SegTree(const vector<SegT> &in){
			n=1;
			while(n<in.size())n<<=1;
			val=vector<SegT>(2*n, pii(0, 0));
			for(int i=n-1 + in.size()-1;i>=0;i--){
				if(n-1 <= i) val[i] = in[i - (n-1)];
				else val[i] = combine(val[i*2+1],val[i*2+2]);
			}
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
		SegT query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return pii(0, 0);
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};

class BIT {
	int n;
	vector<ll> vs;
public:
	BIT(int size) {
		n=1;
		while(n<size) n<<=1;
		vs = vector<ll>(2*n);
	}
	//O(log n)
	void add(int k, ll a) {
		for(int i = k+1; i <= n; i += i & -i) vs[i] += a;
	}
	//[s,t)	O(log n)
	ll sum(int s, int t) {
		if(s > 0) return sum(0, t) - sum(0, s);
		ll res = 0;
		for(int i = t; i > 0; i -= i & -i) res += vs[i];
		return res;
	}
};


int n, m;
main(){
	scanf("%d%d", &n, &m);
	vector<pii> d(n);
	BIT bit(n);
	REP(i, n){
		ll x=0;
		scanf("%I64d", &x);
		d[i] = pii(x, i);
		bit.add(i, x);
	}
	SegTree seg(d);
	REP(i, m){
		int t, l, r, k, x;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d", &l, &r);
			printf("%I64d\n", bit.sum(l-1, r));
		}else if(t == 2){
			scanf("%d%d%d", &l, &r, &x);
			while(1){
				pii ret = seg.query(l-1, r);
				if(ret.first < x) break;
				int y = ret.first % x;
				seg.update(ret.second, pii(y, ret.second));
				bit.add(ret.second, y - d[ret.second].first);
				d[ret.second].first = y;
			}
		}else{
			scanf("%d%d", &k, &x);
			k --;
			bit.add(k, x - d[k].first);
			seg.update(k, pii(x, k));
			d[k] = pii(x, k);
		}
	}
	return 0;
}