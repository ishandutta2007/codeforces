#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long double ld;
typedef long long LL;
const ld eps = 1e-9;

ld dis(LL x1,LL y1,LL x2,LL y2) {
	return (ld)(sqrt((x1-x2)*(x1-x2) + (y2-y1)*(y2-y1)));
}

int main () {
	LL r,d;
	scanf("%lld %lld",&r,&d);
	LL ans=0;
	int n;
	scanf("%d",&n);
	for (int i=1;n>=i;i++) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		ld rr=dis(0,0,a,b);
		if (r-d-eps <= rr-c &&rr+c<=r+eps) ans++;
	}
	printf("%lld\n",ans);
}