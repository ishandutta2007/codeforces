#include<bits/stdc++.h>
#define maxn 2005
#define modu 998244353
using namespace std;
typedef long long LL;

int n,a[maxn][maxn];

LL F[maxn]={1};

LL f[maxn]={1},g[maxn][maxn];

int T1[maxn],T2[maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            scanf("%d",a[i]+j);
    
    for (int i=1;i<=n;++i)
        F[i]=F[i-1]*i%modu;

    for (int i=2;i<=n;++i)
        f[i]=(i-1)*(f[i-1]+f[i-2])%modu;
    for (int i=0;i<=n;++i)
    {
        g[i][0]=F[i];
        for (int j=1;j<=i;++j)
            g[i][j]=(g[i][j-1]-g[i-1][j-1]+modu)%modu;
    }
}

LL pw(LL a,LL k)
{
    LL ans=1;
    for (;k;k>>=1)
    {
        if (k&1)
            ans=ans*a%modu;
        a=a*a%modu;
    }
    return ans;
}

int lowbit(int i)   {   return i&(-i);  }

void change(int T[],int i,int d)
{
    for (;i<=n;i+=lowbit(i))
        T[i]+=d;
}

int query(int T[],int i)
{
    if (i<=0)   return 0;
    int ans=0;
    for (;i;i-=lowbit(i))
        ans+=T[i];
    return ans;
}

void solve()
{
    // cout<<"f[n]:"<<f[n]<<endl;

    LL ans=0;
    for (int i=1;i<=n;++i)
    {
        LL t=pw(f[n],n-i),c=(i==1?0:n);

        for (int j=1;j<=n;++j)
            T1[j]=lowbit(j),T2[j]=(i==1?0:lowbit(j));

        for (int j=1;j<=n;++j)
        {
            int f=query(T1,a[i-1][j])-query(T1,a[i-1][j]-1);
            int p=query(T2,a[i][j]-1),q=query(T1,a[i][j]-1)-p;


            if (f)
            {
                if (a[i-1][j]<a[i][j])
                {
                    // cout<<"op 1"<<endl;
                    ans+=((p-1)*g[n-j][c-2]+q*g[n-j][c-1])%modu*t;
                } else
                {
                    // cout<<"op 2"<<endl;
                    ans+=(p*g[n-j][c-2]+q*g[n-j][c-1])%modu*t;
                }
                --c;
                change(T2,a[i-1][j],-1);

            } else
            {
                    // cout<<"op 3"<<endl;
                ans+=(p*g[n-j][c-1]+q*g[n-j][c])%modu*t;
            }
            if (query(T2,a[i][j])-query(T2,a[i][j]-1))
                --c,change(T2,a[i][j],-1);
            change(T1,a[i][j],-1);
            ans%=modu;
            // cout<<i<<" "<<j<<" : "<<f<<" "<<p<<" "<<q<<" "<<c<<" ~ "<<ans<<endl;

            // if (a[i][j]==a[i-1][j]) --c;
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}