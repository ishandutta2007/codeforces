#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct edge{
	int to,next;
};
struct Tree_1{
	edge e[N];
	int head[N],tot;
	int dfn[N],low[N];
	int sta[N],be[N];
	int blocks,n,T;
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
	}
	void tarjan(int x,int ban){
		dfn[x]=low[x]=++T;
		sta[++*sta]=x;
		for (int i=head[x];i;i=e[i].next)
			if (!dfn[e[i].to]){
				tarjan(e[i].to,i);
				low[x]=min(low[x],low[e[i].to]);
			}
			else if (i^ban^1)
				low[x]=min(low[x],dfn[e[i].to]);
		if (dfn[x]==low[x]){
			blocks++;
			int y=19260817;
			for (;y!=x;--*sta){
				y=sta[*sta];
				be[y]=blocks;
			}
		}
	}
	void init(){
		T=0; tot=1; *sta=0; blocks=0;
	}
}T1;
struct Tree_2{
	edge e[N];
	int head[N],tot;
	int pos[N],fa[N][21];
	int dep[N],T,n;
	Tree_2(){
		tot=0;
	}
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
	}
	void dfs(int x,int f,int d){
		pos[x]=++T; fa[x][0]=f; dep[x]=d;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=f) dfs(e[i].to,x,d+1);
	}
	void buildst(int n){
		for (int i=1;i<=20;i++)
			for (int j=1;j<=n;j++)
				fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int LCA(int x,int y){
		if (dep[x]<dep[y]) swap(x,y);
		int tmp=dep[x]-dep[y];
		for (int i=20;i>=0;i--)
			if (tmp&(1<<i)) x=fa[x][i];
		for (int i=20;i>=0;i--)
			if (fa[x][i]!=fa[y][i])
				x=fa[x][i],y=fa[y][i];
		return (x==y?x:fa[x][0]);
	}
}T2;
int be[N],x[N],y[N];
int n,m,cases;
void init(){
	T1.init();
	scanf("%d%d%d",&n,&m,&cases);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		T1.add(x[i],y[i]);
		T1.add(y[i],x[i]);
	}
	for (int i=1;i<=n;i++)
		if (!T1.dfn[i]) T1.tarjan(i,0);
	for (int i=1;i<=n;i++)
		be[i]=T1.be[i];
	for (int i=1;i<=m;i++){
		int X=T1.be[x[i]],Y=T1.be[y[i]];
		if (X!=Y) T2.add(X,Y),T2.add(Y,X);
	}
	for (int i=1;i<=T1.blocks;i++)
		if (!T2.pos[i]) T2.dfs(i,0,1); 
	T2.buildst(T1.blocks);
}
int tg;
int read(){
	int x;
	scanf("%d",&x);
	x=(x+tg+n-1)%n+1;
	return be[x];
}
bool cmp(int x,int y){
	return T2.pos[x]<T2.pos[y];
}
int z[N],p[N],q[N];
void solve(int id){
	int cntv,cnte,cntp=0;
	scanf("%d%d",&cntv,&cnte);
	for (int i=1;i<=cntv;i++)
		p[++cntp]=z[i]=read();
	for (int i=1;i<=cnte;i++){
		p[++cntp]=x[i]=read();
		p[++cntp]=y[i]=read();
	}
	sort(p+1,p+cntp+1,cmp);
	cntp=unique(p+1,p+cntp+1)-p-1;
	int cntP=cntp;
	int t=1; q[t]=p[1];
	for (int i=2;i<=cntp;i++){
		int w=T2.LCA(q[t],p[i]);
		for (;t>1&&T2.dep[w]<=T2.dep[q[t-1]];t--)
			T1.add(q[t],q[t-1]),T1.add(q[t-1],q[t]);
		if (!w) t--;
		if (w!=q[t]){
			T1.add(q[t],w);
			T1.add(w,q[t]);
			p[++cntP]=q[t]=w;
		} 
		q[++t]=p[i];
	}
	for (int i=1;i<t;i++)
		T1.add(q[i],q[i+1]),
		T1.add(q[i+1],q[i]);
	for (int i=1;i<=cnte;i++)
		T1.add(x[i],y[i]),T1.add(y[i],x[i]);
	for (int i=1;i<=cntP;i++)
		if (!T1.dfn[p[i]]) T1.tarjan(p[i],0);
	bool ok=1;
	for (int i=1;i<cntv;i++)
		if (T1.be[z[i]]!=T1.be[z[i+1]])
			ok=0;
	puts(ok?"YES":"NO");
	if (ok) tg=(tg+id)%n;
	for (int i=1;i<=cntP;i++)
		T1.dfn[p[i]]=T1.low[p[i]]=T1.head[p[i]]=0;
	T1.init();
}
int main(){
	init();
	memset(T1.head,0,sizeof(T1.head));
	memset(T1.dfn,0,sizeof(T1.dfn));
	memset(T1.low,0,sizeof(T1.low));
	T1.init(); 
	for (int i=1;i<=cases;i++)
		solve(i);
}