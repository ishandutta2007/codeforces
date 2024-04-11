#include<stdio.h>
int a[10],n;char c;
int main(){
	scanf("%d",&n);
	while(getchar()!='\n');
	while(n--){
		c=getchar();
		if(c=='L')for(int i=0;i<=9;i++){if(!a[i]){a[i]=1;break;}}
		else if(c=='R')for(int i=9;i>=0;i--){if(!a[i]){a[i]=1;break;}}
		else a[c-'0']=0;
	}for(int i=0;i<=9;i++)printf("%d",a[i]);
}