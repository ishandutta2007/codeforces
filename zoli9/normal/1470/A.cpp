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
        int n, m;
        cin>>n>>m;
        vi a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            a[i]--;
        }
        sort(a.begin(), a.end());
        vll c(m);
        for(int i=0; i<m; i++)
        {
            cin>>c[i];
        }
        ll ans=0;
        int cnt=0;
        for(int i=n-1; i>=0; i--)
        {
            if(cnt<a[i])
            {
                ans+=c[cnt];
                cnt++;
            }
            else
            {
                ans+=c[a[i]];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}