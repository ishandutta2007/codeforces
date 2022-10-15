#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=8007,inf=1e9+7;
struct Edge{int to,nxt,f,w;}e[N<<5];
int s_e=1,head[N<<1];
inline void add_e(int from,int to,int f,int w){
	e[++s_e]=(Edge){to,head[from],f,w},head[from]=s_e;
	e[++s_e]=(Edge){from,head[to],0,-w},head[to]=s_e;
}
int s,t,dis[N<<1];
bool vis[N<<1];
inline bool spfa(){
	for(int i=1;i<=t;i++)dis[i]=inf;
	queue<int>q;q.push(s),dis[s]=0,vis[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop(),vis[x]=0;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to,w=e[i].w;
			if(dis[y]>dis[x]+w && e[i].f){
				dis[y]=dis[x]+w;
				if(!vis[y])vis[y]=1,q.push(y);
			}
		}
	}
	return dis[t]^inf;
}
int dfs(int x,int f){
	if(x==t || !f)return f;int ans=0;vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;if(vis[y])continue;
		if(dis[y]==dis[x]+e[i].w && e[i].f){
			int flow=dfs(y,min(e[i].f,f-ans));
			e[i].f-=flow,e[i^1].f+=flow,ans+=flow;
			if(ans==f)break;
		}
	}
	if(!ans)dis[x]=inf;return vis[x]=0,ans;
}
inline int dinic(){
	int cost=0;
	while(spfa())cost+=dis[t]*dfs(s,inf);
	return cost;
}
int n,nn,id[N],idx[N],a[N],b[N];
ll c[N];
inline ll calc(int i,int x){return 1ll*a[i]*x+b[i];}
inline bool check(int mid){
	ll mx=0;int tot=0;
	for(int i=1;i<=nn;i++){
		mx=max(mx,calc(id[i],mid));
		if(id[i]<=n)c[++tot]=mx;
	}
	sort(idx+1,idx+n+1,[&](int x,int y){return calc(x,mid)<calc(y,mid);});
	for(int i=n;i;i--)
		if(c[i]<calc(idx[i],mid))return 0;
	return 1;
}
int main(){
	n=read(),nn=n<<1;
	for(int i=1;i<=nn;i++)a[i]=read(),b[i]=read(),id[i]=i;
	for(int i=1;i<=n;i++)idx[i]=i+n;
	sort(id+1,id+nn+1,[&](int x,int y){return b[x]==b[y]?a[x]>a[y]:b[x]<b[y];});
	int l=0,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		check(mid)?r=mid-1:l=mid+1;
	}
	if(l>1e9)puts("-1"),exit(0);
	s=(n<<2)+1,t=s+1;
	for(int i=1;i<=nn;i++){
		int x=id[i],y=id[i-1];
		add_e(x,x+nn,1,0),add_e(x,x+nn,inf,1);
		if(x<=n)add_e(s,x,1,0);
		if(i^1){
			add_e(x,y,inf,0);
			if(b[x]==b[y])add_e(y,x,inf,0);
		}
	}
	sort(id+1,id+nn+1,[&](int x,int y){return calc(x,l)<calc(y,l);});
	for(int i=1;i<=nn;i++){
		int x=id[i],y=id[i-1];
		if(x>n)add_e(x+nn,t,1,0);
		if(i^1){
			add_e(x+nn,y+nn,inf,0);
			if(calc(x,l)==calc(y,l))add_e(y+nn,x+nn,inf,0);
		}
	}
	return cout<<l<<" "<<dinic()+n,0;
}