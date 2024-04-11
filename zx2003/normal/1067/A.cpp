#include<bits/stdc++.h>
const int N=1e5+5,mo=998244353,U=200;
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
int n,i,j,a[N],f[N][205][2],ans;
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i);
	if(a[1]==-1)for(i=1;i<=U;++i)f[1][i][0]=1;else f[1][a[1]][0]=1;
	for(i=2;i<=n;++i){
		int x;
		for(j=1,x=0;j<=U;++j)f[i][j][0]=x,add(x,f[i-1][j][0]),add(x,f[i-1][j][1]);
		for(j=U,x=0;j;--j)f[i][j][1]=x,add(x,f[i-1][j][1]);
		for(j=1;j<=U;++j)add(f[i][j][1],f[i-1][j][0]),add(f[i][j][1],f[i-1][j][1]);
		if(a[i]!=-1)for(j=1;j<=U;++j)if(j!=a[i])memset(f[i][j],0,8);
	}
	for(i=1;i<=U;++i)add(ans,f[n][i][1]);
	printf("%d\n",ans);
	return 0;
}