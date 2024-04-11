#include<bits/stdc++.h>
int n,i,j;
int main(){
	scanf("%d",&n);
	if(n%2==0)return puts("NO"),0;
	puts("YES");
	printf("1 ");
	for(i=4;i<n*2;i+=4)printf("%d %d ",i,i+1);
	for(i=2;i<n*2;i+=4)printf("%d %d ",i,i+1);
	printf("%d\n",n*2);
	return 0;
}