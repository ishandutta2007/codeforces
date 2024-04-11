#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[100009];
long long b[100009];
long long ans=1;
long long MOD=1000000007;
long long kerek;
long long mennyi(long long x, long long y)
{
    long long ossz=(kerek-1)/x+1;
    long long rossz;
    if(y==0)
    {
        rossz=(kerek/10-1)/x+1;
    }
    else rossz=(kerek/10*(y+1)-1)/x+1-( (kerek/10*(y)-1)/x+1 );
    return ossz-rossz;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=(n/k); i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=(n/k); i++)
    {
        cin>>b[i];
    }
    kerek=1;
    for(int i=1; i<=k; i++)
    {
        kerek*=10;
    }
    for(int i=1; i<=(n/k); i++)
    {
        ans*=mennyi(a[i], b[i]);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}