#include<stdio.h>
int main(){
	int n,p,q;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&p,&q);
		puts(p%q?"NO":"YES");
	}
}