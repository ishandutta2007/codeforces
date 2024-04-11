#include<bits/stdc++.h>
int n,i;
int main(){
	scanf("%d",&n);
	for(i=0;(1<<i)-1<n;++i);
	printf("%d\n",i);
	return 0;
}