#include <cstdio>
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %*d",&n);bool tag=false;
		for(int w,i=1;i<=n;++i)scanf("%d",&w),tag|=w;
		puts(tag?"YES":"NO");
	}
	return 0;
}