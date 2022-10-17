#include<bits/stdc++.h>
using namespace std;

const int N=1111;

int n,vis[N];

double d[N],sm[N],r[N],a[N][N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lf",&a[i][j]),a[i][j]/=100; 
    for(int i=1;i<n;i++)
        d[i]=1e18;
    d[0]=1e18;
    for(int i=1;i<=n;i++)
    {
        int p=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&d[j]<d[p])
                p=j;
        vis[p]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j])
            {
                sm[j]+=(1.0-r[j])*a[j][p]*(d[p]+1);
                r[j]+=(1.0-r[j])*a[j][p];
                d[j]=min(d[j],(sm[j]+(1-r[j]))/r[j]);
                //d[i]=(sm) + (1-r)*(d[i]+1)
            }
    }
    printf("%.10lf\n",d[1]);
}