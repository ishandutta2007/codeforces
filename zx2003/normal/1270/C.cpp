#include<bits/stdc++.h>
long long s;
int T,n,x,ss;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(s=ss=0;n--;)scanf("%d",&x),s+=x,ss^=x;
		printf("2\n%d %lld\n",ss,s+ss);
	}
}