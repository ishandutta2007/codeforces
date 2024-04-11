#include<bits/stdc++.h>
const int N=3e5+5;
int T,n,a[N],b[N],i;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
		puts(a[1]<a[n]?"YES":"NO");
	}
}