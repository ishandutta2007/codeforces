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
      ll x, y, k;
        cin>>x>>y>>k;
        ll goal=k+k*y;
        goal--;
        x--;
        ll ans=k;
        if(goal%x==0) ans+=(goal/x);
        else ans+=(goal/x+1);
        cout<<ans<<'\n';
    }
    return 0;
}