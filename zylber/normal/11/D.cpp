#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

long long dp[(1<<20)][20];

int ady[20][20];

int main()
{
#ifdef YOACM
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    memset(ady,0,sizeof(ady));
    memset(dp,0,sizeof(dp));
    long long ans=0;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ady[a][b]=1;
        ady[b][a]=1;
    }
    for(int l=0; l<n; l++)
    {
    memset(dp,0,sizeof(dp));
    for(long long i=1; i<n; i++)
    {
        dp[(1LL<<i)][l]=1;
    }
    
    for(long long i=(1LL<<l); i<(1LL<<(l+1)); i++)
    for(long long j=0; j<l; j++)
    for(long long k=0; k<=l; k++)
    if((i&(1LL<<j))==0 && (i&(1LL<<k))!=0 && ady[j][k])
    {
        dp[i|(1LL<<j)][j]+=dp[i][k];
    }
    
    for(long long i=(1LL<<l); i<(1LL<<(l+1)); i++)
    for(long long j=0; j<=l; j++)
    {
        long long r=i, d=0;
        while(r>0)
        {
            d+=r%2;
            r/=2;
        }
        if(d>2 && ady[l][j])
        {
            //cout << i << " " << j << " " << dp[i][j] << endl;
            ans+=dp[i][j];
        }
    }
    }
    cout << ans/2 << endl;
}