#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=111;

int T,n,a[N],b[N];

int f[N][N*N];

void cmin(int &a,int b)
{
    a=(a<b?a:b);
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%lld",&b[i]);
        for(int i=1;i<=n;i++)
            for(int j=0;j<=100*n;j++)
                f[i][j]=1e18;
        int s=0,sa=0;
        for(int i=0;i<n;i++)
        {
            s+=a[i]+b[i];
            for(int j=0;j<=100*i;j++)
            {
                cmin(f[i+1][j+a[i+1]],f[i][j]+a[i+1]*a[i+1]*(n-1)+b[i+1]*b[i+1]*(n-1)+2*j*a[i+1]+(s-j)*b[i+1]*2);
                cmin(f[i+1][j+b[i+1]],f[i][j]+a[i+1]*a[i+1]*(n-1)+b[i+1]*b[i+1]*(n-1)+2*j*b[i+1]+(s-j)*a[i+1]*2);
            }
        }
        printf("%lld\n",*min_element(f[n],f[n]+n*100+1));
    }
}