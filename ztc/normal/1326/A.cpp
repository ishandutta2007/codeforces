#include<stdio.h>
int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1)puts("-1");
		else{
			printf("2");
			for(int i=2;i<=n;i++)printf("3");puts("");
		}
	}
}