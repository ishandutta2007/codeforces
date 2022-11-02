#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll MOD=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin>>n>>k;
    ll ans1=0;
    for(ll i=n; i>=n-k+1; i--) ans1+=i;
    ll last=-1;
    ll ans2=1;
    for(ll i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        if(x>n-k)
        {
            if(last==-1)
            {
                last=i;
                continue;
            }
            else
            {
                ans2=(ans2*(i-last))%MOD;
            }
            last=i;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}