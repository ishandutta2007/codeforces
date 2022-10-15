#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int pa[N],sz[N],ans;
int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
inline void unin(int x,int y){
    x=find(x),y=find(y);
    if(x^y)pa[x]=y,ans=max(ans,sz[y]+=sz[x]);
}
struct Edge{int to,nxt,w;bool ok;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
    e[++s_e]={y,head[x],w,1},head[x]=s_e;
}
int n,rt,pd[N],pe[N];
ll diam;
void find_d(int x,int fa,ll dis){
    if(dis>diam)rt=x,diam=dis;
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;if(y==fa)continue;
	pd[y]=x,pe[y]=e[i].w,find_d(y,x,dis+e[i].w);
    }
}
int id[N];
ll dep[N];
void dfs(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;if(y==fa || !e[i].ok)continue;
	dep[y]=dep[x]+e[i].w,pd[y]=x,dfs(y,x);
    }
}
inline void work(ll L){
    for(int i=1;i<=n+1;i++)pa[i]=i,sz[i]=1;
    sz[n+1]=0,ans=1;
    for(int l=1,r=1;l<=n+(rt==n+1);l++){
	while(r<=n+(rt==n+1) && dep[id[l]]-dep[id[r]]<=L){
	    int x=id[r];
	    for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==pd[x] || !e[i].ok)continue;
		unin(y,x);
	    }
	    r++;
	}
	sz[find(id[l])]--;
    }
    printf("%d\n",ans);
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read(),w=read()<<1;
	add_e(x,y,w),add_e(y,x,w);
    }
    find_d(1,0,0),diam=0,find_d(rt,0,0);
    {
	int x=rt;ll d=0;
	while(1){
	    if((d+pe[x])*2>diam){
		if((d+pe[x])*2==diam)rt=x;
		else{
		    rt=n+1;
		    for(int i=head[x];i;i=e[i].nxt)
			if(e[i].to==pd[x]){e[i].ok=0;break;}
		    for(int i=head[pd[x]];i;i=e[i].nxt)
			if(e[i].to==x){e[i].ok=0;break;}
		    add_e(rt,x,diam/2-d),add_e(rt,pd[x],d+pe[x]-diam/2);
		}
		break;
	    }
	    d+=pe[x],x=pd[x];
	}
    }
    dfs(rt,0);
    for(int i=1;i<=n+1;i++)id[i]=i;
    sort(id+1,id+n+2,[](int x,int y){return dep[x]>dep[y];}),dep[n+1]=dep[id[n]];
    int Q=read();
    while(Q--)work(read()<<1);
    return 0;
}