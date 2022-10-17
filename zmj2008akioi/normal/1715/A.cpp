#include <cstdio>
const int N=1e6+10;
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m),--n,--m;
		if(!n&&!m)puts("0"); 
		else if(n>m)printf("%d\n",(m<<1)+n+1);
		else printf("%d\n",(n<<1)+m+1);
	}
	return 0;
}