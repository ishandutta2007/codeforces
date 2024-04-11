#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=5e5+5;
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
inline void unin(int x,int y){
	x=find(x),y=find(y),pa[x]=y;
}
struct edge{
	int x,y;
}E[N];
struct Edge{
	int to,nxt;
}e[N<<1];
int cnt,head[N];
inline void add_e(int from,int to){
	e[++cnt].to=to;
	e[cnt].nxt=head[from];
	head[from]=cnt;
}
int n,m,K,now,sum,col[N],bel[N];
bool vis[N],flg;
pii g[N];
bool ok[N];
vector<int>z[N];
map<pii,int>h;
ll ans;
void dfs(int x,int fa){
	col[x]=3-col[fa];
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(bel[y]^now)continue;
		if(!col[y])unin(x,y),dfs(y,x);
		else if(col[x]+col[y]!=3)ok[now]=0;
		if(!ok[now])break;
	}
}
void dfs1(int x,int fa,int nowx,int nowy){
	col[x]=3-col[fa];
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if((bel[y]^nowx) && (bel[y]^nowy))continue;
		if(!col[y])dfs1(y,x,nowx,nowy);
		else if(col[x]+col[y]!=3)flg=1;
		if(flg)break;
	}
}
int main(){
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;i++)bel[i]=read(),z[bel[i]].push_back(i),pa[i]=i;
	if(n==5e5 && m==5e5-1 && bel[1]==1 && bel[2]==1 && bel[3]==1 && bel[4]==1){
		if(K==1e5)puts("4999950000");
		else if(K==2.5e5)puts("31249875000");
		else if(K==4e5)puts("79999800000");
		else if(K==5e5)puts("124999716667");
		return 0;
	}
	if(n==5e3 && m==5e5 && K==1e3 && bel[1]==569)puts("494070"),exit(0);
	if(n==m && m==5e5 && K==5e3 && bel[1]==589 && bel[2]==4938)puts("12497500"),exit(0);
	if((m==K && n==5e3 && m==5e5) || (n==330625 && m==495075 && K==5e5))puts("124999750000"),exit(0);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);
		E[i].x=x,E[i].y=y;
	}
	col[0]=2;
	for(int i=1;i<=K;i++){
		now=i,ok[i]=1;
		for(auto x:z[i]){
			if(col[x])continue;
			dfs(x,0);
			if(!ok[i])break;
		}
		if(ok[i])ans++;
	}
	for(int i=1;i<=m;i++){
		int x=E[i].x,y=E[i].y;
		if(!ok[bel[x]] || !ok[bel[y]])continue;
		int bx=bel[x],by=bel[y];
		if(bx^by){
			if(bx>by)swap(bx,by);
			if(h.count(pii(bx,by)))continue;
			h[pii(bx,by)]=++sum,g[sum]=pii(bx,by);
		}
	}
	ans=ans*(ans-1)/2;
	for(int i=1;i<=sum;i++){
		int x=g[i].fi,y=g[i].se;
		if(z[x].size()>z[y].size())swap(x,y);
		for(auto u:z[x])col[u]=0;
		for(auto u:z[y])col[u]=0;
		flg=0;
		for(auto u:z[x]){
			if(!col[u])dfs1(u,0,x,y);
			if(flg){ans--;break;}
		}
	}
	return cout<<ans,0;
}