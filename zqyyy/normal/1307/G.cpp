#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=57,inf=0x3f3f3f3f;
struct Edge{
	int to,nxt,fl,w;
}e[(N*N)<<1];
int s_e,head[N];
inline void add_e(int from,int to,int fl,int w){
	e[++s_e].to=to,e[s_e].fl=fl,e[s_e].w=w;
	e[s_e].nxt=head[from],head[from]=s_e;
}
int n,m,s,t,dis[N],pd[N],pe[N];
bool vis[N];
queue<int>q;
inline bool spfa(){
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	vis[s]=1,q.push(s),dis[s]=0;
	while(!q.empty()){
		int x=q.front();q.pop(),vis[x]=0;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to,w=e[i].w;
			if(dis[y]>dis[x]+w && e[i].fl){
				dis[y]=dis[x]+w,pd[y]=x,pe[y]=i;
				if(!vis[y])vis[y]=1,q.push(y);
			}
		}
	}
	return dis[t]^inf;
}
vector<pii>a;
inline void EK(){
	int flow=0,cost=0;
	while(spfa()){
		int fl=inf,co=0,x=t;
		for(int i=pe[x];x^s;x=pd[x],i=pe[x])fl=min(fl,e[i].fl);
		x=t;
		for(int i=pe[x];x^s;x=pd[x],i=pe[x])e[i].fl-=fl,e[i^1].fl+=fl,co+=fl*e[i].w;
		flow+=fl,cost+=co;
		a.push_back(pii(flow,cost));
	}
}
int main(){
	n=read(),m=read(),s_e=1;
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		add_e(x,y,1,w),add_e(y,x,0,-w);
	}
	s=1,t=n,EK();
	int Q=read();
	while(Q--){
		int x=read();double ans=inf;
		for(auto i:a)ans=min(ans,1.0*(x+i.se)/i.fi);
		printf("%.10lf\n",ans);
	}
	return 0;
}