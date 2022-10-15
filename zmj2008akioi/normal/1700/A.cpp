#include <cstdio>
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&m,&n);
		printf("%lld\n",n*(n+1)/2+(long long)m*(m+1)*n/2-n);
	}
	return 0;
}