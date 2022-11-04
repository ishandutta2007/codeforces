#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{
	int to,next;
}e[N];
int head[N],tot,T;
int dfn[N],las[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int dfs(int x){
	dfn[x]=++T;
	for (int i=head[x];i;i=e[i].next)
		dfs(e[i].to);
	las[x]=T;
}
int fa[20][N],dep[N];
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=18;i>=0;i--)
		if (tmp&(1<<i)) x=fa[i][x];
	for (int i=18;i>=0;i--)
		if (fa[i][x]!=fa[i][y])
			x=fa[i][x],y=fa[i][y];
	return x==y?x:fa[0][x];
}
int mx[20][N],v[20][N];
int n,m,q,sz,rt[N];
int ls[N*70],rs[N*70],s[N*70];
vector<int> Q[N];
void add(int k,int &nk,int l,int r,int x){
	nk=++sz; s[nk]=s[k]+1;
	ls[nk]=ls[k]; rs[nk]=rs[k]; 
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(ls[k],ls[nk],l,mid,x);
	else add(rs[k],rs[nk],mid+1,r,x);
} 
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return s[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
}
int getf(int x,int v){
	for (int i=18;i>=0;i--)
		if (v&(1<<i)) x=fa[i][x];
	return x;
}
int main(){
	scanf("%d",&n);
	fa[0][1]=dep[1]=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[0][i]);
		add(fa[0][i],i);
		dep[i]=dep[fa[0][i]]+1;
	}
	dfs(1);
	for (int i=1;i<=18;i++)
		for (int j=1;j<=n;j++)
			fa[i][j]=fa[i-1][fa[i-1][j]];
	memset(mx,63,sizeof(mx));
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=lca(x,y);
		int tmp=dep[x]-dep[L]+1;
		Q[dfn[x]].push_back(dfn[y]);
		Q[dfn[y]].push_back(dfn[x]);
		for (int j=18;j>=0;j--)
			if (tmp&(1<<j)){
				mx[j][x]=min(mx[j][x],dep[L]);
				x=fa[j][x];
			}
		tmp=dep[y]-dep[L]+1;
		for (int j=18;j>=0;j--)
			if (tmp&(1<<j)){
				mx[j][y]=min(mx[j][y],dep[L]);
				y=fa[j][y];
			}
	}
	for (int i=1;i<=n;i++){
		rt[i]=rt[i-1];
		for (int j=0;j<Q[i].size();j++)
			add(rt[i],rt[i],1,n,Q[i][j]);
	}
	for (int i=18;i;i--)
		for (int j=1;j<=n;j++){
			mx[i-1][j]=min(mx[i-1][j],mx[i][j]);
			mx[i-1][fa[i-1][j]]=min(mx[i-1][fa[i-1][j]],mx[i][j]);
		}
	for (int i=1;i<=n;i++)
		mx[0][i]=v[0][i]=min(dep[i],mx[0][i]);
	for (int i=1;i<=18;i++){
		for (int j=1;j<=18;j++)
			for (int k=1;k<=n;k++)
				mx[j][k]=min(mx[j-1][k],mx[j-1][fa[j-1][k]]);
		for (int j=1;j<=n;j++){
			int tmp=dep[j]-v[i-1][j]+1;
			v[i][j]=dep[j]; int x=j;
			for (int k=18;k>=0;k--)
				if (tmp&(1<<k)){
					v[i][j]=min(v[i][j],mx[k][x]);
					x=fa[k][x];
				}
		}
		for (int j=1;j<=n;j++)
			mx[0][j]=v[i][j];
	}
	scanf("%d",&q);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=lca(x,y);
		if (v[18][x]>dep[L]||v[18][y]>dep[L]){
			puts("-1"); continue;
		}
		int ans=1;
		if (x==L){
			for (int i=18;i>=0;i--)
				if (v[i][y]>dep[L])
					ans+=(1<<i),y=fa[i][y];
		}
		else if (y==L){
			for (int i=18;i>=0;i--)
				if (v[i][x]>dep[L])
					ans+=(1<<i),x=fa[i][x];
		}
		else{
		   	for (int i=18;i>=0;i--)
				if (v[i][x]>dep[L])
					ans+=(1<<i),x=getf(x,dep[x]-v[i][x]);
			for (int i=18;i>=0;i--)
				if (v[i][y]>dep[L])
					ans+=(1<<i),y=getf(y,dep[y]-v[i][y]);
			if (!(ask(rt[las[x]],1,n,dfn[y],las[y])
				-ask(rt[dfn[x]-1],1,n,dfn[y],las[y])))
					ans++;
		}
		printf("%d\n",ans);
	}
}