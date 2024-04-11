#include<bits/stdc++.h>
const int N=1005;
int n,x[N],y[N],i,j,m,a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	for(;;){
		for(i=1;i<=n;++i)if((x[i]+y[i]-x[1]-y[1])&1)break;
		if(i<=n){for(i=1;i<=n;++i)if((x[i]+y[i])&1)a[++m]=i;break;}
		for(i=1;i<=n;++i){if((x[i]+y[i])&1)++x[i];int nx=x[i]+y[i]>>1,ny=x[i]-y[i]>>1;x[i]=nx;y[i]=ny;}
	}
	printf("%d\n",m);for(i=1;i<=m;++i)printf("%d%c",a[i],i==m?'\n':' ');
	return 0;
}