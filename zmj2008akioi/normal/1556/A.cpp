#include <cstdio>
int t,k,a,b;
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&a,&b);
		if((a+b)%2!=0)printf("-1\n");
		else if(a==0&&b==0)printf("0\n");
		else if(a==b)printf("1\n");
		else printf("2\n");
	}
	return 0;
}