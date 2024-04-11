#include<bits/stdc++.h>
#define mo 1000000007
#define N 200005
using namespace std;
int fac[N],inv[N],n,k,ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int S(int n,int k){
	if (k>n) return 0;
	int ans=0;
	for (int x=k;x>0;x--){
		int tmp=1ll*C(k,x)*power(x,n)%mo;
		if ((k-x)&1) tmp=mo-tmp;
		ans=(ans+tmp)%mo;
	}
	return 1ll*ans*inv[k]%mo;
}
int main(){
	scanf("%d%d",&n,&k);
	fac[0]=inv[0]=inv[1]=1;
	for (int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	inv[n]=power(fac[n],mo-2);
	for (int i=n;i>=1;i--)
		inv[i-1]=1ll*inv[i]*i%mo;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ans=(ans+x)%mo;
	} 
	printf("%d",1ll*ans*(S(n,k)+1ll*(n-1)*S(n-1,k)%mo)%mo);
}