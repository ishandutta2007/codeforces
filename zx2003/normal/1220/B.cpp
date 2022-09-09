#include<bits/stdc++.h>
const int N=1005;
int i,j,n,a[N][N],b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
	for(i=1;i<n;++i){
		int x,y;
		if(i==1)x=a[2][i],y=a[2][n];else x=a[1][i],y=a[1][n];
		long long z=1ll*a[i][n]*x/y;
		b[i]=sqrt(z);
		for(;1ll*b[i]*b[i]>z;--b[i]);for(;1ll*b[i]*b[i]<z;++b[i]);
	}
	b[n]=a[1][n]/b[1];
	for(i=1;i<=n;++i)printf("%d%c",b[i],i==n?'\n':' ');
	return 0;
}