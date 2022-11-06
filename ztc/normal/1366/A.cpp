#include<stdio.h>
inline int Min(int p,int q){return p<q?p:q;}
int n,m,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",Min(Min(n,m),(n+m)/3));
	}
}