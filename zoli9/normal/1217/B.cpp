#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
ll x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>x;
        ll csokken=0;
        ll maxi=0;
        for(int i=1; i<=n; i++)
        {
            ll a, b;
            cin>>a>>b;
            maxi=max(maxi, a);
            csokken=max(csokken, a-b);
        }
        if(maxi<x && csokken==0) cout<<-1<<endl;
        else
        {
            if(x<=maxi) cout<<1<<endl;
            else
            {
                x-=maxi;
                ll ans=x/csokken;
                if(x%csokken>0) ans++;
                cout<<ans+1<<endl;
            }
        }
    }


    return 0;
}