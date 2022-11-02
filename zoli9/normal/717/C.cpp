#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> a;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        long long b;
        cin>>b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=(a[i]*a[n-i-1]);
        ans%=10007;
    }
    cout<<ans<<endl;
    return 0;
}