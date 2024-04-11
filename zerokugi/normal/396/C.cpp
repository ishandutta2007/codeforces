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
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

const int MOD = 1000000007;

int n, q;
vector<vector<int> > childs;
vector<int> lev, from, to, r;
void adddfs(int v, int l){
	int pid = to.size();
	from[v] = pid;
	to.push_back(v);
	lev[v] = l;
	FOR(it, childs[v]) adddfs(*it, l+1);
	r[pid] = to.size();
}


static const ll defvalue = 0;
class SegTree{
	typedef ll SegT;
	private:
		vector<SegT> val;
		int n;
		
		SegT combine(SegT a, SegT b){
			return min(a, b);
		}
		
	public:
		SegTree(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<SegT>(2*n, defvalue);
		}
		SegTree(const vector<SegT> &in){
			n=1;
			while(n<in.size())n<<=1;
			val=vector<SegT>(2*n, defvalue);
			for(int i=n-1 + in.size()-1;i>=0;i--){
				if(n-1 <= i) val[i] = in[i - (n-1)];
			}
		}
		//i vf a XV
		SegT get(int i){
			SegT ret = defvalue;
			i+=n-1;
			ret = val[i];
			while(i>0){
				i=(i-1)/2;
				(ret += val[i]) % MOD;
			}
			return ret;
		}
		//[a, b) l
		void add(int a,int b, SegT x,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l) return;
			if(a<=l&&r<=b){
				(val[k] += x) %= MOD;
			}else{
				add(a,b,x,k*2+1,l,(l+r)/2);
				add(a,b,x,k*2+2,(l+r)/2,r);
			}
		}
};

main(){
	scanf("%d", &n);
	childs = vector<vector<int> >(n);
	REP(i, n-1){
		int x;
		scanf("%d", &x);
		childs[x-1].push_back(i+1);
	}
	scanf("%d", &q);
	from = vector<int>(n);
	lev = vector<int>(n);
	r = vector<int>(n);
	adddfs(0, 0);
	SegTree seg1(n), seg2(n);
	REP(i, q){
		ll t, v, x, k;
		scanf("%I64d", &t);
		if(t == 1){
			scanf("%I64d%I64d%I64d", &v, &x, &k);v--;
//			printf("add1 [%d %d) %d\n", from[v], r[from[v]], x+k*lev[v]);
//			printf("add2 [%d %d) %d\n", from[v], r[from[v]], k);
			seg1.add(from[v], r[from[v]], (x+(ll)k*lev[v])%MOD);
			seg2.add(from[v], r[from[v]], k);
		}else{
			scanf("%I64d", &v);v--;
//			printf("%d - %d * %d\n", seg1.get(from[v]), seg2.get(from[v]), lev[v]);
			printf("%I64d\n", ((seg1.get(from[v]) - seg2.get(from[v]) * (ll)lev[v])%MOD + MOD) % MOD);
		}
	}
	return 0;
}