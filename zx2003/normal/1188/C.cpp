#include<bits/stdc++.h>
const int N=1005,mo=998244353;
int n,k,a[N],f[N][N],i,j,l,p,ans;
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);std::sort(a+1,a+n+1);
	for(i=1;i<=100000/(k-1);++i){
		for(j=0;j<=n;++j)f[0][j]=1;
		for(j=1;j<=k;++j)for(l=1,p=0;l<=n;++l){
			for(;p<l && a[l]-a[p+1]>=i;++p);
			f[j][l]=f[j-1][p];add(f[j][l],f[j][l-1]);
		}
		add(ans,f[k][n]);
	}
	printf("%d\n",ans);
	return 0;
}