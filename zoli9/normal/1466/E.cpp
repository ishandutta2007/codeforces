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

vector<int> d[500009];

ll MOD=1e9+7;

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
        vector<ll> s(60, 0);
        for(int i=1; i<=n; i++)
        {
            d[i].assign(60, 0);
            ll x;
            cin>>x;
            for(int j=0; j<60; j++)
            {
                d[i][j]=(x%2);
                s[j]+=(x%2);
                x/=2;
            }
        }
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            ll r1=0;
            ll r2=0;
            for(int j=0; j<60; j++)
            {
                if(d[i][j])
                {
                    r1=(r1+(n*((1LL<<j)%MOD)))%MOD;
                    r2=(r2+(s[j]*((1LL<<j)%MOD)))%MOD;
                }
                else
                {
                    r1=(r1+(s[j]*((1LL<<j)%MOD)))%MOD;
                }
            }
            ll cres=(r1*r2)%MOD;
            ans=(ans+cres)%MOD;
            //cout<<ans<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}