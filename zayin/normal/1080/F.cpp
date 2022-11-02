#include<bits/stdc++.h>
#define ls(k)   T[k].ls
#define rs(k)   T[k].rs
#define pos(k)  T[k].pos
#define maxh 18
#define maxn 300050
using namespace std;

int sz,root[maxn];
struct node {
    int ls,rs,pos;
}   T[maxn*maxh];

struct line {
    int l,r,p;
    bool operator < (const line& L) const   {
        return r<L.r;
    }
}   L[maxn];

int n,m,q;

void change(int &k,int l,int r,int p,int x)
{
    T[++sz]=T[k],k=sz;
    if (l==r)
        pos(k)=max(pos(k),x);
    else
    {
        int mid=(l+r)>>1;
        if (p<=mid)
            change(ls(k),l,mid,p,x);
        else
            change(rs(k),mid+1,r,p,x);
        pos(k)=min(pos(ls(k)),pos(rs(k)));
    }
}

void init()
{
    scanf("%d%d%d",&n,&q,&m);
    for (int k=1;k<=m;++k)
        scanf("%d%d%d",&L[k].l,&L[k].r,&L[k].p);
    sort(L+1,L+m+1);
    for (int k=1;k<=m;++k)
        change(root[k]=root[k-1],1,n,L[k].p,L[k].l);
}

int getroot(int p)
{
    if (L[1].r>p)   return 0;
    int l=1,r=m;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if (L[mid].r<=p)
            l=mid;
        else
            r=mid-1;
    }
    return l;
}

int query(int k,int l,int r,int a,int b)
{
    if (a>r||l>b)   return 1<<30;
    if (a<=l&&r<=b) return pos(k);
    int mid=(l+r)>>1;
    return min(query(ls(k),l,mid,a,b),query(rs(k),mid+1,r,a,b));
}

void solve()
{
    while (q--)
    {
        int a,b,x,y;
        scanf("%d%d%d%d",&a,&b,&x,&y);
        int k=getroot(y);
        if (!k||query(root[k],1,n,a,b)<x)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
}

int main()
{
    init();
    solve();
    return 0;
}