#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n, k;
ll m;
vll v;
vll cnt;
vll t;

ll small[200009];
ll big[200009];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    t.push_back(v[0]);
    cnt.push_back(1);
    for(int i=1; i<n; i++)
    {
        if(v[i]==v[i-1])
        {
            cnt.back()++;
            if(cnt.back()>=k)
            {
                cout<<0<<endl;
                return 0;
            }
        }
        else
        {
            t.push_back(v[i]);
            cnt.push_back(1);
        }
    }
    if(k==1)
    {
        cout<<0<<endl;
        return 0;
    }
    ll ans=1e18;
    ll ccc=cnt[0];
    m=t.size();
    for(int i=1; i<m; i++)
    {
        small[i]=small[i-1]+(t[i]-t[i-1])*ccc;
        ccc+=cnt[i];
        if(ccc>=k)
        {
            ans=min(ans, small[i]-(ccc-k));
        }
    }
    ccc=cnt[m-1];
    for(int i=m-2; i>=0; i--)
    {
        big[i]=big[i+1]+(t[i+1]-t[i])*ccc;
        ccc+=cnt[i];
        if(ccc>=k)
        {
            ans=min(ans, big[i]-(ccc-k));
        }
    }
    for(int i=0; i<m; i++)
    {
        //cout<<"s "<<small[i]<<" b "<<big[i]<<endl;
        ans=min(ans, small[i]+big[i]-(n-k));
    }
    cout<<ans<<endl;
    return 0;
}