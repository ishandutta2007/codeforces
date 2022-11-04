#include<bits/stdc++.h>
#define N 250005
using namespace std;
int n,k,mo,ans;
int hr[N],fac[N],inv[N],f[27][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&k,&mo);
	inv[0]=inv[1]=fac[0]=1;
	for (int i=2;i<=n;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for (int i=1;i/2<=n;i*=2)
		for (int j=i/2;j<i&&j<=n;j++)
			hr[j]=i;
	for (int i=1;i<=n;i++){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	ans=power(k,n);
	if (n%2==0){
		f[0][0]=1;
		for (int i=0;i<26;i++)
			for (int j=0;j<=n;j++)
				if (f[i][j]&&(j&n)==j)
					for (int k=j+hr[j];k<=n;k=(k+1)|j)
						if ((k&n)==k)
							f[i+1][k]=(f[i+1][k]+1ll*f[i][j]*inv[k-j]%mo)%mo;
		int tmp=0;
		for (int i=1;i<=26;i++)
			tmp=(tmp+1ll*f[i][n]*inv[k-i])%mo;
		ans=(ans+mo-1ll*tmp*fac[n]%mo*fac[k]%mo)%mo;
	}
	printf("%d",ans);
}