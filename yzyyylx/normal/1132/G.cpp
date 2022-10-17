#include<bits/stdc++.h>
#define N 1001000
using namespace std;

int n,m,tt,num[N],L[N];
struct Node
{
    int ls,rs,mx,sum;
}node[N<<1];

inline void up(int now)
{
    int L=node[now].ls,R=node[now].rs;
    node[now].mx=max(node[L].mx,node[R].mx)+node[now].sum;
}

void build(int now,int l,int r)
{
    if(l==r) return;
    int mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
}

void add(int now,int l,int r,int u,int v,int w)
{
    if(u<=l&&r<=v)
    {
	node[now].mx+=w;
	node[now].sum+=w;
	return;
    }
    int mid=((l+r)>>1);
    if(u<=mid) add(node[now].ls,l,mid,u,v,w);
    if(mid<v) add(node[now].rs,mid+1,r,u,v,w);
    up(now);
}

int ask(int now,int l,int r,int u,int v)
{
    if(u<=l&&r<=v) return node[now].mx;
    int res=0,mid=((l+r)>>1);
    if(u<=mid) res=max(res,ask(node[now].ls,l,mid,u,v));
    if(mid<v) res=max(res,ask(node[now].rs,mid+1,r,u,v));
    return res+node[now].sum;
}

int main()
{
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    num[0]=N;
    for(i=1;i<=n;i++)
    {
	L[i]=i-1;
	for(;num[i]>num[L[i]];L[i]=L[L[i]]);
    }
    build(tt=1,1,n);
    for(i=1;i<m;i++) add(1,1,n,L[i]+1,i,1);
    for(i=1,j=m;j<=n;i++,j++)
    {
	add(1,1,n,L[j]+1,j,1);
	printf("%d ",ask(1,1,n,i,j));
    }
}