#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int n,a[N],r1,r2,r3,d;

int f[N][2];

void cmin(int &a,int b)
{
    a=min(a,b);
}

signed main()
{
    scanf("%lld",&n);
    scanf("%lld%lld%lld",&r1,&r2,&r3);
    scanf("%lld",&d);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            f[i][j]=2e16;
    f[1][0]=r1*a[1]+r3;
    f[1][1]=min(r1*a[1]+r1,r2);
    for(int i=2;i<=n;i++)
    {
        cmin(f[i][0],f[i-1][0]+d+a[i]*r1+r3);
        cmin(f[i][0],f[i-1][0]+d+r2+d+d+r1);
        cmin(f[i][0],f[i-1][1]+d+r1*a[i]+r1+d+r1+d+r1);
        cmin(f[i][0],f[i-1][1]+d+r2+d+r1+d+r1);
        cmin(f[i][0],f[i-1][1]+d+r1*a[i]+r3+d+r1+d);
        cmin(f[i][1],f[i-1][1]+d+r2+d+r1+d);
        cmin(f[i][1],f[i-1][1]+d+r1*a[i]+r1+d+r1+d);
        cmin(f[i][1],f[i-1][0]+d+min(a[i]*r1+r1,r2));
    }
    printf("%lld\n",min(f[n][0],f[n-1][1]+d+a[n]*r1+r3+d+r1));
}