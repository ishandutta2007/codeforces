#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;
const LL INF = 1e15 + 6;

LL a[MAX_N];
LL cnt[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%lld",&a[i]);
			cnt[i] = a[i]/k;
			a[i] %= k;
		}
		bool can=true;
		for (int i=2;n>=i;i++) {
			can &= (a[i]==a[1]);
		}
		if (!can) puts("-1");
		else {
			LL mn = INF;
			for (int i=1;n>=i;i++) {
				mn = min(mn,cnt[i]);
			}
			LL ans=0;
			for (int i=1;n>=i;i++) {
				ans += (cnt[i]-mn);
			}
			printf("%lld\n",ans);
		}
	}
}