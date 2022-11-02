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

ll a[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        ll last=a[0];
        ll u=0;
        for(int i=1; i<n; i++)
        {
            ll nxt=max(a[i], last);
            u=max(u, nxt-a[i]);
            last=nxt;
        }
        ll ans=0;
        while(u>0)
        {
            ans++;
            u/=2;
        }
        cout<<ans<<'\n';
    }

    return 0;
}