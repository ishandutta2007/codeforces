#include<bits/stdc++.h>
const int N=1000005;
int s[N][10],i,j,q,l,r,k,g[N];
int main(){
	for(i=1;i<10;++i){
		memcpy(s[i],s[i-1],40);
		s[i][g[i]=i]=1;
	}
	for(;i<N;++i){
		for(l=i,j=1;l;j*=l%10?l%10:1,l/=10);
		memcpy(s[i],s[i-1],40);++s[i][g[i]=j<10?j:g[j]];
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",s[r][k]-s[l-1][k]);
	}
	return 0;
}