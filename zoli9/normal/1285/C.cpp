#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll X;
    cin>>X;
    ll ans;
    for(ll i=1; i*i<=X; i++)
    {
        if(X%i==0)
        {
            ll j=X/i;
            if(__gcd(i, j)==1)
            {
                ans=i;
            }
        }
    }
    cout<<ans<<" "<<X/ans<<endl;
    return 0;
}