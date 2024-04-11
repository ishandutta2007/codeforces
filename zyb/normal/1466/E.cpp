#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 500005
int i,j,k,l,s,n,m,f[N][2],a[N][65];
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		for (int i=0;i<=60;i++) f[i][0]=f[i][1]=0;
		for (int i=1;i<=n;i++) {
			long long x;
			scanf("%lld",&x);
			for (int j=0;j<=60;j++) f[j][a[i][j]=x&1]++,x>>=1;
		}
		int ans=0;
		for (int i=1;i<=n;i++) {
			long long sum1=0,sum2=0;
			for (int j=0;j<=60;j++) {
				if (a[i][j]==1) {
					(sum1+=(1ll<<j)%P*f[j][1]%P)%=P;
					(sum2+=(1ll<<j)%P*n%P)%=P;
				}
				else {
					(sum2+=(1ll<<j)%P*f[j][1]%P)%=P;
				}
			}
			(ans+=sum1*sum2%P)%=P;
		}
		printf("%d\n",ans);
	}
}