#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int n,m,S,T,p[N],u,v,w,g[N][N],i,j,n1,n2,hi0[N],hi1[N];
ll d[2][N],f0[N][N],f1[N][N],s[N][N],ff0[N],ff1[N],fff[N];
bool vi[N];
inline void dij(int s,int o){
	memset(d[o],10,n+1<<3);memset(vi+1,0,n);d[o][s]=0;
	for(i=1;i<n;++i){
		u=0;for(j=1;j<=n;++j)if(!vi[j] && d[o][j]<d[o][u])u=j;
		if(d[o][u]>3e12)return;vi[u]=1;for(j=1;j<=n;++j)if(g[u][j]<1<<30)d[o][j]=min(d[o][j],d[o][u]+g[u][j]);
	}
}
map<ll,int>mp0,mp1;
struct P{int x,y,w;}a[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for(i=1;i<=n;++i)scanf("%d",p+i);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)g[i][j]=1<<30;
	for(i=1;i<=m;++i)scanf("%d%d%d",&u,&v,&w),g[u][v]=min(g[u][v],w),g[v][u]=min(g[v][u],w);
	dij(S,0);dij(T,1);
	for(i=1;i<=n;++i)mp0[d[0][i]]=mp1[d[1][i]]=0;
	for(auto&u:mp0)u.second=++n1;for(auto&u:mp1)u.second=++n2;
	for(i=1;i<=n;++i)a[i]=(P){mp0[d[0][i]],mp1[d[1][i]],p[i]};
	for(i=1;i<=n;++i)hi0[a[i].x]=max(hi0[a[i].x],a[i].y),hi1[a[i].y]=max(hi1[a[i].y],a[i].x);
	for(i=1;i<=n1;++i){
		for(j=1;j<=n;++j)if(a[j].x>=i)s[i][a[j].y]+=a[j].w;
		for(j=n2-1;j>=1;--j)s[i][j]+=s[i][j+1];
	}
	for(i=n1;i>=1;--i){
		for(j=n2;j>=1;--j){
if(i==4 && j==1)
++i,--i;
			if(hi0[i]>=j)f0[i][j]=ff0[j]+s[i][j];
			if(hi1[j]>=i)f1[i][j]=ff1[i]+s[i][j];
			if(hi1[j]>=i)ff0[j]=max(-f1[i][j]-s[i][j],ff0[j]);
				else ff0[j]=max(ff0[j],ff0[j+1]);
			if(hi0[i]>=j)ff1[i]=max(-f0[i][j]-s[i][j],ff1[i]);
				else ff1[i]=max(ff1[i],fff[j]);
			fff[j]=ff1[i];
		}
	}
	if(f0[1][1]>0)puts("Break a heart");
	if(f0[1][1]==0)puts("Flowers");
	if(f0[1][1]<0)puts("Cry");
	return 0;
}