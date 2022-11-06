int i_copy_my_own_code=1;
#include<stdio.h>
int n,m,c;
int main(){
	scanf("%d%d",&n,&m);
	c=n*m-1;
	for(int i=0;i+i<c;i++)printf("%d %d\n%d %d\n",i/m+1,i%m+1,(c-i)/m+1,(c-i)%m+1);
	if(!(c&1))printf("%d %d\n",n/2+1,m/2+1);
}