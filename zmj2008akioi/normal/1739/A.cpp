#include <cstdio>
int T,n,m;
int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		printf("%d %d\n",max(1,n-1),max(1,m-1));
	}
	return 0;
}