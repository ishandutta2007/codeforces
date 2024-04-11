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

class BIT{
	typedef ll T;
	private:
		vector<T> val;
		int n;
		
		T calc(const T a, const T b){
			return a + b;
		}
	public:
		BIT(){
		}
		BIT(int size){
			n=1;
			while(n<size)n<<=1;
			val=vector<T>(2*n,0LL);
		}
		//x vf a XV
		void add(int x,T a){
			x+=n-1;
			val[x]+=a;
			while(x>0){
				x=(x-1)/2;
				val[x]=calc(val[x*2+1],val[x*2+2]);
			}
		}
		//a<=x<b
		T query(int a,int b,int k=0,int l=0,int r=-1){
			if(r==-1)r=n;
			if(r<=a||b<=l)return 0LL;
			if(a<=l&&r<=b){
				return val[k];
			}else{
				return calc(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
			}
		}
};


class Seg{
    BIT dif, pre;
public:
    Seg(int n){
        dif = BIT(n);
        pre = BIT(n);
    }
    void add(int s, int t, ll v){
        dif.add(s, v);
        dif.add(t, -v);
        pre.add(s, v * s);
        pre.add(t, -v * t);
    }
    ll sum(int s, int t){
        if (s > 0) return sum(0, t) - sum(0, s);
        return dif.query(0, t) * t - pre.query(0, t);
    }
};

main(){
	int n, m, w;
	scanf("%d%d%d", &n, &m, &w);
	Seg segX(n+1), segY(m+1);
	ll sum = 0;
	REP(i, w){
		int a, x1, x2, y1, y2;
		ll v;
		scanf("%d%d%d%d%d", &a, &x1, &y1, &x2, &y2);
		if(a){
			printf("%I64d\n", segX.sum(x1-1, x2) + segY.sum(y1-1, y2) - sum);
		}else{
			scanf("%I64d", &v);
			segX.add(x1-1, x2, v * (y2-y1+1));
			segY.add(y1-1, y2, v * (x2-x1+1));
			sum += v * (x2-x1+1) * (y2-y1+1);
		}
	}
	return 0;
}