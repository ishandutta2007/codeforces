#include<bits/stdc++.h>
#define N 200005
using namespace std;
int h[N],nxt[N],Fa[N],g[N];
int s[N],E[N][3],fa[N][20];
int dep[N],d[N],f[N],n,m;
vector<int> q[N];
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=17;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	for (int i=17;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0]; 
}
int get(int x){
	int m=1; d[1]=x;
	for (;Fa[x]>0;d[++m]=x=Fa[x]);
	for (int i=m-1;i;i--) Fa[d[i]]=d[m],g[d[i]]+=g[d[i+1]];
	return d[m];
}
int main(){
	scanf("%d%d",&n,&m);
	dep[1]=1;
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i][0]);
		nxt[i]=h[fa[i][0]];
		h[fa[i][0]]=i;
		dep[i]=dep[fa[i][0]]+1;
	}
	for (int j=1;j<18;j++)
		for (int i=1;i<=n;i++)	
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&E[i][0],&E[i][1],&E[i][2]);
		q[lca(E[i][0],E[i][1])].push_back(i);
	}
	for (int i=n;i;i--){
		for (int j=0;j<q[i].size();j++){
			int k=q[i][j],x=get(E[k][0]),y=get(E[k][1]),v=E[k][2];
			if (y!=i) v+=-f[y]+s[E[k][1]]+g[E[k][1]];
			if (x!=i) v+=-f[x]+s[E[k][0]]+g[E[k][0]];
			f[i]=max(f[i],v);
		}
		for (int j=h[i];j;j=nxt[j])
			s[i]+=f[j],Fa[j]=i;
		f[i]+=s[i];
		for (int j=h[i];j;j=nxt[j])
			g[j]+=s[i]-f[j];
	}
	printf("%d",f[1]);
}