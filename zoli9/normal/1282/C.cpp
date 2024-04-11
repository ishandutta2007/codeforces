#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int test;
int n;
ll T;
ll a, b;

ll pl(ll ptime, ll adb, ll bdb)
{
    //cout<<ptime<<" "<<adb<<" : "<<bdb<<endl;
    ll ret=0;
    if(ptime<=0) return 0;
    ll c=ptime/a;
    ret=min(c, adb);
    ptime-=(ret*a);
    c=ptime/b;
    ret+=min(c, bdb);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>T>>a>>b;
        ll adb=0;
        ll bdb=0;
        vector<pair<ll, int> > v(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i].S;
            if(v[i].S==0) adb++;
            else bdb++;
        }
        for(int i=0; i<n; i++)
        {
            cin>>v[i].F;
        }
        sort(v.begin(), v.end());
        ll ans=0;
        ll TL=0;
        for(int i=0; i<n; i++)
        {
            if(v[i].F>0 && v[i].F-1-TL>=0)
            {
                ans=max(ans, i+pl(v[i].F-1-TL, adb, bdb));
            }
            if(v[i].S==0)
            {
                adb--;
                TL+=a;
            }
            else
            {
                bdb--;
                TL+=b;
            }
        }
        if(TL<=T) ans=n;
        cout<<ans<<endl;
    }

    return 0;
}