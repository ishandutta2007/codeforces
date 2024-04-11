#include<stdio.h>
#define mod 998244353
int a[200002],n,k,ans=1;
int main(){
	scanf("%d%d",&n,&k);
	printf("%lld ",1ll*k*(n-k+1+n)/2);int val=n-k+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]>=val;
	for(int i=1,cnt=0,j=0;i<=n;i++){
		if(a[i]){if(j)ans=1ll*ans*(cnt+1)%mod;cnt=0;j++;}
		else cnt++;
	}printf("%d",ans);
}