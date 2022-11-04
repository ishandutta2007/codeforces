#include<bits/stdc++.h>
#define mo 1000000007
#define N 1000005
using namespace std;
int n,m,inv[N],fac[N],f[N],s[N];
int main(){
	scanf("%d%d",&n,&m);
	inv[0]=inv[1]=fac[0]=1;
	for (int i=2;i<=n;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for (int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mo,
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=m+2;i<=n;i++)
		f[i]=1ll*fac[i-2]*((i-m-1)+s[i-1]+mo-s[i-m-1])%mo,
		s[i]=(s[i-1]+1ll*f[i]*inv[i-1])%mo;
	printf("%d",1ll*fac[n-1]*s[n]%mo); 
}