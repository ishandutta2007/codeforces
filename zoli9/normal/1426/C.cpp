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
        ll n;
        cin>>n;
        ll ans=n-1;
        vll pos={sqrt(n), sqrt(n)+1};
        for(ll i: pos)
        {
            ll cur=n/i;
            if(n%i!=0) cur++;
            ans=min(ans, i+cur-2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}