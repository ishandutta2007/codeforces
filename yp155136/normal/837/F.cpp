#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long double ld;
typedef __float128 lld;
typedef long long LL;
const int MAX_N = 2e5 +6;

LL a[MAX_N];
LL n,k;

LL okay(LL depth) {
	lld cnt=a[n];
	lld nnow=1;
	LL up=depth;
	LL down=1;
	for (int i=n-1;i>=1;i--) {
		nnow *=up;
		nnow/=down;
		down++;
		up++;
		if (a[i] == 0) {
			continue;
		}
		else {
			if (nnow > 1e18) return true;
			cnt += a[i]*nnow;
			if (cnt >= k) return true;
		}
	}
	return false;
}

LL pre[MAX_N];

void naive() {
	for (int ans=1;;ans++) {
		for (int i=1;n>=i;i++) {
			pre[i] = pre[i-1] + a[i];
			if (pre[i] >= k) {
				printf("%d\n",ans);
				return;
			}
		}
		for (int i=1;n>=i;i++) {
			a[i] = pre[i];
			if (a[i] >= k) {
				printf("%d\n",ans);
			}
		}
	}
}

int main () {
	scanf("%lld %lld",&n,&k);
	LL haha=-1;
	int id=0;
	for (int i=1;n>=i;i++) {
		scanf("%lld",&a[i]);
		if (a[i]) {
			if (!id) id=i;
		}
		if (a[i] >= k) haha=0;
	}
	if (haha == 0) {
		cout<<haha<<endl;
		return 0;
	}
	if (n-id>=4) {
		naive();
		return 0;
	}
	LL L=0,R=1e18 + 8;
	while (R-L!=1) {
		LL mid=(L+R)>>1;
		if (okay(mid)) R=mid;
		else L=mid;
	}
	printf("%lld\n",R);
}