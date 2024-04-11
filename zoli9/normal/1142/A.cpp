#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a, b;
long long res(long long x)
{
    long long ans=n*k;
    ans/=(__gcd(n*k, x));
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cin>>a>>b;
    long long maxi=1;
    long long mini=n*k;
    for(long long masodik=b; masodik<n*k; masodik+=k)
    {
        long long d=(a-masodik+n*k)%(n*k);
        if(d==0) d=n*k;
        long long r=res(d);
        maxi=max(maxi, r);
        mini=min(mini, r);
    }
    for(long long masodik=n*k-b; masodik>=0; masodik-=k)
    {
        long long d=(a-masodik+n*k)%(n*k);
        if(d==0) d=n*k;
        long long r=res(d);
        maxi=max(maxi, r);
        mini=min(mini, r);
    }
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}