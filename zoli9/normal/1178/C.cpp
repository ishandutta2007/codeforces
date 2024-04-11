#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
ll MOD=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll ans=1;
    for(int i=1; i<=n+m; i++) ans=(ans*2)%MOD;
    cout<<ans<<endl;

    return 0;
}