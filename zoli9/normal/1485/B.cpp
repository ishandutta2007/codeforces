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
    int n, q, k;
    cin>>n>>q>>k;
    vi a(n+2);
    vll dp(n+2, 0);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1];
        if(i>1 && i<n)
        {
            dp[i]+=(a[i+1]-a[i-1]-2);
        }
    }

    while(q--)
    {
        int x, y;
        cin>>x>>y;
        ll ans=0;
        if(x==y)
        {
            cout<<k-1<<'\n';
            continue;
        }
        ans=a[x+1]-2;
        ans+=k-a[y-1]-1;
        //cout<<ans<<endl;
        ans+=dp[y-1];
        //cout<<ans<<endl;
        ans-=dp[x];
        cout<<ans<<'\n';
    }
    return 0;
}