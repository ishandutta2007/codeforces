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
const int INF = 1000000000;

typedef int SegT;
const int defvalue = 0;
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
			val=vector<SegT>(2*n, defvalue);
		}
		SegTree(const vector<SegT> &in){
			n=1;
			while(n<in.size())n<<=1;
			val=vector<SegT>(2*n, defvalue);
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
			if(r<=a||b<=l) return defvalue;
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return combine(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};


int n;
main(){
	int i,j;
	scanf("%d", &n);
	vector<int> a(n);
	REP(i, n){
		scanf("%d", &a[i]);
		a[i] = !a[i];
	}
	SegTree seg(a);
	ll ans = 0;
	REP(i, n){
		if(!a[i]){
			ans += seg.query(i + 1, n);
		}
	}
	cout << ans << endl;
	return 0;
}