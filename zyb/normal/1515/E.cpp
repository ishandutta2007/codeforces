#include<bits/stdc++.h>
using namespace std;
#define N 405
long long f[N][N],a[N][N];
int n,m;
long long b[N];
inline void doit(int n) {
	a[0][0]=1;
	for(int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++) a[i][j]=(a[i-1][j]+a[i-1][j-1])%m;
		a[i][0]=1;
	}
	b[0]=1;
	for (int i=1;i<=n;i++) b[i]=b[i-1]*2%m;
}
int main() {
	scanf("%d%d",&n,&m);
	doit(n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++)
		for (int k=1;k<j;k++) {
			(f[i][j]+=1ll*a[j][k]*b[k-1]%m*f[i-k-1][j-k]%m)%=m;
		}
		f[i][i]=b[i-1];
	}
	long long ans=0;
	for (int i=1;i<=n;i++) (ans+=f[n][i])%=m;
	printf("%lld\n",ans);
}