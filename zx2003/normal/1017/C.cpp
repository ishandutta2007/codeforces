#include<bits/stdc++.h>
int n,i,x,mi,mix,j;
int main(){
	mi=1<<30;
	scanf("%d",&n);
	/*
	for(i=1;i<=n;++i){
		int z=i+(n+i-1)/i;
		if(z<mi)mi=z,mix=i;
	}
	*/
	mix=ceil(sqrt(n));
	for(i=mix;i;--i)
		for(j=i;j<=n;j+=mix)printf("%d ",j);
	return 0;
}