#include <cstdio>
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;++i)scanf("%*d %*d");
		puts(n==m?"NO":"YES");
	}
	return 0;
}