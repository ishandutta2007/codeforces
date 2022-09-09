#include<bits/stdc++.h>
int n,k,i;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;1ll*i*(i+1)/2-(n-i)!=k;++i);
	printf("%d\n",n-i);
	return 0;
}