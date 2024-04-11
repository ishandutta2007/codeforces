#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll g=-1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll szam;
        cin>>szam;
        if(g<0) g=szam;
        else g=__gcd(g, szam);
    }
    ll ans=1;
    for(ll i=2; i<=1000007; i++)
    {
        if(g%i==0)
        {
            ll cnt=0;
            while(g%i==0)
            {
                g/=i;
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(g>1) cout<<2*ans<<endl;
    else cout<<ans<<endl;
    return 0;
}