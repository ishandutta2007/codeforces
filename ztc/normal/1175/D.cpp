#ifndef self_copying
#define self_copying
#endif
#include<stdio.h>
#include<algorithm>
int n,k;
long long a[300002],ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}ans=a[n]*(long long)k;
	std::sort(a+1,a+n);
	for(int i=1;i<k;i++)ans-=a[i];
	printf("%lld",ans);
}