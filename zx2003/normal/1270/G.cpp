#include<bits/stdc++.h>
const int N=1e6+5;
int T,n,a[N],i,j,c[N],m;
bool b[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);memset(b+1,0,n);m=0;
		for(i=1;i<=n;++i)scanf("%d",a+i),a[i]=i-a[i];
		for(i=1;!b[i];b[i]=1,i=a[i]);
		for(j=i;c[++m]=j,a[j]!=i;j=a[j]);
		printf("%d\n",m);for(i=1;i<=m;++i)printf("%d%c",c[i],i==m?'\n':' ');
	}
	return 0;
}