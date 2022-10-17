#include<bits/stdc++.h>
using namespace std;

const int N=2001;

int n,a[N];

long long f[N][N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            f[l][r]=min(f[l+1][r],f[l][r-1])+a[r]-a[l];
        }
    }
    printf("%lld\n",f[1][n]);
}