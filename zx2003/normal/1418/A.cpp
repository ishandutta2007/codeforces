#include<bits/stdc++.h>
int T,x,y,k;
long long a;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&x,&y,&k);
		a=1ll*k*(y+1);
		a=(a-1+x-1-1)/(x-1)+k;
		printf("%lld\n",a);
	}
}