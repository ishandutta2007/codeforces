#include<bits/stdc++.h>
using namespace std;
#define mod1 1000000007
#define mod2 1000000009
#define base1 19260817
#define base2 20010911
#define maxn 201000
#define maxs 10100000
#define SIZE 11009989
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
ull pw[maxn],_pw[maxn];
struct Data{
	int len,id;
	ull h;
};
struct hash_table{
	int head[11009990],nxt[maxs],p[maxs],ptr;
	ull d[maxs];
	void add(ull x,int a){
		int z=x%SIZE;
		for(int t=head[z];t;t=nxt[t])
			if(d[t]==x){p[t]+=a;return ;}
		nxt[++ptr]=head[z],head[z]=ptr;
		p[ptr]+=a,d[ptr]=x;
	}
	int find(ull x){
		int z=x%SIZE;
		for(int t=head[z];t;t=nxt[t])
			if(d[t]==x)return p[t];
		return 0;
	}
}st;
int anses[maxn],prec[maxn],dep[maxn],fa[21][maxn],n,m;
vector<pii>G[maxn];
vector<Data>Q[maxn];
void dfs(int u,int f){
	fa[0][u]=f;
	for(auto c:G[u])if(c.first!=f){
		dep[c.first]=dep[u]+1;
		pw[c.first]=pw[u]*(base1)+(c.second);
		prec[c.first]=c.second;
		dfs(c.first,u); 
	}
}
ull get(int l,int r){
	return pw[l]-pw[r]*_pw[dep[l]-dep[r]];
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;d>>i;i++)if(d>>i&1)u=fa[i][u];
	if(u==v)return u;
	for(int i=19;i>=0;--i)if(fa[i][u]^fa[i][v])
		u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
int jmp(int u,int d){
	for(int i=0;d>>i;i++)if(d>>i&1)u=fa[i][u];
	return u;
}
ull geth(char* s){
	ull ret=0;
	for(int i=0;s[i];i++)
		ret=ret*(base1)+(s[i]);
	return ret;
}
int kmp(char* t,char* s){
	static int f[maxn];
//	printf("[%s,%s]\n",t,s);
	int n=max(strlen(s),strlen(t)),ns=strlen(s);
	for(int i=0;i<n;++i)f[i]=0;
	f[0]=-1;
	for(int i=1;s[i];i++){
		int j=f[i-1];
		while(j!=-1&&s[j+1]!=s[i])j=f[j];
		if(s[j+1]==s[i])j++;
		f[i]=j;
	}
	int ans=0;
	for(int i=0,x=-1;t[i];i++){
		while(x!=-1&&s[x+1]!=t[i])x=f[x];
		if(s[x+1]==t[i])x++;
		if(x==ns-1)ans++;
	}
	return ans;
}
void dfs2(int u,int f){
	for(int i=1,x=f;i<=100&&x;i++){
		st.add(get(u,x),1);
//		printf("[%d,%d]=%llu\n",u,x,get(u,x));
		x=fa[0][x];
	}
	for(auto c:Q[u])
		anses[abs(c.id)]+=(c.id>0?1:-1)*st.find(c.h);
	for(auto c:G[u])if(c.first!=f)
		dfs2(c.first,u);
	for(int i=1,x=f;i<=100&&x;i++)
		st.add(get(u,x),-1),x=fa[0][x];
}
int main(){
	scanf("%d",&n);
	_pw[0]=(1);
	for(int i=1;i<=n;++i)_pw[i]=_pw[i-1]*(base1);
	for(int i=2,u,v;i<=n;++i){
		char s[2];
		scanf("%d%d%s",&u,&v,s);
		G[u].push_back(pii(v,s[0]));
		G[v].push_back(pii(u,s[0]));
	}
	dfs(1,0);
	for(int i=1;i<20;++i)
		for(int j=1;j<=n;++j)
			fa[i][j]=fa[i-1][fa[i-1][j]];
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;++i){
		char s[200],t[300];
		int tp=0;
		scanf("%d%d%s",&u,&v,s);
		int lc=lca(u,v),len=strlen(s);
		int zu=jmp(u,max(0,dep[u]-dep[lc]-len));
		int zv=jmp(v,max(0,dep[v]-dep[lc]-len));
//		printf("[%d,%d(%d,%d),%d]",lc,zu,u,dep[u]-dep[lc]-len,zv);
		Q[zv].push_back(Data{len,-i,geth(s)});
		Q[v].push_back(Data{len,i,geth(s)});
//		printf("{%d,%d}",zu,u);
		reverse(s,s+len);
		Q[zu].push_back(Data{len,-i,geth(s)});
		Q[u].push_back(Data{len,i,geth(s)});
		reverse(s,s+len);
		while(zu!=lc)t[tp++]=prec[zu],zu=fa[0][zu];
		int xp=tp;
		while(zv!=lc)t[tp++]=prec[zv],zv=fa[0][zv];
		reverse(t+xp,t+tp);
		t[tp]=0;
		anses[i]=kmp(t,s);
	}
	dfs2(1,0);
	for(int i=1;i<=m;++i)printf("%d\n",anses[i]);
}