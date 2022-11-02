#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n,m;
int a[maxn];

int stk[maxn],tp;

int N;
vector<int> G[maxn];
int T,L[maxn],R[maxn];

void dfs(int i) {
    L[i]=++T;
    for (int j:G[i])
        dfs(j);
    R[i]=T;
}

struct node {
    int tag,mx;
} Tree[maxn<<2];
#define tag(i) Tree[i].tag
#define mx(i) Tree[i].mx

void build(int k,int l,int r)   {
    tag(k)=mx(k)=-maxn;
    if (l==r)   return ;
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
}

void renew(int k,int d)   {
    tag(k)+=d,mx(k)+=d;
}

void godown(int k)  {
    renew(k<<1,tag(k));
    renew(k<<1|1,tag(k));
    tag(k)=0;
}

void update(int k)  {
    mx(k)=max(mx(k<<1),mx(k<<1|1));
}

void change(int k,int l,int r,int p,int x)  {
    if (l==r)
        mx(k)=x;
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (p<=mid)
            change(k<<1,l,mid,p,x);
        else
            change(k<<1|1,mid+1,r,p,x);
        update(k);
    }
}

void add(int k,int l,int r,int a,int b) {
    if (a<=l&&r<=b)
        renew(k,1);
    else    {
        godown(k);
        int mid=(l+r)>>1;
        if (a<=mid)
            add(k<<1,l,mid,a,b);
        if (b>mid)
            add(k<<1|1,mid+1,r,a,b);
        update(k);
    }
}

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)  
        scanf("%d",a+i);
    stk[tp=0]=n+1;
    for (int i=n;i;--i) {
        while (tp&&a[i]>=a[stk[tp]])    --tp;
        G[stk[tp]].push_back(i);
        stk[++tp]=i;
    }
    dfs(N=n+1);
    build(1,1,N);
    for (int i=1;i<=n;++i)  {
        change(1,1,N,L[i],0);
        add(1,1,N,L[i],R[i]);
        if (i<m)    continue;
        change(1,1,N,L[i-m],-maxn);
        printf("%d ",mx(1));
    }
    return 0;
}