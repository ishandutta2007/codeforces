#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int inf=4e6;
namespace MF{
#define N 607
#define M 500007
    struct Edge{int to,nxt,f;}e[M<<1];
    int s_e,head[N],cur[N];
    inline void add_e(int x,int y,int f){
	e[++s_e]={y,head[x],f},head[x]=s_e;
	e[++s_e]={x,head[y],0},head[y]=s_e;
    }
    int n,s,t,dep[N];
    inline void init(int _n,int _s,int _t){
	n=_n,s=_s,t=_t,s_e=1;
	for(int i=1;i<=n;i++)head[i]=0;
    }
    inline bool bfs(){
	for(int i=1;i<=n;i++)dep[i]=0,cur[i]=head[i];
	dep[s]=1;queue<int>q;q.push(s);
	while(!q.empty()){
	    int x=q.front();q.pop();
	    for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(e[i].f && !dep[y])dep[y]=dep[x]+1,q.push(y);
	    }
	}
	return dep[t];
    }
    int dfs(int x,int minx){
	if(x==t)return minx;int flow=0;
	for(int &i=cur[x];i;i=e[i].nxt){
	    int y=e[i].to;
	    if(dep[y]==dep[x]+1 && e[i].f){
		int fl=dfs(y,min(minx-flow,e[i].f));
		flow+=fl,e[i].f-=fl,e[i^1].f+=fl;
		if(flow==minx)break;
	    }
	}
	if(flow<minx)dep[x]=0;return flow;
    }
    inline int dinic(){
	int flow=0;
	while(bfs())flow+=dfs(s,0x3f3f3f3f);
	return flow;
    }
#undef N
#undef M
}using MF::dinic;using MF::init;using MF::add_e;
int n,s,t,ans;
int main(){
    n=read(),s=n+n+1,t=s+1,init(t,s,t);
    for(int i=1;i<=n;i++){
	int k=read();
	while(k--)add_e(i,read()+n,inf);
    }
    for(int i=1;i<=n;i++)add_e(i+n,t,inf);
    for(int i=1,v;i<=n;i++)v=-read(),ans+=v,add_e(s,i,inf+v);
    ans-=dinic()-inf*n;
    printf("%d\n",-ans);
    return 0;
}