#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;


int n, k;
ll prim[100009];
ll db[100009];
ll volt[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(ll i=2; i<=100000; i++)
    {
        if(prim[i]==0)
        {
            for(ll j=i; j<=100000; j+=i)
            {
                if(prim[j]==0) prim[j]=i;
            }
        }
    }
    ll ans=0;
    for(int u=1; u<=n; u++)
    {
        ll x;
        cin>>x;
        ll ez=1;
        ll kell=1;
        while(x>1)
        {
            ll p=prim[x];
            int db=0;
            while(x%p==0)
            {
                db++;
                x/=p;
            }
            db%=k;
            if(db>0)
            {
                for(int i=1; i<=db; i++)
                {
                    ez*=p;
                }
                for(int i=1; i<=k-db; i++)
                {
                    kell*=p;
                    kell=min(kell, 100001LL);
                }
            }
        }
        ans+=volt[kell];
        volt[ez]++;
    }
    cout<<ans<<endl;


    return 0;
}