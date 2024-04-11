#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,l,r,n,a[N],s[N];

int tr[N*21][2],rt=0,tot;

void ins(int &x,int d,int v)
{
    if(x==-1)
    {
        x=++tot;
        tr[tot][0]=tr[tot][1]=-1;
    }
    if(d==-1)
        return;
    ins(tr[x][v>>d&1],d-1,v);
}

int qmx(int x,int d,int v)
{
    if(d==-1)
        return 0;
    return tr[x][(v>>d&1)^1]!=-1?(qmx(tr[x][(v>>d&1)^1],d-1,v)|(1<<d)):qmx(tr[x][v>>d&1],d-1,v);
}

int qmn(int x,int d,int v)
{
    if(d==-1)
        return 0;
    return tr[x][v>>d&1]!=-1?qmn(tr[x][v>>d&1],d-1,v):(qmn(tr[x][(v>>d&1)^1],d-1,v)|(1<<d));
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        tot=0;
        tr[rt][0]=tr[rt][1]=-1;
        n=r-l+1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),ins(rt,16,a[i]);
        for(int i=1;i<=n;i++)
        {
            if(qmx(rt,16,a[i]^l)==r&&qmn(rt,16,a[i]^l)==l)
            {
                printf("%d\n",a[i]^l);
                break;
            }
        }
    }
}