#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1<<19;
char c[N];int n,T[M*2|5];
inline void mdy(int x,int v){for(T[x+=M]=v;x>>=1;T[x]=max(T[x<<1],T[x<<1|1]));}
inline int ask(int l,int r){
	int ans=0;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if(!(l&1))ans=max(ans,T[l^1]);
		if(r&1)ans=max(ans,T[r^1]);
	}
	return ans;
}
struct SAM{
	static const int N=::N*2;
	int ch[N][26],pre[N],step[N],xb,n,wz[N],pos[N],anc[20][N],f[N];
	inline void build(){
		int p,q,np,nq,lst=xb=1,i,x;
		memset(ch[1],0,104);
		for(i=1;c[i];++i){
			x=c[i]-'a';step[np=++xb]=step[p=lst]+1;
			memset(ch[np],0,104);
			for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
			if(p){
				q=ch[p][x];
				if(step[p]+1!=step[q]){
					step[nq=++xb]=step[p]+1;
					memcpy(ch[nq],ch[q],104);
					pre[nq]=pre[q];pre[q]=pre[np]=nq;
					for(;p && ch[p][x]==q;p=pre[p])ch[p][x]=nq;
				}else pre[np]=q;
			}else pre[np]=1;
			wz[pos[lst=np]=i]=np;
		}n=i-1;
	}
	int id[N],ri[N],dfn[N],cn;
	std::vector<int>e[N];
	void dfs(int x){
		dfn[id[x]=++cn]=x;
		for(int i=0;i<e[x].size();++i)dfs(e[x][i]);
		ri[x]=cn;
	}
	inline void calc(int i,int zz){
		int u=i;
		for(int j=19;j>=0;--j){
			int x=anc[j][u];
			if(x && ask(id[x],ri[x])-step[x]+1<zz-step[i]+1)u=x;
		}
		f[i]=f[pre[u]]+1;
if(i==47)
++i,--i;
	}
	inline void work(){
		int i,j,ans=0;
		build();
		for(i=1;i<=xb;++i)e[pre[i]].push_back(i);
		dfs(1);
		memcpy(anc[0]+1,pre+1,xb<<2);for(i=1;i<20;++i)for(j=1;j<=xb;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
		for(i=1;i<=n;++i){
			static int st[N],cov[N];int x=wz[i],w=0;
			for(;x>1 && !cov[x];x=pre[x])st[++w]=x,cov[x]=1;
			for(;w;)calc(st[w--],i);mdy(id[wz[i]],i);
		}
		for(i=1;i<=xb;++i)ans=max(ans,f[i]);
		printf("%d\n",ans);
	}
}S;
int main(){
	scanf("%d%s",&n,c+1);
	S.work();
	return 0;
}