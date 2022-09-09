#include<bits/stdc++.h>
int n,k,a[1005],i,x,ans,z;
int main(){
	scanf("%d%d",&n,&k);z=n+1>>1;
	for(i=0;i<n;++i)scanf("%d",&x),++a[x];
	for(i=1;i<=k;++i)ans+=a[i]/2*2,z-=a[i]/2;
	printf("%d\n",ans+z);
	return 0;
}