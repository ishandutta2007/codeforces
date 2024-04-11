#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef long double ld;
const int MAX_N = 1e5 + 6;

struct BIT {
	LL a[MAX_N];
	int n;
	void init(int _n) {
		n=_n;
		for (int i=0;n>=i;i++) a[i]=0;
	}
	void upd(int x,LL val) {
		for(int i=x;n>=i;i += (i&(-i))) {
			a[i] += val;
		}
	}
	LL qry(int id) {
		LL ret=0;
		for(int i=id; i>=1; i-=(i&(-i))) {
			ret+=a[i];
		}
		return ret;
	}
} bit,bit2,bit3;

LL v[MAX_N];
int a[MAX_N];
LL val[MAX_N];
LL pre[MAX_N];

int main () {
	LL n;
	while (scanf("%I64d",&n) != EOF) {
		bit.init(n+1);
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			val[i] = bit.qry(n) - bit.qry(a[i]);
			bit.upd(a[i],1);
			v[i] = v[i-1] + val[i];
			pre[i] = pre[i-1] + v[i];
		}
		bit2.init(n+1);
		for (int i=1;n>=i;i++) {
			bit2.upd(a[i],n-i+1);
		}
		bit3.init(n+1);
		ld ans=0.0;
		LL sum=0;
		for (int i=1;n>=i;i++) {
			LL tot=0;
			tot += (n-i+1) * (v[i-1]+v[n]);
//			cout<<"tot = "<<tot<<endl;
			tot -= (pre[n] - pre[i-1]);
//			cout<<"tot = "<<tot<<endl;
			ld t=n-i+1;
			ans += (sum + tot + (t*(t+1)*(t-1))/12.0) / (ld(n*(n+1))/2.0);
			sum -= (bit3.qry(n)-bit3.qry(a[i]-1)) * (bit2.qry(a[i])-bit2.qry(a[i]-1));
			bit2.upd(a[i],-(bit2.qry(a[i])-bit2.qry(a[i]-1) ));
			bit3.upd(a[i],1);
			sum += (bit2.qry(a[i]-1));
		}
		cout<<fixed<<setprecision(20)<<ans<<endl;
	}
}