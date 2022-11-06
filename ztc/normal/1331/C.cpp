#include<stdio.h>
int n,m=0;
int main(){
	scanf("%d",&n);
	if(n&1)m|=16;
	if(n&2)m|=2;
	if(n&4)m|=8;
	if(n&8)m|=4;
	if(n&16)m|=1;
	if(n&32)m|=32;
	printf("%d",m);
}