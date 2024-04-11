#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,C,ans,T;
int a[N][N],b[N][N];
int dfn[N],low[N],vis[N];
int S[N],G[N],f[N],be[N];
void tarjan(int x,int fa){
	dfn[x]=low[x]=++T;
	vis[x]=1; S[++*S]=x;
	for (int i=1;i<=n;i++)
		if (a[x][i]&&i!=fa){
			if (!dfn[i]){
				tarjan(i,x);
				low[x]=min(low[x],low[i]);
			}
			else if (vis[i])
				low[x]=min(low[x],dfn[i]);
		}
	if (dfn[x]==low[x]){
		C++;
		do{
			be[S[*S]]=C; G[C]++;
			vis[S[*S]]=0;
		}while (S[(*S)--]!=x);
	}
}
int fa[N];
void dfs1(int x,int fa){
	for (int i=1;i<=C;i++)
		if (b[x][i]&&i!=fa){
			::fa[i]=x; dfs1(i,x);
			S[x]+=S[i]+G[i];
			f[x]+=f[i];
		}
	f[x]+=G[x]*S[x];
}
void dfs2(int x,int fa){
	for (int i=1;i<=C;i++)
		if (b[x][i]&&i!=fa){
			f[i]=f[x]-G[x]*(S[i]+G[i])+G[i]*(n-S[i]-G[i]);
			dfs2(i,x);
		}
}
bool v[N];
int work(int x){
	memset(v,0,sizeof(v)); v[0]=1;
	for (int i=1;i<=C;i++)
		if (b[x][i]){
			int cnt=(i==fa[x]?n-G[x]-S[x]:G[i]+S[i]);
			for (int wzp=n-G[x];wzp>=cnt;wzp--) v[wzp]|=v[wzp-cnt];
		}
	int ans=0;
	for (int i=0;i<=n-G[x];i++)
		if (v[i]) ans=max(ans,i*(n-G[x]-i));
	return ans+f[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	tarjan(1,0);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]&&be[i]!=be[j])
				b[be[i]][be[j]]=1;
	memset(S,0,sizeof(S));
	dfs1(be[1],0); dfs2(be[1],0);
	for (int i=1;i<=C;i++)
		ans=max(ans,work(i));
	for (int i=1;i<=C;i++)
		ans+=G[i]*G[i];
	printf("%d",ans);
}