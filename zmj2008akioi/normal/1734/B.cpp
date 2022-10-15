#include <cstdio>
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j)printf("%d ",j==1||j==i);
			putchar('\n');
		}
	}
	return 0;
}