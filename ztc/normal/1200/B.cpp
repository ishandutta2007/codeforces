#include<stdio.h>
long long t,n,cnt,k,a;bool f;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&cnt,&k,&a);f=1;cnt+=a;
		for(int i=2;i<=n;i++){
			scanf("%lld",&a);
			if(cnt<a-k)f=0;
			cnt+=k<a?k:a;
		}printf("%s\n",f?"YES":"NO");
	}
}