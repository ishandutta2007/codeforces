#include<bits/stdc++.h>
int T,n,k1,k2,x,i;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&k1,&k2);
		bool fl=0;
		for(;k1--;)scanf("%d",&x),fl|=x==n;
		for(;k2--;)scanf("%d",&x);
		puts(!fl?"NO":"YES");
	}
	return 0;
}