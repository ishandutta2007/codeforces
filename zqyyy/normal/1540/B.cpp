#include<cstdio>
#include<cctype>

#define maxn 222
#define mod 1000000007
#define inv2 500000004

template<class T>

inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}

inline long long qpow(long long a,int b){
	long long ans=1;
	for(;b;b>>=1){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
	}
	return ans;
}

struct E{
	int v,nxt;
	E() {}
	E(int v,int nxt):v(v),nxt(nxt) {}
}e[maxn<<1];

int n,s_e,head[maxn];

inline void a_e(int u,int v){
	e[++s_e]=E(v,head[u]);
	head[u]=s_e;
}

int rt,dep[maxn];

long long ans,f[maxn][maxn];

inline int MIN(int a,int b){
	return dep[a]<dep[b]?a:b;
}

void dfsinit(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)continue;
		dfsinit(v,u);
	}
}

void dfs(int u,int fa,int lca){
	if(rt>u)(ans+=f[dep[rt]-dep[lca]][dep[u]-dep[lca]])%=mod;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u,MIN(v,lca));
	}
}

inline void work(int root){
	dfsinit(root,0);
	for(int i=1;i<=n;i++)
		dfs(rt=i,0,i);
}

int main(){
	n=read<int>();
	for(int i=1;i<n;i++){
		int u=read<int>();
		int v=read<int>();
		a_e(u,v),a_e(v,u);
	}
	for(int i=1;i<=n;i++)f[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i-1][j]+f[i][j-1])*inv2%mod;
    for(int i=1;i<=n;i++)work(i);
	printf("%lld\n",ans*qpow(n,mod-2)%mod);
    return 0;
}