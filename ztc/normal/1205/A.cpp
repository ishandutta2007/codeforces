#include<stdio.h>
int n;
int main(){
	scanf("%d",&n);
	if(n&1){
		printf("YES\n");
		for(int i=1;i<=n;i++)printf("%d ",i*2-(i&1));
		for(int i=1;i<=n;i++)printf("%d ",i*2-!(i&1));
	}else printf("NO");
}