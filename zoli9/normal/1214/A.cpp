#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n;
ll d;
ll e;
ll ans=109;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d>>e;
    for(ll i=0; i*e<=n; i+=5)
    {
        ll x=n-i*e;
        ll y=x/d;
        x-=(y*d);
        ans=min(ans, x);
    }
    cout<<ans<<endl;


    return 0;
}