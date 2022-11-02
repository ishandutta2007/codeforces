#include <bits/stdc++.h>
using namespace std;
long long n;
const long long MOD=1e9+7;
long long alatt[1009][1009];
int main()
{
    for(int i=0; i<=1005; i++)
    {
        alatt[i][0]=1;
        alatt[i][i]=1;
    }
    for(int i=1; i<=1005; i++)
    {
        for(int j=1; j<i; j++)
        {
            alatt[i][j]=alatt[i-1][j]+alatt[i-1][j-1];
            alatt[i][j]%=MOD;
        }
    }
    //cout<<"*";
    cin>>n;
    long long ossz=0;
    long long ans=1;
    for(int i=1; i<=n; i++)
    {
        long long g;
        cin>>g;
        ossz+=g;
        ans*=alatt[ossz-1][g-1];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}