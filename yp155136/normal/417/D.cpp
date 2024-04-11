#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e2 + 6;
const int MAX_M = 20;
const LL INF = 5e18;

LL dp[1<<(MAX_M)];

struct _ {
	LL a,b,c;
	void input() {
		scanf("%lld %lld %lld",&a,&b,&c);
		LL d=0;
		while (c--) {
			LL e;
			scanf("%lld",&e);
			e--;
			d += (1<<e);
		}
		c=d;
	}
} ipt[MAX_N];

bool operator<(const _ &p1,const _ &p2) {
	return p1.b < p2.b;
}

int main () {
	LL n,m,b;
	while (scanf("%lld %lld %lld",&n,&m,&b) != EOF) {
		for (int i=1;n>=i;i++) {
			ipt[i].input();
		}
		sort(ipt+1,ipt+n+1);
		fill(dp,dp+(1<<m),INF);
		dp[0]=0;
		LL ans=INF;
		for (int i=1;n>=i;i++) {
			int x=ipt[i].a,k=ipt[i].b,mask=ipt[i].c;
			for (int j=0;(1<<m)>j;j++) {
				int go=j|mask;
				if (go == j || dp[j] == INF) continue;
				dp[go]=min(dp[go],dp[j] + x);
			}
			ans = min(ans,dp[(1<<m)-1] + k*b);
		}
		if (ans==INF) puts("-1");
		else printf("%lld\n",ans);
	}
}