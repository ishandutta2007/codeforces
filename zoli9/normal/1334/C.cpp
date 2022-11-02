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
        ll n;
        cin>>n;
        vll v(n);
        vll b(n);
        ll sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>v[i]>>b[i];
            sum+=v[i];
        }
        ll mini=b[0];
        for(int i=0; i<n; i++)
        {
            ll cc=min(b[i], v[(i+1)%n]);
            sum-=cc;
            mini=min(mini, cc);
        }
        cout<<sum+mini<<'\n';
    }

    return 0;
}