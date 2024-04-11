#include <cstdio>
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),putchar('1');
		for(int i=3;i<=n;++i)printf(" %d",i);puts(" 2");
	}
	return 0;
}