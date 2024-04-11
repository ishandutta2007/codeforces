#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int sz[N],dep[N],fa[N];
int top[N],dfn[N];
vector<int> e[N];
int n,Q,T;
void dfs1(int x){
	sz[x]=1;
	for (int i=0;i<e[x].size();i++){
		dep[e[x][i]]=dep[x]+1;
		dfs1(e[x][i]);
		sz[x]+=sz[e[x][i]]; 
	}
}
void dfs2(int x,int tp){
	top[x]=tp; dfn[x]=++T;
	int k=0;
	for (int i=0;i<e[x].size();i++)
		if (sz[e[x][i]]>sz[k])
			k=e[x][i];
	if (k) dfs2(k,tp);
	for (int i=0;i<e[x].size();i++)
		if (e[x][i]!=k)
			dfs2(e[x][i],e[x][i]);
}
int lca(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
int v[N],q[N],id[N];
int f[N],tg[N],vis[N];
int b[N],d[N],sum[N],sta[N];
int fa2[N],cnt[1005][1005];
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=2;i<=n;i++)
		scanf("%d",&fa[i]),e[fa[i]].push_back(i);
	for (int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for (int i=1;i<=Q;i++)
		scanf("%d",&q[i]);
	dfs1(1); dfs2(1,1);
	int blk=(int)(sqrt(Q)+1e-9);
	int t=1; id[1]=1;
	for (int h=1;h<=t;h++)
		for (int i=0;i<e[id[h]].size();i++)
			id[++t]=e[id[h]][i];
	for (int i=0;i<=Q/blk;i++){
		int lbd=i*blk+1,rbd=min(Q,(i+1)*blk);
		for (int j=1;j<=n;j++) f[j]=tg[j]=vis[j]=0;
		int ans=0,tp=0,tp2=0;
		for (int j=1;j<lbd;j++){
			vis[abs(q[j])]^=1;
			f[abs(q[j])]+=(q[j]>0?1:-1);
		}
		for (int j=n;j>=1;j--){
			int x=id[j];
			ans+=(!vis[x]&&f[x]>v[x]);
			f[fa[x]]+=f[x];
		}
		for (int j=lbd;j<=rbd;j++)
			b[++tp]=abs(q[j]);
		sort(b+1,b+tp+1,cmp);
		for (int j=1,k=tp;j<k;j++)
			b[++tp]=lca(b[j],b[j+1]);
		sort(b+1,b+tp+1,cmp);
		int id=0;
		for (int j=1,las=0;j<=tp;j++)
			if (las!=b[j]||j==1){
				for (;tp2&&lca(sta[tp2],b[j])!=sta[tp2];tp2--);
				fa2[b[j]]=sta[tp2]; sta[++tp2]=b[j];
				tg[b[j]]=1; d[las=b[j]]=++id; b[id]=las;
			}
		for (int j=1;j<=id;j++){
			sum[j]=0;
			for (int k=-blk;k<=blk;k++)
				cnt[j][k+blk]=0;
			for (int k=fa[b[j]];k&&!tg[k];k=fa[k])
				if (abs(f[k]-v[k]-1)<=blk&&!vis[k])
					cnt[j][f[k]-v[k]-1+blk]++;
			for (int k=blk-1;k>=-blk;k--)
				cnt[j][k+blk]+=cnt[j][k+blk+1];
		}
		for (int j=lbd;j<=rbd;j++){
			int x=abs(q[j]),tp=(q[j]>0?1:-1);
			for (;x;x=fa2[x]){
				ans-=(!vis[x]&&f[x]>v[x]);
				f[x]+=tp; vis[x]^=(x==abs(q[j])?1:0);
				ans+=(!vis[x]&&f[x]>v[x]);
				ans-=cnt[d[x]][-sum[d[x]]+blk];
				sum[d[x]]+=tp;
				ans+=cnt[d[x]][-sum[d[x]]+blk];
			}
			printf("%d ",ans);
		}
	}
}