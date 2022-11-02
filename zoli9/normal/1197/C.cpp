#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
vector<ll> d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    ll x;
    cin>>x;
    for(int i=2; i<=n; i++)
    {
        ll y;
        cin>>y;
        d.push_back(y-x);
        x=y;
    }
    sort(d.begin(), d.end());
    ll ans=0;
    for(int i=0; i<n-k; i++)
    {
        ans+=d[i];
    }
    cout<<ans<<endl;



    return 0;
}