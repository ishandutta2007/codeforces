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
        vll db(32, 0);
        for(int i=1; i<=n; i++)
        {
            ll x;
            cin>>x;
            ll cnt=0;
            while(x>0)
            {
                x/=2;
                cnt++;
            }
            db[cnt]++;
        }
        ll ans=0;
        for(int i=0; i<db.size(); i++)
        {
            ll pl=(db[i]*(db[i]-1))/2;
            ans+=(pl);
        }
        cout<<ans<<'\n';
    }
    return 0;
}