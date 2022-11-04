#include<bits/stdc++.h>
using namespace std;
const int mo=1000000007;
const int N=100005;
struct node{
	int sum2,sum,cnt;
	node operator +(const node &a)const{
		return (node){(sum2+a.sum2)%mo,(sum+a.sum)%mo,(cnt+a.cnt)%mo};
	}
	node operator -(const node &a)const{
		return (node){(sum2+mo-a.sum2)%mo,(sum+mo-a.sum)%mo,(cnt+mo-a.cnt)%mo};
	}
	node operator +(const int a)const{
		node tmp;
		tmp.cnt=cnt;
		tmp.sum=(sum+1ll*cnt*a)%mo;
		tmp.sum2=(sum2+2ll*sum*a+1ll*cnt*a%mo*a)%mo;
		return tmp;	
	}
}f[N],g[N],fav[N];
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot;
int d[N],fa[N][20];
int dep[N],n,q;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dfs1(int x){
	f[x].cnt=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=(dep[x]+e[i].v)%mo;
			d[e[i].to]=d[x]+1;
			dfs1(e[i].to);
			f[x]=f[x]+(f[e[i].to]+e[i].v);
		}
}
void dfs2(int x){
	g[x]=f[x]+fav[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			node tmp=g[x]-(f[e[i].to]+e[i].v);
			fav[e[i].to]=tmp+e[i].v;
			dfs2(e[i].to);
		}
}
int LCA(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	int tmp=d[x]-d[y];
	for (int i=0;i<=18;i++)	
		if (tmp&(1<<i)) x=fa[x][i];
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return (x==y?x:fa[x][0]);
}
int dis(int x,int y){
	return (dep[x]+dep[y]+2ll*mo-2*dep[LCA(x,y)])%mo;
}
bool checkfa(int x,int y){
	return LCA(x,y)==x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs1(1); g[1]=f[1]; dfs2(1);
	for (int i=1;i<=18;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (checkfa(y,x)){
			node ans=g[x];
			node ans2=fav[y];
			ans=ans-(ans2+dis(x,y));
			printf("%d\n",(2ll*ans.sum2+mo-g[x].sum2)%mo);
		}
		else{
			node ans=f[y];
			ans=ans+dis(x,y);
			printf("%d\n",(2ll*ans.sum2+mo-g[x].sum2)%mo);
		}
	}
}