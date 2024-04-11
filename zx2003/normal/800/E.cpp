#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,i,j,sz[N],qsz[N],lf[N],rt,fa[N];
vector<int>e[N];
void dfs(int u){
	sz[u]=1;
	if(u<=n){lf[u]=u;return;}
	for(int i=0;i<2;++i)dfs(e[u][i]),sz[u]+=sz[e[u][i]];lf[u]=lf[e[u][0]];
	if(sz[e[u][0]]<sz[e[u][1]])swap(e[u][0],e[u][1]);
	qsz[u]=sz[e[u][1]];
}
inline void ins(int u){fa[n+i-1]=fa[u];fa[u]=fa[i]=n+i-1;}
void solve(int u){
	static int st[N];int w=0,l,r,m,s,ss;
	for(;u>n;u=e[u][0])st[++w]=u;st[++w]=u;
	for(l=1,r=w;l<r;){
		s=ss=0;m=r-1;
		for(int i=l;i<=r;++i)s+=qsz[st[i]];
		for(int i=l;i<r;++i)if(ss+=qsz[st[i]],ss>=s/2){m=i;break;}
		printf("%d %d %d\n",lf[e[st[m]][0]],lf[e[st[m]][1]],i);fflush(stdout);
		static char c[9];scanf("%s",c);
		if(*c=='X')r=m;else if(*c=='Y')return solve(e[st[m]][1]);else l=m+1;
	}
	ins(st[l]);
}
int main(){
	scanf("%d",&n);
	fa[1]=fa[2]=rt=n+1;
	for(i=3;i<=n;++i){
		for(j=0;j<N;++j)e[j].clear();
		for(j=1;j<=n+i-2;++j)if(fa[j])e[fa[j]].push_back(j);
		for(;fa[rt];rt=fa[rt]);dfs(rt);solve(rt);
	}
	for(;fa[rt];rt=fa[rt]);
	fa[rt]=-1;
	puts("-1");for(i=1;i<n*2;++i)printf("%d ",fa[i]);puts("");fflush(stdout);
}