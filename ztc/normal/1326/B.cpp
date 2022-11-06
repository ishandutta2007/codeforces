#include<stdio.h>
int b,n,maxx=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b);
		int a=maxx+b;printf("%d ",a);
		if(a>maxx)maxx=a;
	}
}