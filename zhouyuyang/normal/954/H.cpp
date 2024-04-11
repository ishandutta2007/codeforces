#include<bits/stdc++.h>
#define mo 1000000007
#define N 10005
using namespace std;
int sum[N],inv[N],Inv[N];
int s[N],ans[N],a[N],n;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	sum[1]=inv[1]=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=1ll*sum[i-1]*a[i]%mo;
		inv[i]=power(sum[i],mo-2);
		Inv[i]=power(a[i],mo-2);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			s[i+j]=(s[i+j]+1ll*sum[i]*sum[j])%mo;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++)
			s[i+j]=(s[i+j]+mo-1ll*sum[i]*sum[j]%mo)%mo;
		for (int j=i*2+1;j<=2*n;j++)
			ans[j-i*2]=(ans[j-i*2]+1ll*s[j]*inv[i]%mo*(a[i+1]-1)%mo*Inv[i+1])%mo;
		for (int j=i+1;j<=n;j++)
			ans[j-i]=(ans[j-i]+sum[j])%mo;
		for (int j=i+1;j<=n;j++){
			int tmp=1ll*sum[j]*inv[i]%mo;
			ans[2*(j-i)]=(ans[2*(j-i)]+1ll*sum[j]*tmp%mo*(a[i+1]-1)%mo*Inv[i+1]%mo*500000004)%mo;
		}
	}
	for (int i=1;i<=2*n-2;i++)
		printf("%d ",ans[i]);
}