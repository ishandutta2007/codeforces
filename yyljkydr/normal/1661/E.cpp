#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

struct Data{
    int sum;
    int lf[3],rf[3];
};

int fa[12];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int id[12],cc;

int gid(int x)
{
    if(!id[x])
        id[x]=++cc;
    return id[x];
}

Data operator +(const Data &a,const Data &b)
{
    Data ret;
    ret.sum=a.sum+b.sum;
    for(int i=0;i<12;i++)
        fa[i]=i,id[i]=0;
    cc=0;
    for(int i=0;i<3;i++)
    {
        if(a.rf[i]==-1||b.lf[i]==-1)
            continue;
        int fu=find(a.rf[i]),fv=find(b.lf[i]+6);
        if(fu==fv)
            continue;
        fa[fu]=fv;
        ret.sum--;
    }
    for(int i=0;i<3;i++)
    {
        if(a.lf[i]==-1)
        {
            ret.lf[i]=-1;
            continue;
        }
        ret.lf[i]=gid(find(a.lf[i]))-1;
    }
    for(int i=0;i<3;i++)
    {
        if(b.rf[i]==-1)
        {
            ret.rf[i]=-1;
            continue;
        }
        ret.rf[i]=gid(find(b.rf[i]+6))-1;
    }
    return ret;
}

struct T{
    int l,r,ls,rs;
    Data v;
}t[N*2+1];

void update(int x)
{
    t[x].v=t[t[x].ls].v+t[t[x].rs].v;
}

int cnt;

char a[3][N];

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
    {
        int p=0;
        for(int i=0;i<3;i++)
        {
            if(a[i][l]=='0')
            {
                t[x].v.lf[i]=t[x].v.rf[i]=-1;
                continue;
            }
            t[x].v.lf[i]=t[x].v.rf[i]=(i>0&&t[x].v.lf[i-1]!=-1?p-1:p++);
        }
        t[x].v.sum=p;
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

Data qry(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].v;
    int mid=(t[x].l+t[x].r)>>1;
    if(r<=mid)
        return qry(t[x].ls,l,r);
    else if(l>mid)
        return qry(t[x].rs,l,r);
    else
        return qry(t[x].ls,l,r)+qry(t[x].rs,l,r);
}

int n,q;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        scanf("%s",a[i]+1);
    build(1,n);
    scanf("%d",&q);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",qry(1,l,r).sum);
    }
}   
/*
4
1101
0110
1101
1
1 4
*/