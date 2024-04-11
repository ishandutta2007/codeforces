#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
#define mk make_pair
#define fi first
#define se second
const int N=3e5+7;
struct Edge{
	int to,nxt;
}e[N<<1];
int s_e=1,head[N];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e;
}
int n,m,X,d[N],fa[N],id[N];
ll sum,a[N];
int l,r,ans[N];
bool vis[N];
void dfs(int x){
	d[x]=1,vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;if(vis[y])continue;
		fa[y]=x,id[y]=i>>1,d[x]++,dfs(y);
	}
}
queue<int>q;
int main(){
	n=read(),m=read(),X=read();
	for(int i=1;i<=n;i++)sum+=a[i]=read();
	if(sum<1ll*(n-1)*X)puts("NO"),exit(0);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y),add_e(y,x);
	}
	dfs(1),r=n-1;
	for(int i=2;i<=n;i++)if(d[i]==1)q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(a[x]+a[fa[x]]>=X)a[fa[x]]+=a[x]-X,ans[++l]=id[x];
		else ans[r--]=id[x];
		if(--d[fa[x]]==1 && fa[x]!=1)q.push(fa[x]);
	}
	puts("YES");
	for(int i=1;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}