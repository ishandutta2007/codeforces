#include<stdio.h>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	a-=b;b=a-c;a=a+c;
	if(a==0&&b==0)return printf("0")&0;
	return putchar(a*b<=0?'?':(a>0?'+':'-'))&0;
}