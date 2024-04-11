#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=3e5+7,inf=1e9;
struct Edge{int to,nxt,w;}e[N<<6];
int s_e,head[N<<4];
inline void add_e(int x,int y,int w){
    e[++s_e]={y,head[x],w},head[x]=s_e;
}
int n,tot,a[N],b[N],num[N];
struct Segment_Tree{
    int t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
    void build(int p,int l,int r){
	if(l==r){t[p]=l+n+1;return;}
	int mid=(l+r)>>1;t[p]=++tot;
	build(ls,l,mid),build(rs,mid+1,r);
	add_e(t[p],t[ls],0),add_e(t[p],t[rs],0);
    }
    void modify(int p,int l,int r,int x,int y,int v){
	if(x<=l && r<=y)return add_e(v,t[p],1);
	int mid=(l+r)>>1;
	if(x<=mid)modify(ls,l,mid,x,y,v);
	if(y>mid)modify(rs,mid+1,r,x,y,v);
    }
}T;
int dis[N<<4],pre[N<<4];
bool vis[N<<4];
int hd,tl,q[N<<5];
inline void dijkstra(int s){
    for(int i=0;i<=tot;i++)dis[i]=inf;
    dis[s]=0,q[hd=tl=tot]=s;
    while(hd<=tl){
	int x=q[hd++];
	if(vis[x])continue;vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
	    int y=e[i].to,w=e[i].w;
	    if(dis[y]>dis[x]+w){
		dis[y]=dis[x]+w,pre[y]=x;
		if(w==1)q[++tl]=y;
		else q[--hd]=y;
	    }
	}
    }
}
inline void work(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),num[i]=++tot;
    tot=n*2+1,T.build(1,0,n);
    for(int i=1;i<=n;i++)T.modify(1,0,n,i-a[i],i,num[i]);
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=0;i<=n;i++)add_e(i+n+1,num[i+b[i]],0);
    dijkstra(n);
    if(dis[0]==inf){puts("-1");return;}
    printf("%d\n",dis[0]);
    vector<int>vec;int x=0;
    while(x!=n){
	if(n<x && x<=2*n+1)vec.push_back(x-n-1);
	x=pre[x];
    }
    reverse(vec.begin(),vec.end());
    for(int x:vec)printf("%d ",x);
}
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    int test=1;
    while(test--)work();
    return 0;
}