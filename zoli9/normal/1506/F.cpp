#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

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
        vector<pair<ll, ll>> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F;
        }
        for(int i=0; i<n; i++)
        {
            cin>>a[i].S;
        }
        sort(a.begin(), a.end());
        ll ans=0;
        pair<ll, ll> cur={1, 1};
        for(int i=0; i<n; i++)
        {
            ll x=cur.F-cur.S;
            ll y=a[i].F-a[i].S;
            if(x==y)
            {
                if(x%2==0)
                {
                    ans+=(a[i].F-cur.F);
                }
            }
            if(x%2==1) x--;
            if(y%2==1) y--;
            ans+=((y-x)/2);
            cur=a[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}