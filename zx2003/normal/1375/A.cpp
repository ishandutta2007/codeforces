#include<bits/stdc++.h>
int T,n,a[199],i;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=n;i+=2)if(a[i]<0)a[i]*=-1;
		for(i=2;i<=n;i+=2)if(a[i]>0)a[i]*=-1;
		for(i=1;i<=n;++i)printf("%d%c",a[i],i==n?'\n':' ');
	}
}