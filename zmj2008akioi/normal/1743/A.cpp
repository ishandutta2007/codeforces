#include <cstdio>
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%*d");
		n=10-n,printf("%d\n",3*n*(n-1));
	}
	return 0;
}