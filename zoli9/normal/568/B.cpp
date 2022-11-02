#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long n;
long long ossz;
const long long MOD=1e9+7;
long long alatt[4009][4009];
long long d[4009][4009];
int main()
{
    for(int i=0; i<=4005; i++)
    {
        alatt[i][0]=1;
        alatt[i][i]=1;
    }
    for(int i=1; i<=4005; i++)
    {
        for(int j=1; j<i; j++)
        {
            alatt[i][j]=alatt[i-1][j]+alatt[i-1][j-1];
            alatt[i][j]%=MOD;
        }
    }
    cin>>n;
    ossz=0;
    /*ossz=1;
    for(int i=1; i<n; i++)
    {
        long long ak=alatt[n][i];
        ak*=i;
        ak%=MOD;
        ossz+=ak;
        ossz%=MOD;
    }
    cout<<ossz;*/
    d[1][1]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            d[i][j]=(d[i-1][j]*j+d[i-1][j-1])%MOD;
        }
    }
    for(int i=1; i<=n; i++)
    {
        ossz+=d[n][i]*i;
        ossz%=MOD;
    }
    cout<<ossz;
    return 0;
}