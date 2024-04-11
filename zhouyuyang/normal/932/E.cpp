#include<bits/stdc++.h>
#define mo 1000000007
#define N 5005
using namespace std;
int fac[N],inv[N];
int v[N],c[N];
int n,k,ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
int C(int i,int j){
	return 1ll*fac[i]*inv[j]%mo*inv[i-j]%mo;
}
int main(){
	scanf("%d%d",&n,&k);
	int m=min(n,k);
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<=m;i++)
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo; 
	for (int i=1;i<=m;i++){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	for (int i=1;i<=m;i++){
		v[i]=power(i,k);
		for (int j=1;j<i;j++)
			v[i]=(v[i]+mo-1ll*v[j]*C(i,j)%mo)%mo;
	}
	c[0]=1;
	for (int i=1;i<=m;i++)
		c[i]=1ll*c[i-1]*(n-i+1)%mo;
	for (int i=1;i<=m;i++)
		c[i]=1ll*c[i]*inv[i]%mo;
	for (int i=1;i<=m;i++){
		int tmp=1ll*c[i]*v[i]%mo;
		ans=(ans+1ll*tmp*power(2,n-i))%mo;
	}
	printf("%d",ans);
}