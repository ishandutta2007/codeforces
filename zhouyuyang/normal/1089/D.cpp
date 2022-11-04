#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005;
vector<int> e[N];
vector<pii> spe;
int sz[N],q[N],vis[N],dfn[N];
int deg[N],fa[N][18],dep[N];
int id[N],pos[N],up[N],dn[N];
int d[305][305],pos2[N],n,m;
ll ans,S1[N],S2[N];
void solve_leaf(){
	int h=0,t=0;
	For(i,1,n) sz[i]=1;
	For(i,1,n) if (deg[i]==1) q[++t]=i,vis[i]=1;
	while (h!=t){
		int x=q[++h];
		if (h!=n) ans+=2ll*sz[x]*(n-sz[x]);
		for (auto i:e[x]) if (!vis[i]){
			if (--deg[i]) sz[i]+=sz[x];
			if (deg[i]==1) q[++t]=i,vis[i]=1;
		}
	}
}
void dfs(int x){
	vis[x]+=2;
	for (auto i:e[x])
		if (i!=fa[x][0]&&!(vis[i]&1))
			if (vis[i]==2){
				if (dep[x]<dep[i])
					spe.PB(pii(x,i));
			}
			else{
				fa[i][0]=x;
				dep[i]=dep[x]+1;
				dfs(i);
			}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,16,0) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,16,0) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void insert_spe(int x){
	if (id[x]) return;
	id[x]=++*id;
	pos[*id]=x;
}
int dfs2(int x,int tp){
	dfn[x]=++*dfn;
	pos2[*dfn]=x;
	S1[*dfn]=sz[x];
	S2[*dfn]=1ll*sz[x]*dep[x];
	vis[x]+=2; up[x]=id[tp];
	for (auto i:e[x])
		if (i!=fa[x][0]&&!vis[i])
			dn[x]=dfs2(i,id[x]?x:tp);
	if (id[x]) dn[x]=id[x];
	return dn[x];
}
int DIV2(int x){
	return x>=0?x/2:-((-x+1)/2);
}
ll solvepth(int v1,int v2,int p1,int p2){
	int len=p1-p2;
	int p=max(-1,min(len,DIV2(v2+len-v1)));
	ll ans=1ll*v1*(S1[p1]-S1[p1-p-1]);
	ans+=1ll*v2*(S1[p1-p-1]-S1[p2-1]);
	ans+=1ll*dep[pos2[p1]]*(S1[p1]-S1[p1-p-1])-(S2[p1]-S2[p1-p-1]);
	ans+=(S2[p1-p-1]-S2[p2-1])-1ll*dep[pos2[p2]]*(S1[p1-p-1]-S1[p2-1]);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
		deg[x]++; deg[y]++;
	}
	solve_leaf();
	int rt=0;
	For(i,1,n)
		if (!vis[i]){
			rt=i;
			break;
		}
	dfs(rt);
	For(i,1,16) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	For(i,1,n) vis[i]&=1;
	insert_spe(rt);
	for (auto i:spe){
		insert_spe(i.fi);
		insert_spe(i.se);
		For(j,1,*id){
			insert_spe(LCA(pos[j],i.fi));
			insert_spe(LCA(pos[j],i.se));
		}
	}
	dfs2(rt,rt);
	For(i,1,n){
		S1[i]+=S1[i-1];
		S2[i]+=S2[i-1];
	}
	memset(d,50,sizeof(d));
	For(i,1,*id)
		if (pos[i]!=rt)
			d[i][up[pos[i]]]=d[up[pos[i]]][i]=dep[pos[i]]-dep[pos[up[pos[i]]]];
	for (auto i:spe)
		d[id[i.fi]][id[i.se]]=d[id[i.se]][id[i.fi]]=1;
	For(i,1,*id) d[i][i]=0;
	For(k,1,*id) For(i,1,*id) For(j,1,*id)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	For(i,1,n) if (!(vis[i]&1)){
		int x=dn[i],y=up[i];
		if (i!=1){
			int v2=dep[i]-dep[pos[y]]+d[y][x];
			ans+=1ll*sz[i]*solvepth(v2,0,dfn[pos[x]],dfn[i]);
			int v1=dep[pos[x]]-dep[i]+d[x][y]+1;
			ans+=1ll*sz[i]*solvepth(0,v1,dfn[i],dfn[i]-(dep[i]-dep[pos[y]])+1);
		}
		For(j,1,*id) if (j!=dn[i])
			if (pos[j]==rt){
				int v1=dep[pos[x]]-dep[i]+d[x][j];
				int v2=dep[i]-dep[pos[y]]+d[y][j];
				ans+=1ll*sz[i]*sz[pos[j]]*min(v1,v2);
			}
			else{
				int J=up[pos[j]];
				int v1=min(dep[pos[x]]-dep[i]+d[x][j],dep[i]-dep[pos[y]]+d[y][j]);
				int v2=min(dep[pos[x]]-dep[i]+d[x][J],dep[i]-dep[pos[y]]+d[y][J])+1;
				ans+=1ll*sz[i]*solvepth(v1,v2,dfn[pos[j]],dfn[pos[j]]-(dep[pos[j]]-dep[pos[J]])+1);
			}
	}
	printf("%lld\n",ans/2);
}