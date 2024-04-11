#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
typedef pair<int,int> pii;
typedef long long ll;
int n,q,len[maxn],fa[21][maxn],L[maxn],R[maxn];
vector<pii>G[maxn];
ll dep[maxn],lef[21][maxn],rig[21][maxn],mn[21][maxn],mndep[maxn];
void dfs(int u){
	L[u]=R[u]=u;
	if(!G[u].size())mndep[u]=dep[u],mn[0][u]=dep[u];
	else mndep[u]=1e18,mn[0][u]=1e18;
	ll z=1e18;
	for(auto v:G[u]){
		dep[v.first]=v.second+dep[u];
		dfs(v.first);
		mndep[u]=min(mndep[v.first],mndep[u]);
		R[u]=R[v.first];
	}
	for(int i=0;i<G[u].size();++i){
		auto v=G[u][i];
		lef[0][v.first]=z-2*dep[u];
		z=min(z,mndep[v.first]);
	}
	z=1e18;
	for(int i=G[u].size()-1;i>=0;--i){
		auto v=G[u][i];
		rig[0][v.first]=z-2*dep[u];
		z=min(z,mndep[v.first]);
	}
}
ll cal(int x,int l,int r){
	l=max(l,L[x]);
	r=min(r,R[x]);
	if(l>r)return 1e18;
	int z=len[r-l+1];
	return min(mn[z][l],mn[z][r-(1<<z)+1]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2,u,w;i<=n;++i){
		scanf("%d%d",&u,&w);
		G[u].push_back(pii(i,w));
		fa[0][i]=u;
	}
	for(int i=1;i<=n;++i){
		while((1<<len[i]+1)<=i)len[i]++;
		sort(G[i].begin(),G[i].end()); 
	}
	dfs(1);
//	return 0;
	for(int i=1;i<=20;++i)
		for(int j=1;j<=n;++j){
			fa[i][j]=fa[i-1][fa[i-1][j]];
			lef[i][j]=min(lef[i-1][j],lef[i-1][fa[i-1][j]]);
			rig[i][j]=min(rig[i-1][j],rig[i-1][fa[i-1][j]]);
			if((j+(1<<i-1))<=n)mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
		}
	for(int i=1;i<=q;++i){
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		if(!G[x].size()&&x>=l&&x<=r){
			puts("0");
			continue;
		}
		ll ans=1e18;
		ll sum=0;
		int y=x;
		for(int i=20;i>=0;--i)if(fa[i][y]){
			int u=fa[i][y];
			if(L[u]>r||R[u]<l){
				y=fa[i][y];
			}
		}
		if(L[y]>r||R[y]<l)y=fa[0][y];
		sum=dep[x]-dep[y];
		x=y;
//		printf("<%d>",x);
		ans=min(ans,-dep[x]+cal(x,l,r));
		
//		printf("[%lld]",ans);
		for(int i=20;i>=0;--i)if(fa[i][y]){
			int u=fa[i][y];
			if(l<=L[u]){
				ans=min(ans,dep[x]+lef[i][y]);
				y=u;
			}
		}
		if(fa[0][y]){
			y=fa[0][y];
			ans=min(ans,-dep[y]*2+dep[x]+cal(y,l,r));
		}
//		printf("[%lld]",ans);
		y=x;
		for(int i=20;i>=0;--i)if(fa[i][y]){
			int u=fa[i][y];
			if(R[u]<=r){
				ans=min(ans,dep[x]+rig[i][y]);
				y=u;
			}
		}
		if(fa[0][y]){
			y=fa[0][y];
			ans=min(ans,-dep[y]*2+dep[x]+cal(y,l,r));
		}
		printf("%lld\n",ans+sum);
	}
}