#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main() {
	int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if (1ll*a>1ll*b*c) {
			puts("-1");
			continue;
		}
		long long t2=1ll*b*d;
        long long x=1ll*a/t2;
        long long ans=1ll*(1ll*a+a-1ll*x*b*d)*(x+1)/2;
        printf("%lld\n",ans);
    }
}