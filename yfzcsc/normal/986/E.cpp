#include<bits/stdc++.h>
#define maxn 100100
#define mod 1000000007
#define maxm 10010000
using namespace std;
typedef pair<int,int> pii;
int cnt[maxm],nxt[maxm],psz,pri[maxm/10],vis[maxm];
int n,a[maxn],fa[maxn],Q,anses[maxn],dep[maxn],top[maxn],son[maxn];
vector<int>G[maxn];
vector<pii>wxh[maxn];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int dfs1(int u){
	int s=0,sz=1,mxsize=0;
	for(auto p:G[u])if(p!=fa[u]){
		fa[p]=u,dep[p]=dep[u]+1;
		s=dfs1(p),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=p;
	}
	return sz;
}
void dfs2(int u,int tp){
	top[u]=tp;
	if(son[u])dfs2(son[u],tp);
	for(auto p:G[u])if(p!=fa[u]&&p!=son[u])
		dfs2(p,p);
}
int lca(int u,int v){
	while(top[u]!=top[v])
		dep[top[u]]<dep[top[v]]?v=fa[top[v]]:u=fa[top[u]];
	return dep[u]<dep[v]?u:v;
}
void dfs3(int u){
	for(int i=a[u];i>1;){
		int j=1,z=nxt[i];
//		printf("{%d,%d}",i,nxt[i]);
		while(i%z==0)i/=z,j*=z;
		cnt[j]++;
	}
	for(auto O:wxh[u]){
		int fac=1;
		for(int i=O.second;i>1;){
			int j=1,z=nxt[i],s=0,p=0;
			while(i%z==0){
				i/=z,j*=z,p++;
				s+=p*cnt[j];
			}
			while(1ll*j*z<=10000000)
				j*=z,s+=p*cnt[j];
			fac=1ll*fac*qpow(z,s)%mod;
//			printf("{%d,%d,%d}\n",O.first,z,s);
		}
		if(O.first<0)fac=qpow(fac,mod-2);
		anses[abs(O.first)]=1ll*anses[abs(O.first)]*fac%mod;
	}
	for(auto p:G[u])if(p!=fa[u])
		dfs3(p);
	
	for(int i=a[u];i>1;){
		int j=1,z=nxt[i];
		while(i%z==0)i/=z,j*=z;
		cnt[j]--;
	}
}
int main(){
	int M=1e7+2;
	for(int i=2;i<=M;++i){
		if(!vis[i])pri[++psz]=i,nxt[i]=i;
		for(int j=1;j<=psz&&pri[j]*i<=M;++j){
			nxt[i*pri[j]]=pri[j],vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	dfs1(1),dfs2(1,1);
	scanf("%d",&Q);
	for(int i=1,u,v,lc,flc,x;i<=Q;++i){
		scanf("%d%d%d",&u,&v,&x);
		lc=lca(u,v);
		wxh[lc].push_back(pii(-i,x));
		wxh[fa[lc]].push_back(pii(-i,x));
		wxh[u].push_back(pii(i,x));
		wxh[v].push_back(pii(i,x));
		anses[i]=1;
	}
	dfs3(1);
	for(int i=1;i<=Q;++i)printf("%d\n",anses[i]);
}