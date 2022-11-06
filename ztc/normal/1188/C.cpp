#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#define inf 998244353
int n,k,a[1002],f[1002][1002];
int lans;long long cnt=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=a[n]/(k-1?k-1:1)+1;i++){
		for(int j=1;j<=n;j++){
			int t=std::upper_bound(a+1,a+n+1,a[j]-i)-a;f[j][1]=j;
			for(int l=2;l<=k;l++){
				f[j][l]=(f[j-1][l]+f[t-1][l-1])%inf;
			}
		}
		if(lans!=0)cnt+=(long long)(lans-f[n][k])*(i-1);
		lans=f[n][k];
		if(!f[n][k])break;
	}
	printf("%lld",((cnt%inf)+inf)%inf);
}