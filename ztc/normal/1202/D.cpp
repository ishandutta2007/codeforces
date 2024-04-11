#include<stdio.h>
int a[45002],t,n,top,cnt;char str[100002];
int main(){
	scanf("%d",&t);
	for(int i=1;i<=45000;i++)a[i]=i*(i-1)>>1;
	while(t--){
		scanf("%d",&n);top=0;cnt=0;
		for(int i=45000;i>=2;i--){
			while(n>=a[i]){
				n-=a[i];cnt++;
				str[++top]='7';
			}str[++top]='3';
		}str[++top]='3';str[++top]='1';
		while(top){putchar(str[top]);cnt-=str[top]=='7';top--;if(cnt==0)break;}putchar('\n');
	}
}