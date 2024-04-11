#include<bits/stdc++.h>
#define ll long long
#define N 200100
using namespace std;

int n,m,tt,num[N],rt[N];
struct Node
{
    int ls,rs,sum;
}node[N*40];

void build(int now,int l,int r)
{
    if(l==r) return;
    int mid=((l+r)>>1);
    node[now].ls=++tt;
    build(tt,l,mid);
    node[now].rs=++tt;
    build(tt,mid+1,r);
}

void add(int now,int l,int r,int u)
{
    node[now].sum++;
    if(l==r) return;
    int mid=((l+r)>>1);
    if(u<=mid)
    {
	node[++tt]=node[node[now].ls];
	node[now].ls=tt;
	add(node[now].ls,l,mid,u);
    }
    else
    {
	node[++tt]=node[node[now].rs];
	node[now].rs=tt;
	add(node[now].rs,mid+1,r,u);
    }
}

ll ask(int u,int v,int l,int r,int p,int q)
{
    if(p>q) return 0;
    if(p<=l&&r<=q) return node[v].sum-node[u].sum;
    int res=0,mid=((l+r)>>1);
    if(p<=mid) res+=ask(node[u].ls,node[v].ls,l,mid,p,q);
    if(mid<q) res+=ask(node[u].rs,node[v].rs,mid+1,r,p,q);
    return res;
}

int main()
{
    int i,j,a,b,c,d,t;
    cin>>n>>m;
    build(rt[0]=tt=1,1,n);
    for(i=1;i<=n;i++) scanf("%d",&t),num[t]=i;
    for(i=1;i<=n;i++)
    {
	rt[i]=++tt;
	node[tt]=node[rt[i-1]];
	add(tt,1,n,num[i]);
    }
    while(m--)
    {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	ll A,B,C,D,E,F,G,H,I;
	A=ask(rt[0],rt[b-1],1,n,1,a-1);
	B=ask(rt[b-1],rt[d],1,n,1,a-1);
	C=ask(rt[d],rt[n],1,n,1,a-1);
	D=ask(rt[0],rt[b-1],1,n,a,c);
	E=ask(rt[b-1],rt[d],1,n,a,c);
	F=ask(rt[d],rt[n],1,n,a,c);
	G=ask(rt[0],rt[b-1],1,n,c+1,n);
	H=ask(rt[b-1],rt[d],1,n,c+1,n);
	I=ask(rt[d],rt[n],1,n,c+1,n);
//	cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<" "<<F<<" "<<G<<" "<<H<<" "<<I<<endl;
	printf("%lld\n",A*(E+F+H+I)+B*(D+E+F+G+H+I)+C*(D+E+G+H)+D*(E+F+H+I)+E*(F+G+H+I)+F*(G+H)+E*(E-1)/2);
    }
}