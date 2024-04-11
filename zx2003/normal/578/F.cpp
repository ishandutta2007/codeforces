#include<bits/stdc++.h>
const int N=205,L=105;
int mo,n,m,a[N][N],xb,g[L*L],id[L*L],i,j;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int calc(){
	int i,j,k,x,ans=1;
	for(i=1;i<=xb;++i)for(j=1;j<=xb;++j)a[i][j]=(a[i][j]%mo+mo)%mo;
	for(i=1;i<=xb;++i){
		for(j=i;j<=xb && !a[j][i];++j);
		if(j>xb)return 0;
		if(j!=i)for(k=1,ans=mo-ans;k<=xb;++k)std::swap(a[i][k],a[j][k]);ans=1ll*ans*a[i][i]%mo;
		for(j=1;j<=xb;++j)if(j!=i && a[j][i])for(k=i,x=1ll*a[j][i]*poww(mo-a[i][i],mo-2)%mo;k<=xb;++k)
			a[j][k]=(a[j][k]+1ll*a[i][k]*x)%mo;
	}
	return ans;
}
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
inline int I(int x,int y){return (x-1)*(m+1)+y;}
inline bool tryuni(int x,int y){x=gfa(x);y=gfa(y);if(x==y)return 0;g[x]=y;return 1;}
inline void ins(int x,int y){++a[x][x];++a[y][y];--a[x][y];--a[y][x];}
char c[L][L];
inline int solve(int o){
	int ecnt=0;
	for(i=1;i<=(n+1)*(m+1);++i)g[i]=i;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(c[i][j]!='*'){
		if((i+j)%2==o && c[i][j]=='\\' && !tryuni(gfa(I(i,j)),gfa(I(i+1,j+1))))return 0;
		if((i+j)%2!=o && c[i][j]=='/' && !tryuni(gfa(I(i,j+1)),gfa(I(i+1,j))))return 0;
	}else ++ecnt;
	xb=0;
	for(i=1;i<=n+1;++i)for(j=1;j<=m+1;++j)if((i+j)%2==o && g[I(i,j)]==I(i,j))
		id[I(i,j)]=++xb;
	if(xb>ecnt+1)return 0;
	for(i=1;i<=xb;++i)memset(a[i]+1,0,xb<<2);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(c[i][j]=='*'){
		if((i+j)%2==o)ins(id[gfa(I(i,j))],id[gfa(I(i+1,j+1))]);
			else ins(id[gfa(I(i,j+1))],id[gfa(I(i+1,j))]);
	}
	--xb;return calc();
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	for(i=1;i<=n;++i)scanf("%s",c[i]+1);
	printf("%d\n",(solve(0)+solve(1))%mo);
	return 0;
}