#include<bits/stdc++.h>
using namespace std;
const int N=2e3+99;
int n,m,l[N],s[N],c[N*2],i,j,k,f[N][N],g[N],ans;
inline void upa(int&a,const int&b){a<b?a=b:0;}
int main(){
	for(i=0;i<N;++i)for(j=0;j<N;++j)f[i][j]=j==0?0:-(1<<30);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",l+i);
	for(i=1;i<=n;++i)scanf("%d",s+i);
	for(i=1;i<=n+m;++i)scanf("%d",c+i);
	for(i=n;i;--i){
		for(j=1;j<=n-i+1;++j){
			g[j]=f[l[i]][j-1]-s[i];
			for(k=0;g[j]+=c[l[i]+k],j-1>>k&1;++k);
		}
		for(j=1;j<=n-i+1;++j){
			for(k=0;j>>k;++k)upa(f[l[i]+k][j>>k],g[j]);
			upa(f[l[i]+k][0],g[j]);
			upa(ans,g[j]);
		}
		for(j=l[i];j+1<N;++j)upa(f[j+1][0],f[j][0]);
	}
	printf("%d\n",ans);
	return 0;
}