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
    int test;
    cin>>test;
    while(test--)
    {
        ll n, x;
        cin>>n>>x;
        vll v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        ll ans=0;
        ll sum=0;
        for(ll i=0; i<n; i++)
        {
            sum+=v[i];
            if(sum>=(i+1)*x) ans=i+1;
        }
        cout<<ans<<'\n';
    }

    return 0;
}