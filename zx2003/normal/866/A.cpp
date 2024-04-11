#include<cstdio>
int n;
int main(){
	scanf("%d",&n);
	if(n>1)printf("%d %d\n1 2\n",n*2-2,2);
		else printf("%d %d\n1 2\n",1,2);
	return 0;
}