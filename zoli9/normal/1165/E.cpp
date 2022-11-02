#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int test;
ll n;
ll MOD=998244353;
vector<ll> a, b, c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        c.push_back(a[i]*(i+1)*(n-i));
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    reverse(b.begin(), b.end());
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        c[i]%=MOD;
        b[i]%=MOD;
        ll plusz=(b[i]*c[i])%MOD;
        ans=(ans+plusz)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}