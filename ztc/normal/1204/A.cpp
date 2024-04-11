#include<stdio.h>
char c[10002];int l=0,p=0;
int main(){
	scanf("%s",&c);
	while(c[l])l++,p|=c[l]=='1';
	printf("%d",(l+1>>1)-((l&1)&&p==0));
}