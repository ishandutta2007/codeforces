#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T;

int n,k;

int vis[N],p[N],ptot,mu[N],g[N],smu[N];

void pre(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            p[++ptot]=i,mu[i]=-1;
        for(int j=1;j<=ptot&&i*p[j]<=n;j++)
        {
            mu[i*p[j]]=-mu[i];
            vis[i*p[j]]=1;
            if(i%p[j]==0)
            {
                mu[i*p[j]]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        smu[i]=smu[i-1]+mu[i];
        for(int j=1,k;j<=i;j=k+1)
        {
            k=i/(i/j);
            g[i]+=(smu[k]-smu[j-1])*(i/j)*(i/j-1)/2;
        }
    }
}

int calc(int l,int r)
{
    if(l>r)
        return 1e18;
    int ret=0;
    // for(int i=l;i<=r;i++)
    //     for(int j=i+1;j<=r;j++)
    //         ret+=__gcd(i,j)>=l;
    // return ret;
    for(int i=l,j=l-1;i<=r;i=j+1)
    {
        j=r/(r/i);
        ret+=g[r/i]*(j-i+1);
    }
    return ret;
}

int f[21][N];

void solve(int k,int l,int r,int L,int R)
{
    if(L>R)
    {
        for(int i=l;i<=r;i++)
            f[k][i]=1e18;
        return;
    }
    if(l>r)
        return;
    int mid=(l+r)>>1;
    int bst=-1;
    int cc=calc(L+1,mid);
    for(int i=L;i<=R;i++)
    {
        if(i>=mid)
            break;
        //f[k-1][i]+calc(i+1,mid)
        int val=f[k-1][i]+cc;
        if(bst==-1||val<f[k][mid])
            bst=i,f[k][mid]=val;
        cc-=g[mid/(i+1)];
    }
    solve(k,l,mid-1,L,bst);
    solve(k,mid+1,r,bst,R);
}

signed main()
{
    scanf("%lld",&T);
    pre(100000);
    f[0][0]=0;
    for(int i=1;i<=1e5;i++)
        f[0][i]=1e18;
    for(int i=1;i<=20;i++)
        solve(i,i,100000,i-1,(100000)-1);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",k>20?n:f[k][n]+n);
    }
}