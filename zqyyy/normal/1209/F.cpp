#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+7,mod=1e9+7;
struct Edge{
	int to,nxt,w;
}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]=(Edge){y,head[x],w},head[x]=s_e;
}
inline int ws(int x){int res=0;while(x)x/=10,res++;return res;}
int n,m,tot,d[N],dis[N*6];
bool vis[N*6];
vector<pii>G[N*6];
priority_queue<pii>q;
void dfs(vector<int>u,int D){
	vector<int>b[10];
	for(auto x:u){
		if(vis[x])continue;vis[x]=1,dis[x]=D;
		for(auto y:G[x])
			if(!vis[y.fi])b[y.se].push_back(y.fi);
	}
	for(int i=0;i<=9;i++)
		if(!b[i].empty())dfs(b[i],(10ll*D+i)%mod);
}
int main(){
	tot=n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		add_e(x,y,i),add_e(y,x,i);
	}
	for(int i=2;i<=n;i++)d[i]=1e9;
	q.push(pii(0,1));
	while(!q.empty()){
		int x=q.top().se;q.pop();
		if(vis[x])continue;vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to,w=ws(e[i].w);
			if(d[y]>d[x]+w)d[y]=d[x]+w,q.push(pii(-d[y],y));
		}
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int x=1;x<=n;x++)
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to,w=ws(e[i].w);
			if(d[y]==d[x]+w){
				vector<int>a(0);int X=e[i].w;
				while(X)a.push_back(X%10),X/=10;
				int j=a.size()-1,lst=x;
				while(j)G[lst].push_back(pii(++tot,a[j--])),lst=tot;
				G[lst].push_back(pii(y,a[j]));
			}
		}
	dfs(vector<int>{1},0);
	for(int i=2;i<=n;i++)printf("%d\n",dis[i]);
	return 0;
}