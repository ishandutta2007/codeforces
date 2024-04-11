#include <cstdio>
const int harry=998244353,N=200010;
int T,n,u,v,a,b,p,cnt,dnt,fans,prd[N],head[N],to[2*N],ra[2*N],rb[2*N],next[2*N],inv[N],prm[N],ftr[N],bkt[N],ans[N];
bool dpr[N],vis[N];
inline int max(int x,int y){return x>y?x:y;}
inline void addedge(int u,int v,int a,int b){++dnt,next[dnt]=head[u],head[u]=dnt,to[dnt]=v,ra[dnt]=a,rb[dnt]=b;}
void inc(int x){
	while(x!=1){
		++bkt[ftr[x]];
		ans[ftr[x]]=max(ans[ftr[x]],bkt[ftr[x]]),x/=ftr[x];
	}
}
void dec(int x){
	while(x!=1){
		--bkt[ftr[x]];
		x/=ftr[x];
	}
}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=(long long)nw*nw%harry)if(rm&pw)rm^=pw,rs=(long long)rs*nw%harry;
	return rs;
}
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		prd[to[i]]=(long long)prd[u]*inv[ra[i]]%harry*rb[i]%harry,dec(rb[i]),inc(ra[i]),dfs(to[i]),dec(ra[i]),inc(rb[i]);
	}
}
int main(){
	scanf("%d",&T),inv[1]=1;
	for(int i=2;i<=N;++i){
		inv[i]=qpow(i,harry-2);
		if(!dpr[i])ftr[i]=i,prm[++cnt]=i;
		for(int j=1;j<=cnt&&i*prm[j]<=N;++j){
			dpr[i*prm[j]]=true,ftr[i*prm[j]]=prm[j];
			if(i%prm[j]==0)break;
		}
	}
	while(T--){
		scanf("%d",&n),dnt=0;
		for(int i=1;i<=n;++i)vis[i]=false,head[i]=next[(i<<1)-1]=next[i<<1]=0;
		for(int i=2;i<=n;++i)scanf("%d %d %d %d",&u,&v,&a,&b),addedge(u,v,a,b),addedge(v,u,b,a);
		fans=0,prd[1]=1,dfs(1),p=1;
		for(int i=1;i<=n;++i)while(ans[i])p=(long long)p*i%harry,--ans[i];
		for(int i=1;i<=n;++i)fans+=(long long)prd[i]*p%harry,fans%=harry;
		printf("%d\n",fans);
	}
	return 0;
}