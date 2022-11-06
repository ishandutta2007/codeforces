#include<stdio.h>
int t;
long long n,k,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		ans=0;
		while(n){
			ans+=n%k+1;
			n/=k;
		}
		printf("%lld\n",ans-1);
	}
}