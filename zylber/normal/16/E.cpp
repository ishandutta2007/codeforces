#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double dp[(1<<20)];
double p[20][20];

int main()
{
#ifdef ACMTUYO
    freopen("test.in", "r", stdin);
#endif
    long long n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> p[i][j];
    
    
    memset(dp,0,sizeof(dp));
    dp[(1<<n)-1]=1;
    //double par=(n-1);
    
    for(long long k=(1LL<<n)-1; k>=0; k--)
    {
        double c=0;
        for(long long i=0; i<n; i++)    if(k&(1LL<<i)) c+=1;
        for(long long i=0; i<n; i++)    if(k&(1LL<<i))
        for(long long j=0; j<n; j++)    if(k&(1LL<<j))
        {
            dp[k-(1LL<<i)]+=p[j][i]*dp[k]/(c*(c-1)/2.0);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(i) cout << " ";
        printf("%.6f",dp[(1LL<<i)]);
    }
    cout << endl;
}