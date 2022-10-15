#include <cstdio>
const int N=1e6+10;
int T,n,top,stk[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=9;n;--i){
			if(n>i)n-=i,stk[++top]=i;
			else stk[++top]=n,n=0;
		}
		while(top)printf("%d",stk[top--]);
		putchar('\n');
	}
	return 0;
}