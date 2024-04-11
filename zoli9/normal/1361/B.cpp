#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n, p;
vi v;
ll MOD=1000000007;
vll pows(23);

/*ll modpow(ll base, ll x)
{
    ll res=1;
    while(x>0)
    {
        if(x%2)
        {
            res=(res*base)%MOD;
        }
        base=(base*base)%MOD;
        x/=2;
    }
    return res;
}*/

ll modpow2(ll y)
{
    ll res=1;
    int cnt=0;
    while(y>0)
    {
        if(y%2)
        {
            res=(res*pows[cnt])%MOD;
        }
        y/=2;
        cnt++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>p;
        v.resize(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }
        if(p==1)
        {
            cout<<(n%2)<<'\n';
            continue;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        map<int, int> db;
        bool exists1=false;
        int val1=0;
        for(int w: v)
        {
            if(!exists1)
            {
                exists1=true;
                val1=w;
                continue;
            }
            db[w]++;
            int cnt=w;
            while(db[cnt]==p)
            {
                db[cnt]=0;
                cnt++;
                db[cnt]++;
            }
            if(db[val1]==1)
            {
                db[val1]=0;
                exists1=false;
            }
        }
        if(!exists1)
        {
            cout<<0<<'\n';
            continue;
        }

        pows[0]=p;
        for(int i=1; i<23; i++)
        {
            pows[i]=(pows[i-1]*pows[i-1])%MOD;
        }
        ll ans=modpow2(val1);
        for(auto it=db.begin(); it!=db.end(); it++)
        {
            int i1=(*it).first;
            int i2=(*it).second;
            if(i2==0) continue;
            ll su=modpow2(i1);
            su=(su*i2)%MOD;
            ans=(ans+MOD-su)%MOD;
        }
        cout<<ans<<'\n';
    }

    return 0;
}