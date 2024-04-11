#include<cstdio>
const int N=200005;
struct edge{
	int to,next;
}e[N<<1];
int h[N],n,xb,a,b,i,j,rt,rt2,sz[N],f[N],dfn[N],x[N<<1],y[N<<1],z[N<<1],k,dad[N],lst;
inline void addedge(int a,int b){
	e[++xb]=(edge){b,h[a]};
	h[a]=xb;
	e[++xb]=(edge){a,h[b]};
	h[b]=xb;
}
inline void up(int&a,int b){
	if(a<b)a=b;
}
void dfs(int x,int fa){
	sz[x]=f[x]=1;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs(e[i].to,x),sz[x]+=sz[e[i].to],up(f[x],sz[e[i].to]);
	up(f[x],n-sz[x]);
	if(f[x]<b)rt=x,rt2=0,b=f[x];
		else if(f[x]==b)rt2=x;
}
void getv(int x,int fa){
	if(fa!=e[i].to && x!=e[i].to)dfn[++xb]=x,dad[xb]=fa;
	for(int j=h[x];j;j=e[j].next)if(e[j].to!=fa)getv(e[j].to,x);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	b=1<<30;
	dfs(1,0);
	for(i=h[rt];i;i=e[i].next)
		if(e[i].to!=rt2){
			xb=0;
			getv(lst=e[i].to,rt);
			for(j=1;j<=xb;++j){
				x[++k]=rt,y[k]=lst,z[k]=dfn[j];
				x[++k]=dfn[j],y[k]=dad[j],z[k]=e[i].to;
				lst=dfn[j];
			}
			x[++k]=rt,y[k]=lst,z[k]=e[i].to;
		}
	if(rt2)for(i=h[rt2];i;i=e[i].next)
		if(e[i].to!=rt){
			xb=0;
			getv(lst=e[i].to,rt2);
			for(j=1;j<=xb;++j){
				x[++k]=rt2,y[k]=lst,z[k]=dfn[j];
				x[++k]=dfn[j],y[k]=dad[j],z[k]=e[i].to;
				lst=dfn[j];
			}
			x[++k]=rt2,y[k]=lst,z[k]=e[i].to;
		}
	printf("%d\n",k);
	for(i=1;i<=k;++i)printf("%d %d %d\n",x[i],y[i],z[i]);
	return 0;
}