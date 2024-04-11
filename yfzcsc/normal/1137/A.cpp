#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int a[1010][1010],n,m;
int Lx[1010][1010],Rx[1010][1010];
int Ly[1010][1010],Ry[1010][1010];
pii p[1010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)p[j]=pii(a[i][j],j);
		sort(p+1,p+m+1);
		for(int j=1,z=0;j<=m;++j){
			Lx[i][p[j].second]=z;
			z+=p[j].first!=p[j+1].first;
		}
		for(int j=m,z=0;j>=1;--j){
			Rx[i][p[j].second]=z;
			z+=p[j].first!=p[j-1].first;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)p[j]=pii(a[j][i],j);
		sort(p+1,p+n+1);
		for(int j=1,z=0;j<=n;++j){
			Ly[p[j].second][i]=z;
			z+=p[j].first!=p[j+1].first;
		}
		for(int j=n,z=0;j>=1;--j){
			Ry[p[j].second][i]=z;
			z+=p[j].first!=p[j-1].first;
		}
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j){
//			printf("<%d,%d,%d,%d>",Rx[i][j],Ry[i][j],Lx[i][j],Ly[i][j]);
			int ans=1+max(Rx[i][j],Ry[i][j])+max(Lx[i][j],Ly[i][j]);
			printf("%d ",ans);
		}
}