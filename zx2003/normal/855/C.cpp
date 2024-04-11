#include<cstdio>
const int N=100005,mo=1000000007,X=12;
int h[N],f1[N][X],f2[N][X],f3[N][X],n,m,k,z,u,v,xb,ans,i;//f1-> ==z,f2-> <z,f3-> >z
struct edge{
	int to,next;
}e[N<<1];
inline void addedge(int u,int v){
	e[++xb]=(edge){v,h[u]},h[u]=xb;
	e[++xb]=(edge){u,h[v]},h[v]=xb;
}
void dfs(int x,int fa){
	f1[x][1]=1,f2[x][0]=z-1,f3[x][0]=m-z;
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa){
			dfs(e[i].to,x);
			for(int j=k;j>=0;--j){
				int s1=0,s2=0,s3=0;
				for(int l=0;l<=j;++l){
					if(l<j)s1=(s1+1ll*f1[x][j-l]*f2[e[i].to][l])%mo;
					s2=(s2+1ll*f2[x][j-l]*(1ll*f1[e[i].to][l]+f2[e[i].to][l]+f3[e[i].to][l]))%mo;
					s3=(s3+1ll*f3[x][j-l]*(1ll*f2[e[i].to][l]+f3[e[i].to][l]))%mo;
				}
				f1[x][j]=s1,f2[x][j]=s2,f3[x][j]=s3;
			}
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	scanf("%d%d",&z,&k);
	dfs(1,0);
	for(i=0;i<=k;++i)ans=(1ll*ans+f1[1][i]+f2[1][i]+f3[1][i])%mo;
	return printf("%d\n",ans),0;
}