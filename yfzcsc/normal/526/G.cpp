#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn=2e5+10;
const ll inf=1e18;
vector<pii>G[maxn];
int n,Q;
struct YuYuYu{
	vector<int> v;
	ll dep[maxn],mxd[maxn],sum[maxn],mn[maxn],pval[maxn];
	int tim,fa[20][maxn],col[maxn],rt,son[maxn],prew[maxn],top[maxn];
	void dfs(int u,int f){
		ll mx=0;
		fa[0][u]=f;
		for(auto v:G[u])if(v.first!=f){
			dep[v.first]=dep[u]+v.second;
			prew[v.first]=v.second;
			dfs(v.first,u);
			if(mxd[v.first]+v.second>mx)
				mx=mxd[v.first]+v.second,son[u]=v.first;
		}
		mxd[u]=mx;
	}
	void dfs2(int u,int tp,ll mnans){
		top[u]=tp;
		mn[u]=mnans;
		if(son[u])dfs2(son[u],tp,mnans);
		for(auto v:G[u])if(v.first!=fa[0][u]&&v.first!=son[u])
			dfs2(v.first,v.first,max(mnans,-pval[top[u]]+dep[u]-dep[fa[0][top[u]]]));
	}
	void init(int R){
		rt=R,dfs(rt,0);
		for(int i=1;i<=n;++i)
			pval[i]=mxd[i]+prew[i];
		dfs2(rt,rt,(ll)-1e18);
		for(int i=1;i<=n;++i)if(!son[i])
			v.push_back(i);
		sort(v.begin(),v.end(),[&](int x,int y){
			return pval[top[x]]>pval[top[y]];
		});
		tim=0;
		for(auto a:v)
			for(++tim,sum[tim]=sum[tim-1]+pval[top[a]];!col[a];a=fa[0][a])
				col[a]=tim;
//		for(int i=1;i<=tim;++i)printf("{%lld}",sum[i]);
		for(int i=1;n>>i;i++)for(int j=1;j<=n;++j)
			fa[i][j]=fa[i-1][fa[i-1][j]];
	}
	ll ask(int x,int y){
		y=2*y-1;
		if(tim<=y)return sum[tim];
		ll ans=sum[y];
//		printf("{%d,%d(%lld)}",col[x],y,ans);
		if(col[x]>y){
			int nw=x;
			for(int i=19;i>=0;--i)if(fa[i][nw]&&col[fa[i][nw]]>y)
				nw=fa[i][nw];
//			printf("[%lld(%d)]",mn[nw],rt);
			ans+=max(-pval[top[v[y-1]]],mn[nw]);
			ans+=dep[x]-dep[fa[0][nw]]+mxd[x];
		}
		return ans;
	}
}A,B;
pii getfar(int x,int f){
	pii ret(0,x);
	for(auto v:G[x])if(v.first!=f){
		pii nret=getfar(v.first,x);
		nret.first+=v.second;
		ret=max(ret,nret);
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&Q);
	for(int i=2,u,v,w;i<=n;++i){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(pii(v,w));
		G[v].push_back(pii(u,w));
	}
	pii pA=getfar(1,0);
	pii pB=getfar(pA.second,0);
	A.init(pA.second);
	B.init(pB.second);
	ll lst=0;
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+lst-1)%n+1;
		y=(y+lst-1)%n+1;
//		printf("{%d,%d}",x,y);
		ll ans=max(A.ask(x,y),B.ask(x,y));
		printf("%lld\n",lst=ans);
	}
}