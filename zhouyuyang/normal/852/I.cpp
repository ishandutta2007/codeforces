#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
struct que{int l,r,id,lc;}q[N];
int head[N],fa[N][20],dep[N];
int dfn[N],st[N],en[N],bl[N];
int f[N],b[N],in[N],num[N];
int cntb[N],cntg[N];
long long now,ans[N];
int n,tot,T;
bool cmp(que x,que y){
	if (bl[x.l]==bl[y.l])
		return x.r<y.r;
	return bl[x.l]<bl[y.l];
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	st[x]=++T; dfn[T]=x;
	for (int i=1;i<=17;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
	en[x]=++T; dfn[T]=x;
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=0;i<=17;i++,tmp/=2)
		if (tmp&1) x=fa[x][i];
	for (int i=17;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
void work(int x){
	int v=f[x];
	if (!in[x]){
		if (b[x]) now+=cntg[v],cntb[v]++;
		else now+=cntb[v],cntg[v]++;
	}
	else{
		if (b[x]) now-=cntg[v],cntb[v]--;
		else now-=cntb[v],cntg[v]--;
	}
	in[x]^=1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&f[i]),num[i]=f[i];
	sort(num+1,num+n+1);
	for (int i=1;i<=n;i++)
		f[i]=lower_bound(num+1,num+n+1,f[i])-num;
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	int sz=1375;
	for (int i=1;i<=T;i++)
		bl[i]=(i-1)/sz+1;
	int Q; scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		int x,y; scanf("%d%d",&x,&y);
		if (st[x]>st[y]) swap(x,y);
		q[i]=(que){st[x]+1,st[y],i,lca(x,y)};
	}
	sort(q+1,q+Q+1,cmp);
	int l=1,r=0;
	for (int i=1;i<=Q;i++){
		for (;r<q[i].r;work(dfn[++r]));
		for (;r>q[i].r;work(dfn[r--]));
		for (;l<q[i].l;work(dfn[l++]));
		for (;l>q[i].l;work(dfn[--l]));
		work(q[i].lc);
		ans[q[i].id]=now;
		work(q[i].lc);
	}
	for (int i=1;i<=Q;i++)
		printf("%I64d\n",ans[i]);
}