#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e5+1e3+7;

int T,n,m;

int a[N];

struct R{
    int l,r;
    bool ban;
}b[N],c[N];

bool cmpr(const R &a,const R &b)
{
    return a.l<b.l||(a.l==b.l&&a.r>b.r);
}

int st[N],top;

struct BIT{
    int c[N];

    void add(int x,int v)
    {

    }

    int qry(int x)
    {

    }
};

int f[N];

int g(int a,int b)
{
    return 2*(a+b)-max(a,b);
}

int pl[N];

int pre[N][2];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=m;i++)
            scanf("%lld%lld",&b[i].l,&b[i].r),b[i].ban=0;
        sort(b+1,b+m+1,cmpr);
        top=0;
        for(int i=1;i<=m;i++)
        {
            while(top&&b[i].r<=b[st[top]].r)
                b[st[top--]].ban=1;
            st[++top]=i;
        }
        for(int i=1;i<=m;i++)
        {
            int p=lower_bound(a+1,a+n+1,b[i].l)-a;
            if(p<=n&&a[p]<=b[i].r)
                b[i].ban=1;
        }
        int cm=0;
        for(int i=1;i<=m;i++)
            if(!b[i].ban)
                c[++cm]=b[i];
        for(int i=1;i<=n;i++)
            c[++cm]={a[i],a[i],0};
        m=cm;
        sort(c+1,c+m+1,cmpr);
        fill(f+1,f+m+1,1e18);
        int k=0;
        pre[0][0]=-c[1].r;
        pre[0][1]=-c[1].r*2;
        for(int i=1;i<=m;i++)
        {
            pl[i]=upper_bound(a+1,a+n+1,c[i].r)-a-1;
            if(!pl[i])
            {
                f[i]=1e18;
                pre[i][0]=min(pre[i-1][0],f[i]-c[i+1].r);
                pre[i][1]=min(pre[i-1][1],f[i]-c[i+1].r*2);
                continue;
            }
            while(k+1<i&&c[k+2].r<=a[pl[i]])
                k++;
            // for(int j=0;j<=k;j++)
            //     f[i]=min(f[i],f[j]+g(a[pl[i]]-c[j+1].r,c[i].l-a[pl[i]]));
            f[i]=min(pre[k][0]+a[pl[i]]+2*(c[i].l-a[pl[i]]),pre[k][1]+a[pl[i]]*2+(c[i].l-a[pl[i]]));
            pre[i][0]=min(pre[i-1][0],f[i]-c[i+1].r);
            pre[i][1]=min(pre[i-1][1],f[i]-c[i+1].r*2);
        }
        printf("%lld\n",f[m]);
    }
}
/*
f[i] = f[j] + 
[  j  ]  [    ]  [     ] . [  i  ]
*/