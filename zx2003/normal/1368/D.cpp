#include<bits/stdc++.h>
int n,a[200005],b[29],i,j;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		for(j=0;j<20;++j)b[j]+=a[i]>>j&1;
	}
	long long ans=0;
	for(;n--;){
		int x=0;
		for(j=0;j<20;++j)if(b[j])x|=1<<j,--b[j];
		ans+=1ll*x*x;
	}
	printf("%lld\n",ans);
}