#include<bits/stdc++.h>
const int N=5005,inf=1ll<<30;
inline int min(const int&a,const int&b){return a<b?a:b;}
inline int max(const int&a,const int&b){return a>b?a:b;}
int f[N][N],g[N][N],h[N][N];//f->,g->a[i-1]-1 
int a[N],n,i,j,ans[N];
int main(){
	for(i=0;i<N;++i)for(j=0;j<N;++j)f[i][j]=g[i][j]=h[i][j]=inf;
	scanf("%d",&n);a[0]=1<<30;
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		if(i==1){
			f[i][1]=h[i][0]=0;
		}
		int na=min(a[i-1]-1,a[i]);
		for(j=0;j<=(i+1)/2;++j){
			if(a[i]<=a[i+1])g[i+1][j]=min(g[i+1][j],f[i][j]+a[i+1]-a[i]+1);
				else h[i+1][j]=min(h[i+1][j],f[i][j]);
			if(a[i]>=a[i-1]){
				f[i+1][j+1]=min(f[i+1][j+1],g[i][j]+max(0,a[i-1]-a[i+1]));
				h[i+1][j]=min(h[i+1][j],g[i][j]);
			}
			f[i+1][j+1]=min(f[i+1][j+1],h[i][j]+max(0,a[i]-a[i+1]+1));
			h[i+1][j]=min(h[i+1][j],h[i][j]);
			/*
			g[i+1][j]=max(g[i+1][j],f[i][j]+max(0,a[i+1]-a[i]+1));
			g[i+1][j]=max(g[i+1][j],g[i][j]+max(0,a[i+1]));
			g[i+1]
			if(a[i]<=a[i+1])g[i+1][j]=max(g[i+1][j],f[i][j]+a[i+1]-a[i]+1);
				else g[i+1][j]=max(g[i+1][j],)
			if(a[i]<a[i+1]){
				f[i+1][j+1]=min(f[i+1][j+1],min(f[i][j],g[i][j]));
				g[i+1][j]=max(g[i+1][j],min()+a[i+1]-a[i]);
			}
			f[i+1][j+1]=min(f[i+1][j+1],g[i][j]+c1);
			g[i+1][j]=min(g[i+1][j],f[i][j]+max(0,a[i+1]-a[i]+1));
			g[i+1][j]=min(g[i+1][j],g[i][j]);
			*/
		}
	}
	for(i=0;i<=(n+1)/2;++i)ans[i]=min(h[n][i],min(f[n][i],g[n][i]));
	for(i=(n+1)/2;i;--i)ans[i-1]=min(ans[i-1],ans[i]);
	for(i=1;i<=(n+1)/2;++i)std::cout<<ans[i]<<' ';
	return 0;
}