#include <cstdio>
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",n+((n>>1)<<1)+((n/3)<<1));
	}
	return 0;
}