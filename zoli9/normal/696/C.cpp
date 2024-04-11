#include <bits/stdc++.h>
using namespace std;
long long MOD=1000000007;
long long mhat(long long a, long long b)
{
    long long ans=1;
    while(b>0)
    {
        if(b%2)
        {
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        a%=MOD;
        b/=2;
    }
    return ans;
}
long long x=2;
bool even=false;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        long long uj;
        cin>>uj;
        if(uj%2==0) even=true;
        x=mhat(x, uj);
    }
    if(x%2) x+=MOD;
    x/=2;
    long long y;
    if(even)
    {
        y=x+1;
    }
    else
    {
        y=x-1;
    }
    while(y%3) y+=MOD;
    y/=3;
    cout<<y<<"/"<<x<<endl;
    return 0;
}