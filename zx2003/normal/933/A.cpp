#include<bits/stdc++.h>
const int N=2005;
int f[N][N][3],g[N][N][3],n,a[N],i,j,pr[N][N],su[N][N],ans,ts[N],os[N];
inline int max(const int&a,const int&b){return a<b?b:a;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),ts[i]=ts[i-1]+(a[i]==2),os[i]=i-ts[i];
	for(i=1;i<=n;++i)
		for(pr[i][i]=f[i][i][a[i]]=1,j=i+1;j<=n;++j){
			f[i][j][2]=max(f[i][j-1][1],f[i][j-1][2])+(a[j]==2);
			f[i][j][1]=f[i][j-1][1]+(a[j]==1);pr[i][j]=max(f[i][j][2],f[i][j][1]);
		}
	for(i=n;i;--i)
		for(su[i][i]=g[i][i][a[i]]=1,j=i-1;j;--j){
			f[i][j][2]=max(f[i][j+1][1],f[i][j+1][2])+(a[j]==2);
			f[i][j][1]=f[i][j+1][1]+(a[j]==1);su[i][j]=max(f[i][j][2],f[i][j][1]);
		}
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)
			ans=max(ans,max(
				pr[1][i-1]+ts[n]-ts[i-1],
				max(os[i-1]+su[j][i]+ts[n]-ts[j],os[j]+pr[j+1][n]
				)));
	printf("%d\n",ans);
	return 0;
}